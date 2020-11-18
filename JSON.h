#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<map>

class JSONParser{
	/**
  *\brief A class for parsing json file.
  */
private:
    std::vector<std::string> splittedString(std::string text, char delimiter);
    std::map<std::string, std::string> parse(const std::string text);
public:
///\brief A function to parse data from a filestream.
  ///\param stream The filestream we read.
  ///\return map<string, string>
    std::map<std::string, std::string> parseUnitFromStream(std::ifstream* stream);
	///\brief A function to parse data from file name.
  ///\param fileName The file's name we read.
  ///\return map<string, string>
    std::map<std::string, std::string> parseUnitFromFileName(const std::string& fileName);
	///\brief A function to parse data from content.
  ///\param content The content we read.
  ///\return map<string, string>
    std::map<std::string, std::string> parseUnitFromContent(const std::string& content);
};

#endif //JSONPARSER_H