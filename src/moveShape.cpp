#include "moveShape.h"

sf::RectangleShape moveBasedOnMovementState(sf::RectangleShape oldRectangle, const MovementState movementState) {
  // TODO: this should probably be a part of MovementState I'd think.
  const float speed = 5.0f;

  const sf::Vector2f oldPosition = oldRectangle.getPosition();
  float newX = oldPosition.x;
  float newY = oldPosition.y;

  if (movementState.isMovingRight) newX += speed;
  if (movementState.isMovingLeft) newX -= speed;
  if (movementState.isMovingUp) newY -= speed;
  if (movementState.isMovingDown) newY += speed;

  sf::RectangleShape newRectangle = oldRectangle;
  newRectangle.setPosition(newX, newY);
  return newRectangle;
}
