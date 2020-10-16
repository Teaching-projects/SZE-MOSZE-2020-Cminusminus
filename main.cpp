#include <sys/stat.h>
#include <iostream>
#include "character.h"
#include <string>

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
	  
	  Character* char1 = nullptr;
	  Character* char2 = nullptr;
	  try
	  {
		  char1 = Character::parseUnit(argv[1]);
		  char2 = Character::parseUnit(argv[2]);
	  }
	  catch (const int& fileExist)
	  {
		  std::cout << "First and/or second file doesn't exists.\n";
		  exit(fileExist);
	  }

	  char1->battle(*char2);

	  delete char1;
	  delete char2;
  }
  return 0;
}
