#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include "character.h"
#include <string>
#include <vector>
#include "JSONParser.h"
#include "characterMaker.h"

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
      CharacterMaker characterMaker;
      JSONParser parser;
		  battle(*characterMaker.createCharacter(parser.parseUnitFromFileName(argv[1])), *characterMaker.createCharacter(parser.parseUnitFromFileName(argv[2])));
	  }
	  catch (const int& ex)
	  {
		  std::cout << "First and/or second file doesn't exists.\n";
		  exit(ex);
	  }	 
  }

  return 0;
}
