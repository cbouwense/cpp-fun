#include <SFML/Graphics.hpp>

#include "handleKeyboardEvents.h"

void moveBasedOnMovementState(sf::RectangleShape& rectangle, const MovementState& movementState) {
  if (movementState.isMovingRight) {
    rectangle.move(0.1f, 0.f);
  }

  if (movementState.isMovingLeft) {
    rectangle.move(-0.1f, 0.f);
  }

  if (movementState.isMovingUp) {
    rectangle.move(0.f, -0.1f);
  }

  if (movementState.isMovingDown) {
    rectangle.move(0.f, 0.1f);
  }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML works!");

    sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(100.f, 100.f);

    MovementState movementState = {
      false,
      false,
      false,
      false
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
              window.close();
            }

            if (event.key.code == sf::Keyboard::Escape) {
              window.close();
            }

            movementState = newStateOnKeyPressed(event, movementState);
            movementState = newStateOnKeyReleased(event, movementState);
        }

        moveBasedOnMovementState(rectangle, movementState);

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
