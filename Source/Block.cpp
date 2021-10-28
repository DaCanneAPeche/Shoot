#include "Block.hpp"

Block::Block (float x, float y, int width, int height) {
  rect.x = x*64;
  rect.y = y*64;
  rect.width = width*64;
  rect.height = height*64;
}
