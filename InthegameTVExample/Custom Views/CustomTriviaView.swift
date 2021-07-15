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
    
    // The following override methods are optional
    // and provide you with extra options for customization
    
    override func didLoadView() {
        //customize view at startup after it finishes loading
    }
    
    override func didAnswerTrivia() {
        //customize view after answering if needed
    }
}
