#ifndef CHARACTER_H
#define CHARACTER_H

#include "Inventory.hpp"
#include <memory>

class Character {
public:
  Character();
  virtual ~Character();

  virtual void useItemFromInventory(std::shared_ptr<Item> item);
  virtual void addItemToInventory(std::shared_ptr<Item> item);
  virtual void removeItemFromInventory(std::shared_ptr<Item> item);

private:
  std::unique_ptr<Inventory> inventory;
};

#endif
