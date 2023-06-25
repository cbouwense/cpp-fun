#ifndef BUILD_NEW_COLLISION_STATE_H
#define BUILD_NEW_COLLISION_STATE_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "buildNewCollisionState.h"

CollisionState buildNewCollisionState(const CollisionState oldCollisionState, const sf::RectangleShape rectangle, const sf::RenderWindow& window);

#endif
