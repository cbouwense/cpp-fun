#include <iostream>
#include <memory>

#include "../include/Aliases.hpp"
#include "../include/Character.hpp"
#include "../include/Inventory.hpp"
#include "../include/Item.hpp"
#include "../include/Sword.hpp"

int main() {
  U<Character> character = std::make_unique<Character>();
  S<Item> item(new Sword("Sting", 10));

  character->addItemToInventory(item);
  character->useItemFromInventory(item);

  return 0;
}
