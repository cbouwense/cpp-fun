#ifndef MOVE_SHAPE_HPP
#define MOVE_SHAPE_HPP 

#include <SFML/Graphics.hpp>

#include "GameState.h"

sf::RectangleShape moveBasedOnMovementState(sf::RectangleShape rectangle, const MovementState movementState);

#endif
