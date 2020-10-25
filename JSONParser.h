#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class JSONParser{
public:
    Character* parseUnitFromStream(std::ifstream* stream);
    Character* parseUnitFromFileName(const std::string& fileName);
    Character* parseUnitFromContent(const std::string& content);
};

#endif //JSONPARSER_H