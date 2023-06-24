#ifndef SWORD_H
#define SWORD_H

#include "Item.h"

class Sword : public Item {
public:
  void use() const override;
  
  const std::string getName() const override;

private:
  int m_damage;
  std::string m_name;
};

#endif
