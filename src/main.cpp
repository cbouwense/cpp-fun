#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "handleEvents.h"
#include "moveShape.h"
#include "buildNewCollisionState.h"

MovementState buildNewMovementState(const MovementState oldMovementState, const InputState inputState, const CollisionState collisionState) {
  MovementState newMovementState = oldMovementState;

  newMovementState.isMovingUp = inputState.isPressingUp && !collisionState.isCollidingTop;
  newMovementState.isMovingRight = inputState.isPressingRight && !collisionState.isCollidingRight;
  newMovementState.isMovingDown = inputState.isPressingDown && !collisionState.isCollidingBottom;
  newMovementState.isMovingLeft = inputState.isPressingLeft && !collisionState.isCollidingLeft;

  return newMovementState;
}

int main() {
  //------------------------------------------------------------------------------------------------
  // Window setup
  //------------------------------------------------------------------------------------------------
  
  sf::RenderWindow g_window(sf::VideoMode(1024, 1024), "SFML works!");
  g_window.setFramerateLimit(60);

  //------------------------------------------------------------------------------------------------
  // Global game state
  //------------------------------------------------------------------------------------------------

  InputState g_inputState = {
    false,
    false,
    false,
    false
  };

  CollisionState g_collisionState = {
    false,
    false,
    false,
    false
  };

  MovementState g_movementState = {
    false,
    false,
    false,
    false
  };

  sf::RectangleShape g_rectangle(sf::Vector2f(100.f, 100.f));
  g_rectangle.setFillColor(sf::Color::Red);
  g_rectangle.setPosition(100.f, 100.f);

  //------------------------------------------------------------------------------------------------
  // Game loop
  //------------------------------------------------------------------------------------------------

  while (g_window.isOpen()) {
    //----------------------------------------------------------------------------------------------
    // Local game state
    //----------------------------------------------------------------------------------------------
    
    // Does creating these things fresh every frame cause some kind of bottleneck?
    // How could I measure this?
    CollisionState newCollisionState = g_collisionState;
    InputState newInputState = g_inputState;
    MovementState newMovementState = g_movementState;
    sf::RectangleShape newRectangle = g_rectangle;

    //----------------------------------------------------------------------------------------------
    // Handle all inputs caught during this frame
    //----------------------------------------------------------------------------------------------
    
    sf::Event event;

    // TODO: how do I clamp this to one frame?
    while (g_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        g_window.close();
      }

      if (event.key.code == sf::Keyboard::Escape) {
        g_window.close();
      }

      newInputState = buildNewInputState(newInputState, event);
      newCollisionState = buildNewCollisionState(newCollisionState, newRectangle, g_window);
      newMovementState = buildNewMovementState(newMovementState, newInputState, newCollisionState);
    }

    //----------------------------------------------------------------------------------------------
    // Simulate game state transformation
    //----------------------------------------------------------------------------------------------

    newRectangle = moveBasedOnMovementState(newRectangle, newMovementState);

    // Clear stdout
    std::cout << "\033[2J\033[1;1H";

    // Print out states
    std::cout << "newCollisionState: " << newCollisionState.isCollidingTop << newCollisionState.isCollidingRight  << newCollisionState.isCollidingBottom << newCollisionState.isCollidingLeft << std::endl;
    std::cout << "newMovementState: " << newMovementState.isMovingUp << newMovementState.isMovingRight << newMovementState.isMovingDown << newMovementState.isMovingLeft << std::endl;
    std::cout << "newInputState: " << newInputState.isPressingUp << newInputState.isPressingRight << newInputState.isPressingDown << newInputState.isPressingLeft << std::endl;
    std::cout << "newRectangle: " << newRectangle.getPosition().x << ", " << newRectangle.getPosition().y << std::endl;

    //----------------------------------------------------------------------------------------------
    // Draw
    //----------------------------------------------------------------------------------------------
    
    g_window.clear();
    g_window.draw(newRectangle);
    g_window.display();

    //----------------------------------------------------------------------------------------------
    // Mutate global game state
    //----------------------------------------------------------------------------------------------

    g_collisionState = newCollisionState;
    g_inputState = newInputState;
    g_movementState = newMovementState;
    g_rectangle = newRectangle;
  }

  return 0;
}
