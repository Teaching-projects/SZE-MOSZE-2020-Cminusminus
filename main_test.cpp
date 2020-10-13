#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "character.h"
#include <string>
#include <vector>
#include <gtest/gtest.h>

std::vector<std::string> splittedString(std::string text, char delimiter){
  std::vector<std::string> splittedStrings;
  std::string addString = "";

  for(unsigned int i = 0; i < text.length(); i++){
    if(text[i] == delimiter){
      splittedStrings.push_back(addString);
      addString = "";
    }
    else{
      addString += text[i];
    }
  }

  splittedStrings.push_back(addString);

  return splittedStrings;
}

static Character* createCharacter(const std::string& fileContent){
  std::string name = "";
  int health = 0;
  int damage = 0;

  for(const auto& line : splittedString(fileContent, '\n'))
  {
    std::vector<std::string> splittedLine = splittedString(line, ':');
    if(splittedLine.front().find("name") != std::string::npos){
      name = splittedLine.back();
      name = name.substr(2, name.length() - 4);
    }
    else  if(splittedLine.front().find("hp") != std::string::npos){
      std::string inputHealth =  splittedLine.back();
      inputHealth = inputHealth.substr(0, inputHealth.length()-1);
      health = std::stoi(inputHealth);
    }
    else  if(splittedLine.front().find("dmg") != std::string::npos){
      std::string damageHealth =  splittedLine.back();
      damage = std::stoi(damageHealth);
    }
  }

  return new Character(name, health, damage);
}

static Character* parseUnit(std::ifstream* stream){
  std::string fileContent = "";
  std::string line;
  int lineIndex = 0;
  if(stream->is_open()){
    while (std::getline(*stream, line))
    {
      fileContent += line + '\n';
    }
    stream->close();
  }
  else 
  {
	  throw 1;
  }

  return createCharacter(fileContent);
}

static Character* parseUnit(const std::string& fileNameOrContent){
  std::string name = "";
  int health = 0;
  int damage = 0;

  std::ifstream characterDataFile;

  if(FILE *file = fopen(fileNameOrContent.c_str(), "r")){ //file exists (fájlnév szerinti)
    characterDataFile.open(fileNameOrContent);
    return parseUnit(&characterDataFile);
  }
  else //(string szerinti)
  {
    return createCharacter(fileNameOrContent);
  }
}


TEST(fileNameTest, checkIfEquals){
  Character* character1 = parseUnit("units/test_unit_1.json");
  Character* character2 = new Character("Béla",1500000,14);

  EXPECT_EQ(*character1, *character2); 
}

TEST(fileContentTest, checkIfEquals){
  Character* character1 = parseUnit("{\n\"name\": \"Béla\",\n\"hp\": 1500000,\n\"dmg\": 14\n}");
  Character* character2 = new Character("Béla",1500000,14);

  EXPECT_EQ(*character1, *character2); 
}

TEST(ifstreamTest, checkIfEquals){
  std::ifstream character1DataFile;
  character1DataFile.open("units/test_unit_1.json");
  Character* character1 = parseUnit(&character1DataFile);
  Character* character2 = new Character("Béla",1500000,14);

  EXPECT_EQ(*character1, *character2); 
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
