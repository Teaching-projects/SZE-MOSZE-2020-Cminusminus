#include <sys/stat.h>
#include <iostream>
#include "player.h"
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
	 
	  Player *p1 = nullptr;
	  Player *p2 = nullptr;
	  try
	  {
		  p1 = static_cast<Player*>(Character::parseUnit(argv[2]));
		  p2 = static_cast<Player*>(Character::parseUnit(argv[1]));
		  
		  std::cout << p1 << " " << &p1 << std::endl;
		  std::cout << p2 << " " << &p2 << std::endl;

	  }
	  catch (const int& ex)
	  {
		  std::cout << "First and/or second file doesn't exists.\n";
		  return 1;
	  }
	  p1->battle(*p2);
	  delete p1;
	  delete p2;
	  
  }
  
  return 0;
}