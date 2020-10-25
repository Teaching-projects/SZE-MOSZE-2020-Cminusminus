#ifndef CHARACTER_MAKER_H
#define CHARACTER_MAKER_H

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class CharacterMaker{
public:
    std::vector<std::string> splittedString(std::string text, char delimiter);
    Character* createCharacter(const std::string& fileContent);
private:
    void showErrorMessage(std::string message);
};

#endif // CHARACTER_MAKER_H