#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "character.h"
#include "JSONParser.h"
#include <string>
#include <vector>
#include <gtest/gtest.h>

TEST(fileNameTest, checkIfEqualsGood){
  JSONParser parser;
  Character* character1 = parser.parseUnitFromFileName("units/test_unit_1.json");
  Character* character2 = new Character("Béla",1500000,14);

  EXPECT_EQ(*character1, *character2); 
}

TEST(fileNameTest, checkIfEqualsBad){
  JSONParser parser;
  Character* character1 = parser.parseUnitFromFileName("units/test_unit_1.json");
  Character* character2 = new Character("Béla",1500001,14);

  EXPECT_NE(*character1, *character2); 
}

TEST(fileContentTest, checkIfEqualsGood){
  JSONParser parser;
  Character* character1 = parser.parseUnitFromContent("{\n\"name\": \"Béla\",\n\"hp\": 1500000,\n\"dmg\": 14\n}");
  Character* character2 = new Character("Béla",1500000,14);

  EXPECT_EQ(*character1, *character2); 
}

TEST(fileContentTest, checkIfEqualsBad){
  JSONParser parser;
  Character* character1 = parser.parseUnitFromContent("{\n\"name\": \"Béla\",\n\"hp\": 1500000,\n\"dmg\": 14\n}");
  Character* character2 = new Character("Béla",1500001,14);

  EXPECT_NE(*character1, *character2); 
}

TEST(ifstreamTest, checkIfEqualsGood){
  JSONParser parser;
  std::ifstream character1DataFile;
  character1DataFile.open("units/test_unit_1.json");
  Character* character1 = parser.parseUnitFromStream(&character1DataFile);
  Character* character2 = new Character("Béla",1500000,14);

  EXPECT_EQ(*character1, *character2); 
}

TEST(ifstreamTest, checkIfEqualsBad){
  JSONParser parser;
  std::ifstream character1DataFile;
  character1DataFile.open("units/test_unit_1.json");
  Character* character1 = parser.parseUnitFromStream(&character1DataFile);
  Character* character2 = new Character("Béla",1500001,14);

  EXPECT_NE(*character1, *character2); 
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
