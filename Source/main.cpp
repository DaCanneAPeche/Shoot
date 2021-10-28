#include "Game.hpp"
#include <iostream>
#include "raylib.h" // raylib : graphic lib

// main function
int main(int argc, char const *argv[]) {

  // 896 / 896 = 14 tiles / 14 tiles
  Game game (896, 896, 60, Color {255, 242, 229, 255}); // define the game
  game.run(); // run the game

  return 0;
}
