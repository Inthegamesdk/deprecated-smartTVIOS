//
//  CustomTriviaAnswerView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 18/03/2021.
//

import UIKit
import Inthegametv

class CustomTriviaAnswerView: TriviaAnswerView {
    
    override func setButtonStyleNormal() {
        //fill in for a custom button style
        //if you do not override these methods, the default Inthegame button style will be used
    }
    
    override func setButtonStyleCorrect() {
        let imageNormal = UIImage.imageWithColor(.blue)
        button.setBackgroundImage(imageNormal, for: .normal)
    }
    
    override func setButtonStyleIncorrect() {
        let imageNormal = UIImage.imageWithColor(.systemRed)
        button.setBackgroundImage(imageNormal, for: .normal)
    }
}
