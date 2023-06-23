//------------------------------------------------------------------------------
#ifndef CHARACTER_H
#define CHARACTER_H

//------------------------------------------------------------------------------
class Character {

//------------------------------------------------------------------------------
public:
  Character();

  virtual ~Character();

  virtual void sayHello();
  
  virtual void useItemFromInventory();
  
  virtual void addItemToInventory();
  
  virtual void removeItemFromInventory();

};

#endif
