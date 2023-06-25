#include <SFML/Graphics.hpp>

#include "handleKeyboardEvents.h"

// It would be nice if we could actually have a pure function instead of moving the rectangle in place.
void moveBasedOnMovementState(sf::RectangleShape& rectangle, const MovementState& movementState) {
  const float speed = 5.0f;

  if (movementState.isMovingRight) {
    rectangle.move(speed, 0.f);
  }

  if (movementState.isMovingLeft) {
    rectangle.move(-speed, 0.f);
  }

  if (movementState.isMovingUp) {
    rectangle.move(0.f, -speed);
  }

  if (movementState.isMovingDown) {
    rectangle.move(0.f, speed);
  }
}

int main() {
  sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML works!");

  sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
  rectangle.setFillColor(sf::Color::Red);
  rectangle.setPosition(100.f, 100.f);

  MovementState g_movementState = {
    false,
    false,
    false,
    false
  };  

  window.setFramerateLimit(60);

  while (window.isOpen()) {
    sf::Event event;

    // Local movement state that will be constructed based on events.
    MovementState newMovementState = g_movementState;

    //----------------------------------------------------------------------------------------------
    // Handle all inputs caught during this frame
    //----------------------------------------------------------------------------------------------
    
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.key.code == sf::Keyboard::Escape) {
        window.close();
      }

      newMovementState = movementStateFromEvents(newMovementState, event);
    }

    //----------------------------------------------------------------------------------------------
    // Simulate game state
    //----------------------------------------------------------------------------------------------

    moveBasedOnMovementState(rectangle, newMovementState);

    //----------------------------------------------------------------------------------------------
    // Draw
    //----------------------------------------------------------------------------------------------
    
    window.clear();
    window.draw(rectangle);
    window.display();

    //----------------------------------------------------------------------------------------------
    // Mutate global game state
    //----------------------------------------------------------------------------------------------

    g_movementState = newMovementState;
  }

  return 0;
}
