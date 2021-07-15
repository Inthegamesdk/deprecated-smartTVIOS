//
//  CustomPollView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 17/03/2021.
//

import UIKit
import Inthegametv

class CustomPollView: ITGPollView {

    override func createAnswerView() -> ITGPollAnswerView {
        return CustomPollAnswerView.fromNib()
    }
    
    // The following override methods are optional
    // and provide you with extra options for customization
    
    override func didLoadView() {
        //customize view at startup after it finishes loading
    }

    override func didAnswerPoll() {
        //customize view after answering if needed
    }
}
