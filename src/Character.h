#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
  Character(int i) : m_int(i) {}

  ~Character() = default;
  
  Character addItemToInventory(int i);

  void useItemFromInventory();
  
  void removeItemFromInventory();

  std::string inventoryToString();

  int getItem();

private:
  int m_int;
};

#endif
