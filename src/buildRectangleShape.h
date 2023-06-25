#ifndef BUILD_RECTANGLE_SHAPE_H
#define BUILD_RECTANGLE_SHAPE_H 

#include <SFML/Graphics.hpp>

#include "GameState.h"

sf::RectangleShape buildRectangleShape(sf::RectangleShape rectangle, const MovementState movementState, const float deltaTime);

#endif
