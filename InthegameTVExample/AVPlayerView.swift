//
//  AVPlayerView.swift
//  InthegameTVExample
//
//  Created by Tiago Lira Pereira on 01/02/2021.
//

import UIKit
import AVFoundation


class AVPlayerView: UIView {
    var player: AVPlayer? {
        get {
            return playerLayer.player
        }

        set {
            playerLayer.player = newValue
        }
    }

    var playerLayer: AVPlayerLayer {
        return layer as! AVPlayerLayer
    }

    override class var layerClass: AnyClass {
        return AVPlayerLayer.self
    }
}
