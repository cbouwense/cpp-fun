#include <iostream>
#include "./Character.h"

Character::Character() {}

Character::~Character() {}

void Character::sayHello() {
  std::cout << "Hello, I am a character" << std::endl;
}

void Character::addItemToInventory() {
  std::cout << "Adding to inventory" << std::endl;
}

void Character::removeItemFromInventory() {
  std::cout << "Removing from inventory" << std::endl;
}

void Character::useItemFromInventory() {
  std::cout << "Using from inventory" << std::endl;
}
