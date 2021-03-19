//
//  CustomPollView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 17/03/2021.
//

import UIKit
import Inthegametv

class CustomPollView: PollView {

    override func createAnswerView() -> PollAnswerView {
        return CustomPollAnswerView.fromNib()
    }

}
