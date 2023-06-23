#ifndef SWORD_H
#define SWORD_H

#include "Item.hpp"

class Sword : public Item {
public:
  Sword(const std::string& name, int damage);
  ~Sword() = default;

  void use() override;
  const std::string getName() override;

private:
  int m_damage;
  std::string m_name;
};

#endif