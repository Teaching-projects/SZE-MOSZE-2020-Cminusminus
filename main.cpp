#include <sys/stat.h>
#include <iostream>
#include "character.h"
#include <string>

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
	  battle(*char1, *char2);
	  delete char1;
	  delete char2;
  }
  return 0;
}
