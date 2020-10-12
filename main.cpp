#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "player.h"
#include <string>
#include <vector>

void battle(Player& character1, Player& character2){
  
  while(character1.IsAlive() && character2.IsAlive()){

    character1.Attack(character2);
	character1.XPManager(character1);
    if(character2.IsAlive()){
      character2.Attack(character1);
	  character2.XPManager(character2);
    }

  }

  if(character1.IsAlive()){
    std::cout << character1.GetName() << " wins. Remaining HP:" << character1.GetHealth() << ". Level:" << character1.GetLevel() << '\n';
  }
  else{
    std::cout << character2.GetName() << " wins. Remaining HP:" << character2.GetHealth() << ". Level:" << character2.GetLevel() << '\n';
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


static Player* parseUnit(const std::string& fileName){
  std::string name = "";
  int health = 0;
  int damage = 0;

  std::fstream characterDataFile;
  characterDataFile.open(fileName);
 
  std::string line;
  if(characterDataFile.is_open()){
    while (std::getline(characterDataFile, line))
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
    characterDataFile.close();
  }
  else 
  {
	  throw 1;
  }

  return new Player(name, health, damage);
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
		  battle(*parseUnit(argv[1]), *parseUnit(argv[2]));
	  }
	  catch (const int& ex)
	  {
		  std::cout << "First and/or second file doesn't exists.\n";
		  return 1;
	  }	 
  }
  return 0;
}