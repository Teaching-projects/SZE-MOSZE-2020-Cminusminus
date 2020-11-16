#ifndef CHARACTER_MAKER_H
#define CHARACTER_MAKER_H

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<map>

class CharacterMaker{
	/**
  *\brief A helper class to create a character.
  *\param parsedData the data which we parse.
  *\return Character*
  */
public:
    Character* createCharacter(std::map<std::string, std::string> parsedData);
private:
    void showErrorMessage(std::string message);
};

#endif // CHARACTER_MAKER_H