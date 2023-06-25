#ifndef HANDLEKEYBOARDEVENTS_HPP
#define HANDLEKEYBOARDEVENTS_HPP

#include <SFML/Graphics.hpp>

#include "MovementState.h"

[[nodiscard]] MovementState newStateOnKeyPressed(sf::Event& event, const MovementState& state);

[[nodiscard]] MovementState newStateOnKeyReleased(sf::Event& event, const MovementState& state);

#endif
