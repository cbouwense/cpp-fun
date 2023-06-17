#ifndef CHARACTER_H
#define CHARACTER_H

#include "Inventory.hpp"

class Character {
public:
  Character(Inventory* inventory);
  virtual ~Character();

  virtual void useItemFromInventory(Item item);
  virtual void addItemToInventory(Item item);
  virtual void removeItemFromInventory(Item item);

private:
  Inventory* inventory;
};

#endif
