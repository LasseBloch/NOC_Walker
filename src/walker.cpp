//
// Created by Lasse Lauritsen on 03/02/2017.
//
#include "walker.h"

walker::walker(int screenWidth, int screenHeight) : startXPos_(screenWidth / 2), startYPos_(screenHeight / 2), screenHeight_ (screenHeight), screenWidth_(screenWidth), rnd_(time(0))  {
  xPos_ = startXPos_;
  yPos_ = startYPos_;
  gen_ = std::uniform_int_distribution<int>(0,3);
  speed_ = 1;
}

std::pair<int, int> walker::getPos() const {
  return std::pair<int, int>(xPos_,yPos_);
}

bool walker::walk() {

  int n = gen_(rnd_);
  if (n == 0) {
    xPos_ -= speed_;
  }
  else if (n == 1) {
    xPos_ += speed_;
  }
  else if (n == 2) {
    yPos_ -= speed_;
  }
  else if (n == 3)
  {
    yPos_ += speed_;
  }

  if (xPos_ <= screenWidth_ || xPos_ <= 0 || yPos_ <= screenHeight_ || yPos_ <= 0) {
    return true;
  }
  return false;
}
