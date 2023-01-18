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

let channelSlug = "channel_one_stage"
let accountName = "cellcom"
let accountId = "631da52247f9e460d1039022"
let language = "en"
let videoURL = "https://media2.inthegame.io/uploads/automation_demo.mp4"

class PlayerViewController: UIViewController {

    @IBOutlet weak var containerView: UIView!
    
    public var overlayView: ITGOverlayView?
    
    private var playerController: AVPlayerViewController?
    private var player: AVPlayer?
    private var seekTimer: Timer?
    private var initialHeight: CGFloat!
    private var initialWidth: CGFloat!

    weak var customPreferredFocusView: UIView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        startVideo()
        setupOverlay()
        configureMenuButtonHandler()
    }
    
    func startVideo() {
        initialHeight = view.frame.height
        initialWidth = view.frame.height
        
        let asset = AVAsset(url: URL(string: videoURL)!)
        let item = AVPlayerItem(asset: asset)
        let player = AVPlayer(playerItem: item)
        
        let playerViewController = AVPlayerViewController()
        playerViewController.player = player
        playerViewController.showsPlaybackControls = true
        playerViewController.playbackControlsIncludeInfoViews = false
        playerViewController.videoGravity = .resize
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
        //create the overlay and add it to your view hierarchy
        let overlay = ITGOverlayView(frame: view.bounds)
        overlay.translatesAutoresizingMaskIntoConstraints = true
        overlay.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        containerView.addSubview(overlay)
        
        //load your channel to start up the ITG system
        overlay.load(channelSlug: channelSlug, accountId: accountId, environment: .stage, delegate: self, language: language, foreignId: nil)
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
        NotificationCenter.default.addObserver(forName: AVPlayerItem.timeJumpedNotification, object: item, queue: OperationQueue.main) { (notification) in
            if player.timeControlStatus != .playing {
                self.overlayView?.videoPaused(time: player.currentTime().seconds)
            } else {
                self.seekTimer?.invalidate()
                self.seekTimer = Timer.scheduledTimer(withTimeInterval: 0.4, repeats: false, block: { (timer) in
                    self.seekTimer = nil
                    if player.timeControlStatus == .playing {
                        let time = player.currentTime().seconds
                        self.overlayView?.videoPlaying(time: time)
                    }
                })
            }
        }
    }
    
}

extension PlayerViewController: ITGOverlayDelegate {
    
    func overlayRequestedVideoTime() {
        //overlay may require current video time and state so host application needs to provide it
        guard let player = player else { return }
        let time = player.currentTime().seconds
        if player.timeControlStatus == .playing {
            overlayView?.videoPlaying(time: time)
        } else {
            overlayView?.videoPaused(time: time)
        }
    }
    
    func overlayResizeVideoWidth(activityWidth: CGFloat) {
        //optional - you can adjust the video size when the overlay is showing content
        playerController?.view.frame.size = CGSize(width: view.frame.width - activityWidth, height: view.frame.height)
        view.setNeedsFocusUpdate()
        view.updateFocusIfNeeded()
    }
    
    func overlayResetVideoWidth() {
        playerController?.view.frame.size = CGSize(width: initialWidth, height: view.frame.width)
        view.setNeedsFocusUpdate()
        view.updateFocusIfNeeded()
    }
    
    func overlayResizeVideoHeight(activityHeight: CGFloat) {
        //optional - you can adjust the video size when the overlay is showing content
        playerController?.view.frame.size = CGSize(width: view.frame.width, height: view.frame.height - activityHeight)
        view.setNeedsFocusUpdate()
        view.updateFocusIfNeeded()
    }
    
    func overlayResetVideoHeight() {
        playerController?.view.frame.size = CGSize(width: view.frame.width, height: initialHeight)
        view.setNeedsFocusUpdate()
        view.updateFocusIfNeeded()
    }
    
    func overlayReceivedDeeplink(_ link: String) {
        //custom deeplink may be setup on admin and passed from overlay to host application
    }
    
    func overlayRequestedVideoSeek(time: Double) {
        guard let player = player else { return }
        player.seek(to: CMTime(value: CMTimeValue(time), timescale: 1))
    }
    
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
