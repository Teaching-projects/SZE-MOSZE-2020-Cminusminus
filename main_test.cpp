#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "character.h"
#include "characterMaker.h"
#include "JSONParser.h"
#include <string>
#include <vector>
#include <gtest/gtest.h>

TEST(fileNameTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromFileName("units/test_unit_1.json"));
  Character* character2 = new Character("Béla",1500000,14, 10.3);

  EXPECT_EQ(*character1, *character2); 
}

TEST(fileNameTest, checkIfNotEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromFileName("units/test_unit_1.json"));
  Character* character2 = new Character("Béla",1500001,14, 10.3);

  EXPECT_NE(*character1, *character2); 
}

TEST(fileContentTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character1 =characterMaker.createCharacter(parser.parseUnitFromContent("{\n\"name\": \"Béla\",\n\"hp\": 1500000,\n\"dmg\": 14\n\"attackCooldown\": \ 10.3\n}"));
  Character* character2 = new Character("Béla",1500000,14,10.3);

  EXPECT_EQ(*character1, *character2); 
}

TEST(fileContentTest, checkIfNotEquals){
  CharacterMaker characterMaker;
  JSONParser parser;
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromContent("{\n\"name\": \"Béla\",\n\"hp\": 1500000,\n\"dmg\": 14\n\"attackCooldown\": \ 10.3\n}"));
  Character* character2 = new Character("Béla",1500001,14,10.3);

  EXPECT_NE(*character1, *character2); 
}

TEST(ifstreamTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  std::ifstream character1DataFile;
  character1DataFile.open("units/test_unit_1.json");
  Character* character1 =characterMaker.createCharacter(parser.parseUnitFromStream(&character1DataFile));
  Character* character2 = new Character("Béla",1500000,14, 10.3);

  EXPECT_EQ(*character1, *character2); 
}

TEST(ifstreamTest, checkIfNotEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  std::ifstream character1DataFile;
  character1DataFile.open("units/test_unit_1.json");
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromStream(&character1DataFile));
  Character* character2 = new Character("Béla",1500001,14, 10.3);

  EXPECT_NE(*character1, *character2); 
}

TEST(ifstreamTest, checkIfNotEqualsBadHP){
  JSONParser parser;
  CharacterMaker characterMaker;
  std::ifstream character1DataFile;
  character1DataFile.open("bad_units/test_unit_badHP.json");
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromStream(&character1DataFile));
  Character* character2 = new Character("Towelie",70000,1000,10.3);

  EXPECT_NE(*character1, *character2); 
}

TEST(ifstreamTest, checkIfNotEqualsBadDamage){
  JSONParser parser;
  CharacterMaker characterMaker;
  std::ifstream character1DataFile;
  character1DataFile.open("bad_units/test_unit_badDMG.json");
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromStream(&character1DataFile));
  Character* character2 = new Character("Towelie",70000,1000,10.3);

  EXPECT_NE(*character1, *character2); 
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
