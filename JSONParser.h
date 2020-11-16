#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<map>

class JSONParser{
private:
    std::vector<std::string> splittedString(std::string text, char delimiter);
    std::map<std::string, std::string> parse(const std::string text);
public:
    std::map<std::string, std::string> parseUnitFromStream(std::ifstream* stream);
    std::map<std::string, std::string> parseUnitFromFileName(const std::string& fileName);
    std::map<std::string, std::string> parseUnitFromContent(const std::string& content);
};

#endif //JSONPARSER_H