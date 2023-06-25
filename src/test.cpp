#include <catch2/catch_test_macros.hpp>

#include "GameState.h"

#include "buildNewCollisionState.h"
#include "handleEvents.h"

TEST_CASE("buildNewInputState") {

  //------------------------------------------------------------------------------------------------
  // Keyboard press
  //------------------------------------------------------------------------------------------------
  SECTION("When the event is a keyboard press right key, the resulting state should have isPressingRight set to true") {
    InputState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event rightKeyPressedEvent;
    rightKeyPressedEvent.type = sf::Event::KeyPressed;
    rightKeyPressedEvent.key.code = sf::Keyboard::Right;

    InputState resultState = buildNewInputState(oldState, rightKeyPressedEvent);
  
    REQUIRE(resultState.isPressingRight == true);
  }

  SECTION("When the event is a keyboard press left key, the resulting state should have isPressingLeft set to true") {
    InputState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event leftKeyPressedEvent;
    leftKeyPressedEvent.type = sf::Event::KeyPressed;
    leftKeyPressedEvent.key.code = sf::Keyboard::Left;

    InputState resultState = buildNewInputState(oldState, leftKeyPressedEvent);
  
    REQUIRE(resultState.isPressingLeft == true);
  }

  SECTION("When the event is a keyboard press up key, the resulting state should have isPressingUp set to true") {
    InputState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event upKeyPressedEvent;
    upKeyPressedEvent.type = sf::Event::KeyPressed;
    upKeyPressedEvent.key.code = sf::Keyboard::Up;

    InputState resultState = buildNewInputState(oldState, upKeyPressedEvent);
  
    REQUIRE(resultState.isPressingUp == true);
  }

  SECTION("When the event is a keyboard press down key, the resulting state should have isPressingDown set to true") {
    InputState oldState = {
      false,
      false,
      false,
      false
    };

    sf::Event downKeyPressedEvent;
    downKeyPressedEvent.type = sf::Event::KeyPressed;
    downKeyPressedEvent.key.code = sf::Keyboard::Down;

    InputState resultState = buildNewInputState(oldState, downKeyPressedEvent);
  
    REQUIRE(resultState.isPressingDown == true);
  }

  //------------------------------------------------------------------------------------------------
  // Keyboard release
  //------------------------------------------------------------------------------------------------
  SECTION("When the event is a keyboard release right key, the resulting state should have isPressingRight set to false") {
    InputState oldState = {
      false,
      true,
      false,
      false
    };

    sf::Event rightKeyReleasedEvent;
    rightKeyReleasedEvent.type = sf::Event::KeyReleased;
    rightKeyReleasedEvent.key.code = sf::Keyboard::Right;

    InputState resultState = buildNewInputState(oldState, rightKeyReleasedEvent);
  
    REQUIRE(resultState.isPressingRight == false);
  }

  SECTION("When the event is a keyboard release left key, the resulting state should have isPressingLeft set to false") {
    InputState oldState = {
      false,
      true,
      false,
      false
    };

    sf::Event leftKeyReleasedEvent;
    leftKeyReleasedEvent.type = sf::Event::KeyReleased;
    leftKeyReleasedEvent.key.code = sf::Keyboard::Left;

    InputState resultState = buildNewInputState(oldState, leftKeyReleasedEvent);
  
    REQUIRE(resultState.isPressingLeft == false);
  }

  SECTION("When the event is a keyboard release up key, the resulting state should have isPressingUp set to false") {
    InputState oldState = {
      false,
      false,
      true,
      false
    };

    sf::Event upKeyReleasedEvent;
    upKeyReleasedEvent.type = sf::Event::KeyReleased;
    upKeyReleasedEvent.key.code = sf::Keyboard::Up;

    InputState resultState = buildNewInputState(oldState, upKeyReleasedEvent);
  
    REQUIRE(resultState.isPressingUp == false);
  }

  SECTION("When the event is a keyboard release down key, the resulting state should have isPressingDown set to false") {
    InputState oldState = {
      false,
      false,
      false,
      true
    };

    sf::Event downKeyReleasedEvent;
    downKeyReleasedEvent.type = sf::Event::KeyReleased;
    downKeyReleasedEvent.key.code = sf::Keyboard::Down;

    InputState resultState = buildNewInputState(oldState, downKeyReleasedEvent);
  
    REQUIRE(resultState.isPressingDown == false);
  }
}

TEST_CASE("buildNewCollisionState") {
  SECTION("When the rectangle is at the top left corner of the window, the resulting state should have isCollidingLeft and isCollidingTop set to true") {
    CollisionState oldState = {
      false,
      false,
      false,
      false
    };

    sf::RectangleShape rectangle;
    rectangle.setPosition(0.0f, 0.0f);

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Test");

    CollisionState resultState = buildNewCollisionState(oldState, rectangle, window);

    REQUIRE(resultState.isCollidingLeft == true);
    REQUIRE(resultState.isCollidingTop == true);
  }

  SECTION("When the rectangle is at the top right corner of the window, the resulting state should have isCollidingRight and isCollidingTop set to true") {
    CollisionState oldState = {
      false,
      false,
      false,
      false
    };

    sf::RectangleShape rectangle;
    rectangle.setPosition(800.0f, 0.0f);

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Test");

    CollisionState resultState = buildNewCollisionState(oldState, rectangle, window);

    REQUIRE(resultState.isCollidingRight == true);
    REQUIRE(resultState.isCollidingTop == true);
  }

  SECTION("When the rectangle is at the bottom left corner of the window, the resulting state should have isCollidingLeft and isCollidingBottom set to true") {
    CollisionState oldState = {
      false,
      false,
      false,
      false
    };

    sf::RectangleShape rectangle;
    rectangle.setPosition(0.0f, 600.0f);

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Test");

    CollisionState resultState = buildNewCollisionState(oldState, rectangle, window);

    REQUIRE(resultState.isCollidingLeft == true);
    REQUIRE(resultState.isCollidingBottom == true);
  }

  SECTION("When the rectangle is at the bottom right corner of the window, the resulting state should have isCollidingRight and isCollidingBottom set to true") {
    CollisionState oldState = {
      false,
      false,
      false,
      false
    };

    sf::RectangleShape rectangle;
    rectangle.setPosition(800.0f, 600.0f);

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Test");

    CollisionState resultState = buildNewCollisionState(oldState, rectangle, window);

    REQUIRE(resultState.isCollidingRight == true);
    REQUIRE(resultState.isCollidingBottom == true);
  }
}