#include <catch2/catch_test_macros.hpp>

#include "Character.h"

TEST_CASE( "addItemToInventory returns a new Character with the item given", "[factorial]" ) {
  Character characterWithOne = Character(1);
  Character newCharacter = characterWithOne.addItemToInventory(2);

  REQUIRE(newCharacter.getItem() == 2);
}
