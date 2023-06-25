#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "buildNewCollisionState.h"

CollisionState buildNewCollisionState(const CollisionState oldCollisionState, const sf::RectangleShape rectangle, const sf::RenderWindow& window) {
  const float oldWidth = rectangle.getSize().x;
  const float oldHeight = rectangle.getSize().y;
  const float windowWidth = window.getSize().x;
  const float windowHeight = window.getSize().y;

  const sf::Vector2f position = rectangle.getPosition();
  const float x = position.x;
  const float y = position.y;

  CollisionState newCollisionState = {
    y <= 0.0f,
    x + oldWidth >= windowWidth,
    y + oldHeight >= windowHeight,
    x <= 0.0f
  };

  return newCollisionState;
}
