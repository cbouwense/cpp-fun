//------------------------------------------------------------------------------
#include <algorithm>
#include "Inventory.h"

//------------------------------------------------------------------------------
Inventory::Inventory() : m_items() {}

//------------------------------------------------------------------------------
void Inventory::addItem(Item* item) {
  m_items.push_back(item);
}

//------------------------------------------------------------------------------
void Inventory::removeItem(Item* item) {
  auto it = std::find(m_items.begin(), m_items.end(), item);
  if (it != m_items.end()) {
    m_items.erase(it);
  }
}

//------------------------------------------------------------------------------
bool Inventory::hasItem(Item* item) {
  auto it = std::find(m_items.begin(), m_items.end(), item);
  
  return it != m_items.end();
}

//------------------------------------------------------------------------------
void Inventory::useItem(Item* item) {
  if (!hasItem(item)) return;

  item->use();
}
