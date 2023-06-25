#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "handleEvents.h"

//--------------------------------------------------------------------------------------------------
// Public methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] InputState buildNewInputState(const InputState oldState, sf::Event event) {
  InputState newState = oldState;

  newState = newStateOnKeyPressed(newState, event);
  newState = newStateOnKeyReleased(newState, event);

  return newState;
}

//--------------------------------------------------------------------------------------------------
// Private methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] InputState newStateOnKeyPressed(const InputState oldState, const sf::Event event) {
  InputState newState = oldState;
  
  if (event.type != sf::Event::KeyPressed) return newState;

  switch (event.key.code) {
    case sf::Keyboard::Right:
      newState.isPressingRight = true;
      break;

    case sf::Keyboard::Left:
      newState.isPressingLeft = true;
      break;

    case sf::Keyboard::Up:
      newState.isPressingUp = true;
      break;

    case sf::Keyboard::Down:
      newState.isPressingDown = true;
      break;
  }

  return newState;
}

[[nodiscard]] InputState newStateOnKeyReleased(const InputState oldState, const sf::Event event) {
  InputState newState = oldState;

  if (event.type != sf::Event::KeyReleased) return newState; 

  switch (event.key.code) {
    case sf::Keyboard::Right:
      newState.isPressingRight = false;
      break;

    case sf::Keyboard::Left:
      newState.isPressingLeft = false;
      break;

    case sf::Keyboard::Up:
      newState.isPressingUp = false;
      break;

    case sf::Keyboard::Down:
      newState.isPressingDown = false;
      break;
  }

  return newState;
}
