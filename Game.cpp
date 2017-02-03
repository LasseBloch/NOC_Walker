//
// Created by Lasse Lauritsen on 03/02/2017.
//

#include "Game.h"
#include "walker.h"

Game::Game(int screenHeight, int screenWidth) : screenHeight_(screenHeight), screenWidth_(screenWidth) {
  init();
}

bool Game::init() {

  bool success = true;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("SDL could not be initialized! SDL_ERROR: %s\n", SDL_GetError());
    success = false;
  } else
  {
    // Create window
    window_ = SDL_CreateWindow("Walker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth_, screenHeight_, SDL_WINDOW_SHOWN);
    if (window_) {
      // Create renderer for window_
      renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
      if (!renderer_) {
        SDL_Log("Could not create renderer! SDL_ERROR: %s\n", SDL_GetError());
        success = false;
      }
    } else
    {
      SDL_Log("Could not create window! SDL_ERROR: ‰s \n", SDL_GetError());
      success = false;
    }
  }
  return success;
}

void Game::close() {
  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;
  SDL_DestroyWindow(window_);
  window_ = nullptr;
  SDL_Quit();
}

int Game::startLoop() {
  if (init())
  {
    bool quit = false;
    walker walker(screenWidth_, screenHeight_);
    SDL_Event evt;
    while(!quit) {
      // Handle events
      while(SDL_PollEvent(&evt)) {
        switch (evt.type) {
          case SDL_QUIT:
            SDL_Log("Quit event\n");
            quit = true;
            break;
          default:
            break;
        }
      }
      // Walk the walker if it hits the sides game over!
      if (walker.walk()){
        drawWalkerPos(walker.getPos());
        //printf("walker pos: %d %d\n", walker.getPos().first, walker.getPos().second);

      }
      else {
        quit = true;
      }
    }
  }
  close();
  return 0;
}

void Game::drawWalkerPos(std::pair<int, int> pos) {
  SDL_SetRenderDrawColor(renderer_, 255, 255, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawPoint(renderer_, pos.first, pos.second);
  SDL_RenderPresent(renderer_);
}


