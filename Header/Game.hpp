#ifndef GAME_HPP
#define GAME_HPP

#include "raylib.h"

#include "Player.hpp"
#include "Block.hpp"

class Game {
private:
  void drawScreen();
  void updateGame();
  void drawBlocks ();

  Color backgroundColor;
  Player player;
  std::vector<Block> blocks; // the blocks

public:
  Game (const int screenWidth, const int screenHeight, const int fps, Color windowColor);
  void run();
};

#endif
