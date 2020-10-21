#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class JSONParser{
private:
    std::vector<std::string> splittedString(std::string text, char delimiter);

    Character* createCharacter(const std::string& fileContent);
public:
    Character* parseUnitFromStream(std::ifstream* stream);
    Character* parseUnitFromFileName(const std::string& fileName);
    Character* parseUnitFromContent(const std::string& content);
};

#endif //JSONPARSER_H