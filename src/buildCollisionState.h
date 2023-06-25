#ifndef BUILD_COLLISION_STATE_H
#define BUILD_COLLISION_STATE_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "buildCollisionState.h"

CollisionState buildCollisionState(const CollisionState oldCollisionState, const sf::RectangleShape rectangle, const sf::RenderWindow& window);

#endif
