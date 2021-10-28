#include "Game.hpp"
#include <iostream>
#include <vector>
#include "raylib.h"

// constructor
Game::Game (const int screenWidth, const int screenHeight, const int fps, Color windowColor) :
                                                                   // init the player
                                                                   player (Player (400, 0)){

  // for draw the background in de drawScreen function
  backgroundColor = windowColor;
  blocks = {Block (2, 10, 10, 1), Block (2, 6, 3, 1), Block (5, 5, 3, 1)}; // the blocks

  // create the window
  InitWindow(screenWidth, screenHeight, "Shoot!");

  // set FPS limit
  SetTargetFPS(fps);
}

// the game, but without the window
void Game::updateGame () {
  player.move(); // move the player (see Player class)
  player.checkCollisions(blocks); // collisions between the player and the blocks (see Player class)
}

void Game::drawBlocks () {

  for (int i = 0; i < blocks.size(); ++i) {
    DrawRectangleRec(blocks[i].rect, BLUE);
  }

}

// main drawing function
void Game::drawScreen () {
  BeginDrawing();

    ClearBackground(backgroundColor); // draw background

    player.draw(); // see Player class
    drawBlocks();

  EndDrawing();
}

// the main function of the class
void Game::run () {
  while (!WindowShouldClose()) {
    updateGame();
    drawScreen();
  }

  CloseWindow();
}
