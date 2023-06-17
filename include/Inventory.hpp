#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.hpp"

class Inventory {
public:
  virtual void addItem(Item item) = 0;
  virtual void removeItem(Item item) = 0;
};

#endif
