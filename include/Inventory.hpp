#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <vector>

#include "Item.hpp"

class Inventory {
public:
  Inventory();
  virtual ~Inventory() = default;

  virtual void addItem(std::shared_ptr<Item> item);
  virtual void removeItem(std::shared_ptr<Item> item);
  virtual bool hasItem(std::shared_ptr<Item> item);
  virtual void useItem(std::shared_ptr<Item> item);

private:
  std::vector<std::shared_ptr<Item>> m_items;
};

#endif
