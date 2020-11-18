#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "character.h"
#include "player.h"
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

TEST(ifstreamTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  std::ifstream character1DataFile;
  character1DataFile.open("units/test_unit_1.json");
  Character* character1 =characterMaker.createCharacter(parser.parseUnitFromStream(&character1DataFile));
  Character* character2 = new Character("Béla",1500000,14, 10.3);

  EXPECT_EQ(*character1, *character2); 
}

TEST(badLineTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromFileName("bad_units/test_unit_badLines.json"));
  Character* character2 = new Character("Timmy",30000,400,10.1);

  EXPECT_EQ(*character1, *character2); 
}

TEST(badSpacingTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromFileName("bad_units/test_unit_badSpacing.json"));
  Character* character2 = new Character("Béla",1500000,500,10.3);

  EXPECT_EQ(*character1, *character2); 
}

TEST(mixedInputsTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromFileName("bad_units/test_unit_mixedInputs.json"));
  Character* character2 = new Character("Tricky Tricky",320,200,10.1);

  EXPECT_EQ(*character1, *character2); 
}
TEST(plusDataWhSpaceTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character1 = characterMaker.createCharacter(parser.parseUnitFromFileName("bad_units/test_unit_plusDataWhSpace.json"));
  Character* character2 = new Character("Tricky Tricky",320,200,10.1);

  EXPECT_EQ(*character1, *character2); 
}

TEST(LVLTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character = new Character("Uzi",1500,140,10.3);
  Player* player = new Player("Timmy",3000,90,10.1);
  player->battle(*character);
  unsigned int expectedLVL = 13;
  EXPECT_EQ(expectedLVL, player->GetLevel()); 
}

TEST(MAXHPTest, checkIfEquals){
  JSONParser parser;
  CharacterMaker characterMaker;
  Character* character = new Character("Uzi",1500,140,10.3);
  Player* player = new Player("Timmy",3000,90,10.1);
  player->battle(*character);
  unsigned int expectedMaxHP = 9414;
  EXPECT_EQ(expectedMaxHP, player->GetMaxHP()); 
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
