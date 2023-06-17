#include <iostream>
#include <memory>

#include "../include/Character.hpp"
#include "../include/Inventory.hpp"
#include "../include/Item.hpp"
#include "../include/Sword.hpp"

template <typename T>
using U = std::unique_ptr<T>;

template <typename T>
using S = std::shared_ptr<T>;

int main() {
  U<Character> character = std::make_unique<Character>();
  S<Item> item(new Sword("Sting", 10));

  character->addItemToInventory(item);
  character->useItemFromInventory(item);

  return 0;
}
