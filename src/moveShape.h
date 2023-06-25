#ifndef MOVE_SHAPE_H
#define MOVE_SHAPE_H 

#include <SFML/Graphics.hpp>

#include "GameState.h"

sf::RectangleShape moveBasedOnMovementState(sf::RectangleShape rectangle, const MovementState movementState);

#endif
