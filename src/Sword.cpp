#include <iostream>

#include "../include/Sword.hpp"

Sword::Sword(const std::string& name, int damage) : m_name(name), m_damage(damage) {}

void Sword::use() {
  std::cout << "Swinging sword for " << m_damage << " damage" << std::endl;
}

const std::string Sword::getName() {
  return m_name;
}