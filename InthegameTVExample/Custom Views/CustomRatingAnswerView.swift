//
//  CustomRatingAnswerView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 18/03/2021.
//

import UIKit
import Inthegametv

class CustomRatingAnswerView: ITGRatingAnswerView {
    
    override func setButtonStyleNormal() {
        //fill in for a custom button style
        //if you do not override these methods, the default Inthegame button style will be used
    }
    
    override func setButtonStyleCompleted(selected: Bool) {
        if selected {
            let imageNormal = UIImage.imageWithColor(.blue)
            button.setBackgroundImage(imageNormal, for: .normal)
        }
    }
}
