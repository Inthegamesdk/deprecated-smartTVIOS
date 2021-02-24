//
//  PlayerViewController.swift
//  InthegameTVExample
//
//  Created by Tiago Lira Pereira on 01/02/2021.
//

import UIKit
import AVFoundation
import AVKit
import Inthegametv

let videoURL = "https://api-dev.inthegame.io/uploads/videos/streamers/a64706dd0f42356e93d299075940c456.857ecbb7a131f9bb4940a6b8ad5ec70e.mp4"
let broadcaster = "orlandofcchannel"
let channelID = "ORLvsNYCFC"

class PlayerViewController: UIViewController {

    @IBOutlet weak var containerView: UIView!
    @IBOutlet weak var controlsView: ControlsView!
    
    public var overlayView: ITGOverlayView?
    var playerLayer: AVPlayerLayer?
    var playerView: AVPlayerView?
    var timeObserverToken: Any?

    weak var customPreferredFocusView: UIView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        startVideo()
        setupOverlay()
        configureMenuButtonHandler()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        if isMovingFromParent {
            if let timeObserverToken = timeObserverToken {
                playerLayer?.player?.removeTimeObserver(timeObserverToken)
                self.timeObserverToken = nil
            }
        }
    }
    
    //basic setup of the inthegame overlay view
    func setupOverlay() {
        let overlay = ITGOverlayView(frame: view.bounds)
        overlay.translatesAutoresizingMaskIntoConstraints = true
        overlay.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        containerView.addSubview(overlay)
        
        overlay.load(channelID: channelID, broadcasterName: broadcaster, delegate: self)
        overlayView = overlay
    }
    
    func configureMenuButtonHandler() {
        let menuPressRecognizer = UITapGestureRecognizer()
        menuPressRecognizer.addTarget(self, action: #selector(menuButtonAction(recognizer:)))
        menuPressRecognizer.allowedPressTypes = [NSNumber(value: UIPress.PressType.menu.rawValue)]
        view.addGestureRecognizer(menuPressRecognizer)
    }
        
    @objc func menuButtonAction(recognizer:UITapGestureRecognizer) {
        //passing the menu button event to the overlay
        //overlay returns true if it uses the event to close the current interaction
        //if it returns false, you should use the event
        let interactionClosed = overlayView?.closeInteractionIfNeeded() ?? false
        if !interactionClosed {
            dismiss(animated: true, completion: nil)
        }
    }
    
    func startVideo() {
        playerLayer?.player?.removeObserver(self, forKeyPath: "timeControlStatus")
        playerLayer?.player = nil
        playerLayer?.removeFromSuperlayer()
        
        let asset = AVAsset(url: URL(string: videoURL)!)
        let item = AVPlayerItem(asset: asset)
        let player = AVPlayer(playerItem: item)
        let view = AVPlayerView(frame: self.view.bounds)
        view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.translatesAutoresizingMaskIntoConstraints = true
        view.player = player
        view.playerLayer.frame = view.bounds

        playerView = view
        
        view.playerLayer.videoGravity = .resizeAspect
        view.playerLayer.needsDisplayOnBoundsChange = true
        playerLayer = view.playerLayer
        containerView.addSubview(view)
        
        player.play()
        controlsView.setVideoTime(0, duration: nil)
        
        let timeScale = CMTimeScale(NSEC_PER_SEC)
        let time = CMTime(seconds: 0.5, preferredTimescale: timeScale)
        
        timeObserverToken = player.addPeriodicTimeObserver(forInterval: time,
                                                           queue: .main) { [weak self] time in
            let duration = self?.playerLayer?.player?.currentItem?.duration.seconds
            self?.controlsView.setVideoTime(time.seconds, duration: duration)
        }
    }
    
    @IBAction func actionPlayButton(_ sender: Any) {
        guard let player = self.playerLayer?.player else { return }
        if (player.rate != 0) {
            pause()
        } else if (player.currentItem?.status == .readyToPlay) {
            play()
        }
    }
    
    func play() {
        guard let player = self.playerLayer?.player else { return }
        player.play()
        controlsView.playButton.setImage(UIImage(named: "pause"), for: .normal)
        let time = player.currentTime().seconds
        
        //notify the overlay of the current playing time
        overlayView?.videoPlaying(time: time)
    }
    
    func pause() {
        guard let player = self.playerLayer?.player else { return }
        player.pause()
        controlsView.playButton?.setImage(UIImage(named: "play"), for: .normal)
        
        //notify the overlay that the video is paused
        overlayView?.videoPaused()
    }
    
    override var preferredFocusedView: UIView? {
        return customPreferredFocusView
    }
}

extension PlayerViewController: ITGOverlayDelegate {
    func overlayRequestedPause() {
        pause()
    }
    
    func overlayRequestedPlay() {
        play()
    }
    
    func overlayRequestedFocus() {
        //overlay started an interaction
        //we will focus on it for user interaction
        customPreferredFocusView = overlayView
        view.setNeedsFocusUpdate()
        view.updateFocusIfNeeded()
    }
    
    func overlayReleasedFocus() {
        //overlay finished an interaction
        //you can move focus to one of your views if needed
        //(in most cases it should update automatically)
    }
}
