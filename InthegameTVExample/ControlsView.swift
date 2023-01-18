//
//  ControlsView.swift
//  InthegameTVExample
//
//  Created by Tiago Lira Pereira on 17/02/2021.
//

import UIKit

class ControlsView: UIView {
    
    @IBOutlet weak var playButton: UIButton!
    @IBOutlet weak var progressBar: UIProgressView!

    override func awakeFromNib() {
        super.awakeFromNib()
        playButton.imageView?.contentMode = .scaleAspectFit
    }
    
    func setVideoTime(_ time: Double, duration: Double?) {
        setProgress(time, duration: duration ?? 60)
    }
    
    func setProgress(_ time: Double, duration: Double) {
        let progress = time / duration
        progressBar.progress = Float(progress)
    }
    
    override func didUpdateFocus(in context: UIFocusUpdateContext, with coordinator: UIFocusAnimationCoordinator) {
        super.didUpdateFocus(in: context, with: coordinator)
        if let focusedButton = context.nextFocusedView as? UIButton, focusedButton == playButton {
                coordinator.addCoordinatedAnimations({
                    let scale: CGFloat = 1.2
                    focusedButton.transform = CGAffineTransform(scaleX: scale, y: scale)
                }, completion: {})
            }
        if let unfocusedButton = context.previouslyFocusedView as? UIButton, unfocusedButton == playButton {
                coordinator.addCoordinatedAnimations({
                    unfocusedButton.transform = CGAffineTransform.identity
                }, completion: {})
            }
    }
    
}
