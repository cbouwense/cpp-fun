#include "GameState.h"
#include "buildMovementState.h"

MovementState buildMovementState(const MovementState oldMovementState, const InputState inputState, const CollisionState collisionState) {
  MovementState newMovementState = oldMovementState;

  newMovementState.isMovingUp = inputState.isPressingUp && !collisionState.isCollidingTop;
  newMovementState.isMovingRight = inputState.isPressingRight && !collisionState.isCollidingRight;
  newMovementState.isMovingDown = inputState.isPressingDown && !collisionState.isCollidingBottom;
  newMovementState.isMovingLeft = inputState.isPressingLeft && !collisionState.isCollidingLeft;

  return newMovementState;
}
