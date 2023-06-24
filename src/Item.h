#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item {
public:
  virtual ~Item() {}

  // TODO: How should we handle failure to use an item?
  virtual void use() const = 0;
  
  virtual const std::string getName() const = 0;
};

#endif
