//------------------------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H

//------------------------------------------------------------------------------
#include <memory>
#include <vector>
#include "Item.hpp"

//------------------------------------------------------------------------------
class Inventory {

//------------------------------------------------------------------------------
public:
  Inventory();
  
  virtual ~Inventory() = default;

  virtual void addItem(Item* item);
  
  virtual void removeItem(Item* item);
  
  virtual bool hasItem(Item* item);
  
  virtual void useItem(Item* item);

//------------------------------------------------------------------------------
private:
  std::vector<Item*> m_items;
};

#endif
