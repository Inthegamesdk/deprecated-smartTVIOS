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
    
    public var overlayView: ITGOverlayView?
    
    var playerController: AVPlayerViewController?
    var player: AVPlayer?
    var seekTimer: Timer?

    weak var customPreferredFocusView: UIView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        startVideo()
        setupOverlay()
        configureMenuButtonHandler()
        configureDownButtonHandler()
    }
    
    func startVideo() {
        let asset = AVAsset(url: URL(string: videoURL)!)
        let item = AVPlayerItem(asset: asset)
        let player = AVPlayer(playerItem: item)
        
        let playerViewController = AVPlayerViewController()
        playerViewController.player = player
        playerViewController.showsPlaybackControls = true
        playerViewController.playbackControlsIncludeInfoViews = false
        playerViewController.videoGravity = .resizeAspect
        self.playerController = playerViewController
        if let view = playerViewController.view {
            view.frame = self.view.bounds
            view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
            view.translatesAutoresizingMaskIntoConstraints = true
            self.addChild(playerViewController)
            self.containerView.addSubview(view)
        }
        self.player = player
        
        player.play()
        startVideoObservers()
        
        customPreferredFocusView = playerController?.view
        view.setNeedsFocusUpdate()
        view.updateFocusIfNeeded()
    }
    
    func setupOverlay() {
        let overlay = ITGOverlayView(frame: view.bounds)
        overlay.translatesAutoresizingMaskIntoConstraints = true
        overlay.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        containerView.addSubview(overlay)
        
        overlay.load(channelID: channelID, broadcasterName: broadcaster, delegate: self)
        overlayView = overlay
    }
    
    //this handler allows the overlay to use the menu button click to remove the current interaction
    func configureMenuButtonHandler() {
        let menuPressRecognizer = UITapGestureRecognizer()
        menuPressRecognizer.addTarget(self, action: #selector(menuButtonAction(recognizer:)))
        menuPressRecognizer.allowedPressTypes = [NSNumber(value: UIPress.PressType.menu.rawValue)]
        view.addGestureRecognizer(menuPressRecognizer)
    }
        
    @objc func menuButtonAction(recognizer:UITapGestureRecognizer) {
        let interactionClosed = overlayView?.closeInteractionIfNeeded() ?? false
        //if the overlay doesn't use the event, we can use it in the app
        if !interactionClosed {
            dismiss(animated: true) {
                self.removePlayer()
            }
        }
    }
    
    //this handler moves the focus to the overlay content when the user presses the "down" key
    //this step is optional - it is useful in this example because the AVPlayerController controls override the "up" key
    func configureDownButtonHandler() {
        let menuPressRecognizer = UITapGestureRecognizer()
        menuPressRecognizer.addTarget(self, action: #selector(downButtonAction(recognizer:)))
        menuPressRecognizer.allowedPressTypes = [NSNumber(value: UIPress.PressType.downArrow.rawValue)]
        view.addGestureRecognizer(menuPressRecognizer)
    }
        
    @objc func downButtonAction(recognizer:UITapGestureRecognizer) {
        let hasInteraction = overlayView?.isDisplayingInteraction() == true
        if hasInteraction {
            customPreferredFocusView = overlayView
            view.setNeedsFocusUpdate()
            view.updateFocusIfNeeded()
        }
    }
    
    func removePlayer() {
        player?.pause()
        playerController?.view.removeFromSuperview()
        playerController?.removeFromParent()
        playerController = nil
        player = nil
    }
    
    override var preferredFocusedView: UIView? {
        return customPreferredFocusView
    }
    
    func startVideoObservers() {
        guard let player = player, let item = player.currentItem else { return }
        
        NotificationCenter.default.addObserver(forName: NSNotification.Name.AVPlayerItemTimeJumped, object: item, queue: OperationQueue.main) { (notification) in
            if player.timeControlStatus != .playing {
                self.overlayView?.videoPaused()
//                print("VIDEO STATE: PAUSED")
            } else {
                self.seekTimer?.invalidate()
                self.seekTimer = Timer.scheduledTimer(withTimeInterval: 0.4, repeats: false, block: { (timer) in
                    self.seekTimer = nil
                    if player.timeControlStatus == .playing {
                        let time = player.currentTime().seconds
                        self.overlayView?.videoPlaying(time: time)
//                        print("VIDEO STATE: PLAYING \(time)")
                    }
                })
            }
        }
    }
}

extension PlayerViewController: ITGOverlayDelegate {
    func overlayRequestedPause() {
        player?.pause()
    }
    
    func overlayRequestedPlay() {
        player?.play()
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
        customPreferredFocusView = playerController?.view
        view.setNeedsFocusUpdate()
        view.updateFocusIfNeeded()
    }
}
