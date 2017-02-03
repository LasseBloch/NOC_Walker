//
// Created by Lasse Lauritsen on 03/02/2017.
//

#ifndef WALKER_GAME_H
#define WALKER_GAME_H
#include <SDL.h>
#include <utility>

class Game {
 public:
  Game(int screenHeight = 600, int screenWidth = 800);
  int startLoop();

 private:
  int const screenHeight_;
  int const screenWidth_;
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;

  bool init();
  void close();
  void drawWalkerPos(std::pair<int, int> pos);
};
#endif //WALKER_GAME_H
