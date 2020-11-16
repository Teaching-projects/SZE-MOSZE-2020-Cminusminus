#include <sys/stat.h>
#include <iostream>
#include "player.h"
#include "character.h"
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  if(argc != 3){
    std::cout << "You have to give me two input files!\n";

    return 1;
  }
  else
  {

	  JSONParser parser;
	  CharacterMaker characterMaker;
	  Character* p1;
	  Character* p2;
	  try
	  {
		  
		  p1 = characterMaker.createCharacter(parser.parseUnitFromFileName(argv[1]));
		  p2 = characterMaker.createCharacter(parser.parseUnitFromFileName(argv[2]));

	  }
	  catch (const int& ex)
	  {
		  std::cout << "First and/or second file doesn't exists.\n";
		  return 1;
	  }

	  p1->battle(*p2);
  }
  
  return 0;
}