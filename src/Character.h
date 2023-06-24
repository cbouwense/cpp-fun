#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
  Character();

  Character(const int i);

  ~Character();
  
  Character addItemToInventory(int i) const;

  Character removeItemFromInventory(int i) const;

  void useItemFromInventory() const;

  bool hasItem(const int i) const;

  bool hasNoItems() const;

private:
  int m_int;
};

#endif
