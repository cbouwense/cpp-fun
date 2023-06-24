#include <catch2/catch_test_macros.hpp>

#include "Character.h"

TEST_CASE("a character created without a specific item will not start with any items") {
  Character character = Character();

  REQUIRE(character.hasNoItems());
}

TEST_CASE("you can add an item to a character's inventory") {
  Character characterWithOne = Character(1);
  Character resultCharacter = characterWithOne.addItemToInventory(2);

  REQUIRE(resultCharacter.hasItem(2));
}

TEST_CASE("when a character does not have the item requested to be removed then it will not change its item") {
  Character characterWithOne = Character(1);
  Character resultCharacter = characterWithOne.removeItemFromInventory(2);

  REQUIRE(resultCharacter.hasItem(1));
}

TEST_CASE("when a character is requested to remove an item it has it will report not having it afterwards") {
  Character characterWithOne = Character(1);
  Character resultCharacter = characterWithOne.removeItemFromInventory(1);

  REQUIRE(resultCharacter.hasItem(1) == false);
}

TEST_CASE("when a character is requested to remove an item it has it will report having no items afterwards") {
  Character characterWithOne = Character(1);
  Character resultCharacter = characterWithOne.removeItemFromInventory(1);

  REQUIRE(resultCharacter.hasNoItems());
}
