#include "Player.hpp"

#include <cmath> // for abs function (see collisions)

Player::Player (float x, float y) {
  rect.x = x;
  rect.y = y;
  rect.width = 64;
  rect.height = 128;

  // for the gravity
  yMomentum = 0;

  resetCollisions ();

}

// gravity
void Player::applyGravity () {

  if (!collisions.bottom) {

    rect.y += yMomentum;
    yMomentum += gravitySpeed;

  }
}

void Player::draw () {
  DrawRectangleRec(rect, RED);
}

void Player::checkCollisions (std::vector<Block> blocks) {

  resetCollisions ();

  // for each block, if the player collides block, check wich side
  for (int i = 0; i < blocks.size(); ++i) {
    if (CheckCollisionRecs(rect, blocks[i].rect)) {

      if (( rect.y + rect.height <= blocks[i].rect.y + abs(yMomentum)) &&
         (rect.y + rect.height >= blocks[i].rect.y)) {
        collisions.bottom = true;
        rect.y = blocks[i].rect.y - rect.height; // for don't crop the block
        yMomentum = 0;
      }

      if (( rect.y >= abs(blocks[i].rect.y + blocks[i].rect.height - abs(yMomentum))) &&
         (rect.y <= blocks[i].rect.y + blocks[i].rect.height)) {
        collisions.top = true;
        rect.y = blocks[i].rect.y + blocks[i].rect.height;
        if (yMomentum < 0) yMomentum *= -1;
      }

      if (( rect.x + rect.width <= blocks[i].rect.x + speed) &&
         (rect.x + rect.width >= blocks[i].rect.x)) {
        collisions.left = true;
        rect.x = blocks[i].rect.x - rect.width;
      }

      if (( rect.x >= abs(blocks[i].rect.x + blocks[i].rect.width - speed)) &&
         (rect.x <= blocks[i].rect.x + blocks[i].rect.width)) {
        collisions.left = true;
        rect.x = blocks[i].rect.x + blocks[i].rect.width;
      }

    }
  }
}

void Player::resetCollisions () {
  collisions.top = false;
  collisions.bottom = false;
  collisions.left = false;
  collisions.right = false;
}

void Player::move () {
  if ((IsKeyDown(KEY_RIGHT)) && (rect.x < 896 - rect.width) && (!collisions.right)) rect.x += speed;
  else if ((IsKeyDown(KEY_LEFT)) && (rect.x > 0) && (!collisions.left)) rect.x -= speed;

  if (IsKeyDown(KEY_UP)) jump ();

  applyGravity();

}

void Player::jump () {
  if (collisions.bottom)
    yMomentum = -20; // go to the sky :ahde:
}
