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

}
