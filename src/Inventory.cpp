#include "../include/Inventory.hpp"
#include <algorithm>

Inventory::Inventory() : m_items() {}

void Inventory::addItem(std::shared_ptr<Item> item) {
  m_items.push_back(item);
}

void Inventory::removeItem(std::shared_ptr<Item> item) {
  auto it = std::find(m_items.begin(), m_items.end(), item);
  if (it != m_items.end()) {
    m_items.erase(it);
  }
}

bool Inventory::hasItem(std::shared_ptr<Item> item) {
  auto it = std::find(m_items.begin(), m_items.end(), item);
  
  return it != m_items.end();
}

void Inventory::useItem(std::shared_ptr<Item> item) {
  if (!hasItem(item)) return;

  item->use();
}