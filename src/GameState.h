#ifndef GAME_STATE_H
#define GAME_STATE_H

struct CollisionState {
  bool isCollidingTop;
  bool isCollidingRight;
  bool isCollidingBottom;
  bool isCollidingLeft;
};

struct InputState {
  bool isPressingUp;
  bool isPressingRight;
  bool isPressingDown;
  bool isPressingLeft;
};

struct MovementState {
  bool isMovingUp;
  bool isMovingRight;
  bool isMovingDown;
  bool isMovingLeft;
};

#endif
