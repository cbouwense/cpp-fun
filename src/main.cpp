#include <iostream>
#include <memory>

#include "../include/Character.hpp"
#include "../include/Inventory.hpp"
#include "../include/Item.hpp"
#include "../include/Sword.hpp"

using namespace std;

int main() {
  std::unique_ptr<Character> character = std::make_unique<Character>();
  std::shared_ptr<Item> item(new Sword("Sting", 10));

  character->addItemToInventory(item);
  character->useItemFromInventory(item);

  return 0;
}
