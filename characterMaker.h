#ifndef CHARACTER_MAKER_H
#define CHARACTER_MAKER_H

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<map>

class CharacterMaker{
public:
    Character* createCharacter(std::map<std::string, std::string> parsedData);
private:
    void showErrorMessage(std::string message);
};

#endif // CHARACTER_MAKER_H