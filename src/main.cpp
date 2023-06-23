#include <iostream>
#include "./Character.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
    
	Character character;
	character.sayHello();
  character.addItemToInventory();
	
	return 0;
}
