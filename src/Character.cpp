#include <iostream>

#include "../include/Character.hpp"

Character::Character() {
  this->inventory = std::make_unique<Inventory>();
}

Character::~Character() {}

void Character::addItemToInventory(std::shared_ptr<Item> item) {
  std::cout << "Adding " << item->getName() << " to inventory" << std::endl;
  inventory->addItem(item);
}

void Character::removeItemFromInventory(std::shared_ptr<Item> item) {
  std::cout << "Removing " << item->getName() << " from inventory" << std::endl;
  inventory->removeItem(item);
}

void Character::useItemFromInventory(std::shared_ptr<Item> item) {
  std::cout << "Using " << item->getName() << " from inventory" << std::endl;
  inventory->useItem(item);
}
