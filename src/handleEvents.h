#ifndef HANDLEKEYBOARDEVENTS_HPP
#define HANDLEKEYBOARDEVENTS_HPP

#include <SFML/Graphics.hpp>

#include "MovementState.h"

[[nodiscard]] MovementState movementStateFromEvents(const MovementState& oldState, sf::Event& event);

[[nodiscard]] MovementState newStateOnKeyPressed(const MovementState& oldState, const sf::Event& event);

[[nodiscard]] MovementState newStateOnKeyReleased(const MovementState& oldState, const sf::Event& event);

#endif
