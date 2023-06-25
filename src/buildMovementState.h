#ifndef BUILD_MOVEMENT_STATE_H
#define BUILD_MOVEMENT_STATE_H

#include "GameState.h"

MovementState buildMovementState(const MovementState oldMovementState, const InputState inputState, const CollisionState collisionState);

#endif
