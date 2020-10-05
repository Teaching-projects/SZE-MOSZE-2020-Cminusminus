#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "character.h"
#include <string>
#include <vector>

void battle(Character& character1, Character& character2){
  while(character1.IsAlive() && character2.IsAlive()){
    character1.Attack(character2);
    if(character2.IsAlive()){
      character2.Attack(character1);
    }
  }

  if(character1.IsAlive()){
    std::cout << character1.GetName() << " wins. Remaining HP:" << character1.GetHealth() << '\n';
  }
  else{
    std::cout << character2.GetName() << " wins. Remaining HP:" << character2.GetHealth() << '\n';
  }
}

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

static Character* parseUnit(std::fstream* stream){
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

  std::fstream characterDataFile;

  if(characterDataFile.good()){ //file exists (fájlnév szerinti)
    characterDataFile.open(fileNameOrContent);
    return parseUnit(&characterDataFile);
  }
  else //(string szerinti)
  {
    return createCharacter(fileNameOrContent);
  }
}

int main(int argc, char *argv[])
{
  if(argc != 3){
    std::cout << "You have to give me two input files!\n";

    return 1;
  }
  else
  {
	  try
	  {
     /* std::fstream character1DataFile;
      character1DataFile.open(argv[1]);
      std::fstream character2DataFile;
      character2DataFile.open(argv[2]);
      battle(*parseUnit(&character1DataFile), *parseUnit(&character2DataFile));*/

		  battle(*parseUnit(argv[1]), *parseUnit(argv[2]));
	  }
	  catch (const int& ex)
	  {
		  std::cout << "First and/or second file doesn't exists.\n";
		  exit(ex);
	  }	 
  }

  return 0;
}
