#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item {
public:
  virtual ~Item() = default;

  // TODO: How should we handle failure to use an item?
  virtual void use() = 0;
  virtual const std::string getName() = 0;
};

#endif
