#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "raylib.h"

class Block {
private:
  /* data */

public:
  Rectangle rect;
  Block (float x, float y, int width, int height); // constructor
};

#endif
