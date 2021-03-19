//
//  CustomTriviaView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 18/03/2021.
//

import UIKit
import Inthegametv

class CustomTriviaView: TriviaView {
    
    override func createAnswerView() -> TriviaAnswerView {
        return CustomTriviaAnswerView.fromNib()
    }
}
