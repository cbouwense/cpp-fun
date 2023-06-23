#include <iostream>
#include "Character.h"

int main() {
  Character character = Character(1);
  std::cout << "Character has " << character.inventoryToString() << std::endl;

  Character characterWithItem = character.addItemToInventory(2);
  std::cout << "Character has " << characterWithItem.inventoryToString() << std::endl;

	return 0;
}
