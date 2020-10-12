#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "character.h"
#include <string>
#include <vector>

/**
*\brief A function to simulate the battle of two given characters. 
*\param character1 The first character.
*\param character2 The second character.
*/
void battle(Character& character1, Character& character2){

	
	character1.Attack(character2);
	character2.Attack(character1);
	double temp1 = character1.GetAttackCooldown();
	double temp2 = character2.GetAttackCooldown();

	while (character1.IsAlive() && character2.IsAlive())
	{
		if (temp1 >= temp2)
		{
			temp1 -= temp2;
			temp2 = 0;
		}
		else
		{
			temp2 -= temp1;
			temp1 = 0;
			
		}

		if ((temp1==0) && (temp2!=0))
		{
			character1.Attack(character2);
			temp1 = character1.GetAttackCooldown();
		}
		else if ((temp2==0)&&(temp1!=0))
		{
			character2.Attack(character1);
			temp2 = character2.GetAttackCooldown();
		}
		else if ((temp1==0) && (temp2==0))
		{
			character1.Attack(character2);
			if (character2.IsAlive())
			{
				character2.Attack(character1);
			}
			else
			{
				break;
			}
			temp1 = character1.GetAttackCooldown();
			temp2 = character2.GetAttackCooldown();
		}

	}

  if(character1.IsAlive()){
    std::cout << character1.GetName() << " wins. Remaining HP:" << character1.GetHealth() << '\n';
  }
  else{

    std::cout << character2.GetName() << " wins. Remaining HP:" << character2.GetHealth() << '\n';
  }
}

/**
*\brief 
*\param text 
*\param delimiter
*\return splttedStrings
*/
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


static Character* parseUnit(const std::string& fileName){
  std::string name = "";
  int health = 0;
  int damage = 0;
  double attackCooldown = 0;

  std::fstream characterDataFile;
  characterDataFile.open(fileName);
 
  std::string line;
  int lineIndex = 0;
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
	  else  if (splittedLine.front().find("attackCooldown") != std::string::npos) {
		  std::string timerInput = splittedLine.back();
		  attackCooldown = std::stod(timerInput);
	  }
    }
    characterDataFile.close();
  }
  else 
  {
	  throw 1;
  }

  return new Character(name, health, damage, attackCooldown);
}

/**
*\brief The main function of the program.
*\param argc The count of the command line arguments.
*\param argv A vector array containing the command lines.
*\return 0 or 1
*\exception fileExist It throws an exception if one of the files doesn't exists.
*/
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
	  catch (const int& fileExist)
	  {
		  std::cout << "First and/or second file doesn't exists.\n";
		  exit(fileExist);
	  }	 
  }
  return 0;
}
