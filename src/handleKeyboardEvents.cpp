#include <iostream>

#include "handleKeyboardEvents.h"

[[nodiscard]] MovementState newStateOnKeyPressed(sf::Event& event, const MovementState& oldState) {
  MovementState newState = oldState;
  
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Right:
        newState.isMovingRight = true;
        break;

      case sf::Keyboard::Left:
        newState.isMovingLeft = true;
        break;

      case sf::Keyboard::Up:
        newState.isMovingUp = true;
        break;

      case sf::Keyboard::Down:
        newState.isMovingDown = true;
        break;
    }
  }

  return newState;
}

[[nodiscard]] MovementState newStateOnKeyReleased(sf::Event& event, const MovementState& oldState) {
  MovementState newState = oldState;

  if (event.type == sf::Event::KeyReleased) {
    switch (event.key.code) {
      case sf::Keyboard::Right:
        newState.isMovingRight = false;
        break;

      case sf::Keyboard::Left:
        newState.isMovingLeft = false;
        break;

      case sf::Keyboard::Up:
        newState.isMovingUp = false;
        break;

      case sf::Keyboard::Down:
        newState.isMovingDown = false;
        break;
    }
  }

  return newState;
}
