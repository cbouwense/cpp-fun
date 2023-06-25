#ifndef HANDLEKEYBOARDEVENTS_HPP
#define HANDLEKEYBOARDEVENTS_HPP

#include <SFML/Graphics.hpp>

#include "GameState.h"

//--------------------------------------------------------------------------------------------------
// Public methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] InputState buildNewInputState(const InputState oldState, sf::Event event);

//--------------------------------------------------------------------------------------------------
// Private methods
//--------------------------------------------------------------------------------------------------

[[nodiscard]] InputState newStateOnKeyPressed(const InputState oldState, const sf::Event event);

[[nodiscard]] InputState newStateOnKeyReleased(const InputState oldState, const sf::Event event);

#endif
