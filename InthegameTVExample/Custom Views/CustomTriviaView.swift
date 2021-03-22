//
//  CustomTriviaView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 18/03/2021.
//

import UIKit
import Inthegametv

class CustomTriviaView: ITGTriviaView {
    
    override func createAnswerView() -> ITGTriviaAnswerView {
        return CustomTriviaAnswerView.fromNib()
    }
}
