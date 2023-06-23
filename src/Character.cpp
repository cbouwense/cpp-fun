#include <iostream>
#include "./Character.h"

Character Character::addItemToInventory(int i) {
  std::cout << "Adding to inventory" << std::endl;
  return Character(i);
}

void Character::removeItemFromInventory() {
  std::cout << "Removing from inventory" << std::endl;
}

void Character::useItemFromInventory() {
  std::cout << "Using from inventory" << std::endl;
}

std::string Character::inventoryToString() {
  return std::to_string(this->m_int);
}

int Character::getItem() {
  return this->m_int;
}