#include <iostream>

#include <SFML/Graphics.hpp>

#include "MovementState.h"
#include "handleEvents.h"
#include "moveShape.h"

int main() {
  //------------------------------------------------------------------------------------------------
  // Window setup
  //------------------------------------------------------------------------------------------------
  
  sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML works!");
  window.setFramerateLimit(60);

  //------------------------------------------------------------------------------------------------
  // Global game state
  //------------------------------------------------------------------------------------------------

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

  while (window.isOpen()) {
    //----------------------------------------------------------------------------------------------
    // Local game state
    //----------------------------------------------------------------------------------------------
    
    // Does creating these things fresh every frame cause some kind of bottleneck? 
    // How could I measure this?
    MovementState newMovementState = g_movementState;
    sf::RectangleShape newRectangle = g_rectangle;

    //----------------------------------------------------------------------------------------------
    // Handle all inputs caught during this frame
    //----------------------------------------------------------------------------------------------
    
    sf::Event event;

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
    // Simulate game state transformation
    //----------------------------------------------------------------------------------------------

    newRectangle = moveBasedOnMovementState(newRectangle, newMovementState);

    //----------------------------------------------------------------------------------------------
    // Draw
    //----------------------------------------------------------------------------------------------
    
    window.clear();
    window.draw(newRectangle);
    window.display();

    //----------------------------------------------------------------------------------------------
    // Mutate global game state
    //----------------------------------------------------------------------------------------------

    g_movementState = newMovementState;
    g_rectangle = newRectangle;
  }

  return 0;
}
