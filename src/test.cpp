#include <catch2/catch_test_macros.hpp>

#include "handleKeyboardEvents.h"

TEST_CASE("movementStateFromEvents") {

  //------------------------------------------------------------------------------------------------
  // Keyboard press
  //------------------------------------------------------------------------------------------------
  SECTION("When the event is a keyboard press right key, the resulting state should have isMovingRight set to true") {
    MovementState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event rightKeyPressedEvent;
    rightKeyPressedEvent.type = sf::Event::KeyPressed;
    rightKeyPressedEvent.key.code = sf::Keyboard::Right;

    MovementState resultState = movementStateFromEvents(oldState, rightKeyPressedEvent);
  
    REQUIRE(resultState.isMovingRight == true);
  }

  SECTION("When the event is a keyboard press left key, the resulting state should have isMovingLeft set to true") {
    MovementState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event leftKeyPressedEvent;
    leftKeyPressedEvent.type = sf::Event::KeyPressed;
    leftKeyPressedEvent.key.code = sf::Keyboard::Left;

    MovementState resultState = movementStateFromEvents(oldState, leftKeyPressedEvent);
  
    REQUIRE(resultState.isMovingLeft == true);
  }

  SECTION("When the event is a keyboard press up key, the resulting state should have isMovingUp set to true") {
    MovementState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event upKeyPressedEvent;
    upKeyPressedEvent.type = sf::Event::KeyPressed;
    upKeyPressedEvent.key.code = sf::Keyboard::Up;

    MovementState resultState = movementStateFromEvents(oldState, upKeyPressedEvent);
  
    REQUIRE(resultState.isMovingUp == true);
  }

  SECTION("When the event is a keyboard press down key, the resulting state should have isMovingDown set to true") {
    MovementState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event downKeyPressedEvent;
    downKeyPressedEvent.type = sf::Event::KeyPressed;
    downKeyPressedEvent.key.code = sf::Keyboard::Down;

    MovementState resultState = movementStateFromEvents(oldState, downKeyPressedEvent);
  
    REQUIRE(resultState.isMovingDown == true);
  }

  //------------------------------------------------------------------------------------------------
  // Keyboard release
  //------------------------------------------------------------------------------------------------
  SECTION("When the event is a keyboard release right key, the resulting state should have isMovingRight set to false") {
    MovementState oldState = {
      true,
      false,
      false,
      false
    };

    sf::Event rightKeyReleasedEvent;
    rightKeyReleasedEvent.type = sf::Event::KeyReleased;
    rightKeyReleasedEvent.key.code = sf::Keyboard::Right;

    MovementState resultState = movementStateFromEvents(oldState, rightKeyReleasedEvent);
  
    REQUIRE(resultState.isMovingRight == false);
  }

  SECTION("When the event is a keyboard release left key, the resulting state should have isMovingLeft set to false") {
    MovementState oldState = {
      false,
      true,
      false,
      false
    };

    sf::Event leftKeyReleasedEvent;
    leftKeyReleasedEvent.type = sf::Event::KeyReleased;
    leftKeyReleasedEvent.key.code = sf::Keyboard::Left;

    MovementState resultState = movementStateFromEvents(oldState, leftKeyReleasedEvent);
  
    REQUIRE(resultState.isMovingLeft == false);
  }

  SECTION("When the event is a keyboard release up key, the resulting state should have isMovingUp set to false") {
    MovementState oldState = {
      false,
      false,
      true,
      false
    };

    sf::Event upKeyReleasedEvent;
    upKeyReleasedEvent.type = sf::Event::KeyReleased;
    upKeyReleasedEvent.key.code = sf::Keyboard::Up;

    MovementState resultState = movementStateFromEvents(oldState, upKeyReleasedEvent);
  
    REQUIRE(resultState.isMovingUp == false);
  }

  SECTION("When the event is a keyboard release down key, the resulting state should have isMovingDown set to false") {
    MovementState oldState = {
      false,
      false,
      false,
      true
    };

    sf::Event downKeyReleasedEvent;
    downKeyReleasedEvent.type = sf::Event::KeyReleased;
    downKeyReleasedEvent.key.code = sf::Keyboard::Down;

    MovementState resultState = movementStateFromEvents(oldState, downKeyReleasedEvent);
  
    REQUIRE(resultState.isMovingDown == false);
  }
}
