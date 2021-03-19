//
//  CustomRatingView.swift
//  InthegameTVDemo
//
//  Created by Tiago Lira Pereira on 18/03/2021.
//

import UIKit
import Inthegametv

class CustomRatingView: RatingView {
    
    override func createAnswerView() -> RatingAnswerView {
        return CustomRatingAnswerView.fromNib()
    }

}
