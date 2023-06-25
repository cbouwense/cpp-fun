#include "buildRectangleShape.h"

sf::RectangleShape buildRectangleShape(sf::RectangleShape oldRectangle, const MovementState movementState, const float deltaTime) {
  // TODO: this should probably be a part of MovementState I'd think.
  const float speed = 250.0f;

  const sf::Vector2f oldPosition = oldRectangle.getPosition();
  float newX = oldPosition.x;
  float newY = oldPosition.y;

  if (movementState.isMovingRight) newX += speed * deltaTime;
  if (movementState.isMovingLeft) newX -= speed * deltaTime;
  if (movementState.isMovingUp) newY -= speed * deltaTime;
  if (movementState.isMovingDown) newY += speed * deltaTime;

  sf::RectangleShape newRectangle = oldRectangle;
  newRectangle.setPosition(newX, newY);

  return newRectangle;
}
