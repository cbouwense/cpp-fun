#include <iostream>
#include <string>
#include "Character.h"

//--------------------------------------------------------------------------------------------------
Character::Character() : m_int(0) {}

//--------------------------------------------------------------------------------------------------
Character::Character(const int i) : m_int(i) {} 

//--------------------------------------------------------------------------------------------------
Character::~Character() {}

//--------------------------------------------------------------------------------------------------
Character Character::addItemToInventory(const int i) const {
  if (hasItem(i)) return *this;

  return Character(i);
}

//--------------------------------------------------------------------------------------------------
Character Character::removeItemFromInventory(const int i) const {
  if (!hasItem(i)) return *this;

  return Character();
}

//--------------------------------------------------------------------------------------------------
void Character::useItemFromInventory() const {
  std::cout << "Using from inventory" << std::endl;
}

//--------------------------------------------------------------------------------------------------
bool Character::hasItem(const int i) const {
  return this->m_int == i;
}

//--------------------------------------------------------------------------------------------------
bool Character::hasNoItems() const {
  return this->m_int == 0;
}
