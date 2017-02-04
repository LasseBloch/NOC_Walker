//
// Created by Lasse Lauritsen on 03/02/2017.
//
#include "walker.h"

walker::walker(int screenWidth, int screenHeight) : startXPos_(screenWidth / 2), startYPos_(screenHeight / 2), screenHeight_ (screenHeight), screenWidth_(screenWidth), rnd_(time(0))  {
  xPos_ = startXPos_;
  yPos_ = startYPos_;
  speed_ = 1;
  gen_ = std::uniform_int_distribution<int>(-speed_,speed_);
}

std::pair<int, int> walker::getPos() const {
  return std::pair<int, int>(xPos_,yPos_);
}

bool walker::walk() {

  xPos_ += gen_(rnd_);
  yPos_ += gen_(rnd_);
  // return false the walker walks out of bounds
  return !((xPos_ > screenWidth_ || xPos_ < 0) || (yPos_ > screenHeight_ || yPos_ < 0));

}
