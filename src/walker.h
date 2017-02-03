//
// Created by Lasse Lauritsen on 03/02/2017.
//

#ifndef WALKER_WALKER_H
#define WALKER_WALKER_H
#include <utility>
#include <random>

class walker {
 public:
  walker(int screenWidth, int screenHeight);
  std::pair<int, int> getPos() const;
  bool walk();

 private:
  int const startYPos_;
  int const startXPos_;
  int const screenWidth_;
  int const screenHeight_;
  int xPos_;
  int yPos_;
  int speed_;
  std::mt19937 rnd_;
  std::uniform_int_distribution<int> gen_;
};

#endif //WALKER_WALKER_H
