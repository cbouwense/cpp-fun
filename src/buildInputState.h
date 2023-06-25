#ifndef BUILD_INPUT_STATE_H
#define BUILD_INPUT_STATE_H

#include <SFML/Graphics.hpp>

#include "GameState.h"

//--------------------------------------------------------------------------------------------------
// Public methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] InputState buildInputState(const InputState oldState, sf::Event event);

//--------------------------------------------------------------------------------------------------
// Private methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] InputState newStateOnKeyPressed(const InputState oldState, const sf::Event event);

[[nodiscard]] InputState newStateOnKeyReleased(const InputState oldState, const sf::Event event);

#endif
