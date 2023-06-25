#include <iostream>

#include "handleEvents.h"

// TODO: Should this be some sort of static class or namespace?

//--------------------------------------------------------------------------------------------------
// Public methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] MovementState movementStateFromEvents(const MovementState& oldState, sf::Event& event) {
  MovementState newState = oldState;

  //------------------------------------------------------------------------------------------------
  // Keyboard events
  //------------------------------------------------------------------------------------------------
  newState = newStateOnKeyPressed(newState, event);
  newState = newStateOnKeyReleased(newState, event);

  return newState;
}

//--------------------------------------------------------------------------------------------------
// Private methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] MovementState newStateOnKeyPressed(const MovementState& oldState, const sf::Event& event) {
  MovementState newState = oldState;
  
  if (event.type != sf::Event::KeyPressed) return newState;

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

  return newState;
}

[[nodiscard]] MovementState newStateOnKeyReleased(const MovementState& oldState, const sf::Event& event) {
  MovementState newState = oldState;

  if (event.type != sf::Event::KeyReleased) return newState; 

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


  return newState;
}
