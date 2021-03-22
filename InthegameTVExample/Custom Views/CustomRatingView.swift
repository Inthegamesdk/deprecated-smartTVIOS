//
//  CustomRatingView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 18/03/2021.
//

import UIKit
import Inthegametv

class CustomRatingView: ITGRatingView {
    
    override func createAnswerView() -> ITGRatingAnswerView {
        return CustomRatingAnswerView.fromNib()
    }

}
