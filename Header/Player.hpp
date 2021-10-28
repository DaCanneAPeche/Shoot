#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "Block.hpp"
#include <iostream>
#include <vector>

struct Collisions {

  bool top, bottom, left, right;

};

class Player {
private:
  const int speed = 5;
  const int gravitySpeed = 1;
  Collisions collisions;

  int yMomentum;

  void applyGravity ();
  void resetCollisions ();
  void jump ();

public:
  Player (float x, float y);

  Rectangle rect;

  void move ();
  void draw ();
  void checkCollisions (std::vector<Block> blocks);
};

#endif
