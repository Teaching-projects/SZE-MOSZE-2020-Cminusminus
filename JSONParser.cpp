#include "JSONParser.h"
#include "character.h"
#include "characterMaker.h"
#include <map>


std::vector<std::string> JSONParser::splittedString(std::string text, char delimiter){
    std::vector<std::string> splittedStrings;
    std::string addString = "";

    for(unsigned int i = 0; i < text.length(); i++){
        if(text[i] == delimiter){
        splittedStrings.push_back(addString);
        addString = "";
        }
        else{
        addString += text[i];
        }
    }

    splittedStrings.push_back(addString);

    return splittedStrings;
}

std::map<std::string, std::string> JSONParser::parse(const std::string text){
    std::map<std::string, std::string> parsedData;

    for(const auto& line : splittedString(text, '\n'))
    {
        std::vector<std::string> splittedLine = splittedString(line, ':');

        if(splittedLine.front().find("name") != std::string::npos){
            std::vector<std::string> name = splittedString(splittedLine.back(), '"');
            parsedData.insert(std::pair<std::string, std::string>("name", name[1]));
        }
        else  if(splittedLine.front().find("hp") != std::string::npos){
            std::vector<std::string> health = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("health", health[0]));
        }
        else  if(splittedLine.front().find("dmg") != std::string::npos){
            parsedData.insert(std::pair<std::string, std::string>("damage", splittedLine.back()));
        }
        else  if (splittedLine.front().find("acd") != std::string::npos) {
            parsedData.insert(std::pair<std::string, std::string>("attackCooldown", splittedLine.back()));
        }
    }

    return parsedData;
}

std::map<std::string, std::string> JSONParser::parseUnitFromStream(std::ifstream* stream){
    std::string fileContent = "";
    std::string line;
    int lineIndex = 0;
    if(stream->is_open()){
        while (std::getline(*stream, line))
        {
            fileContent += line + '\n';
        }
        stream->close();
    }
    else 
    {
        throw 1;
    }

    return parse(fileContent);
}

std::map<std::string, std::string> JSONParser::parseUnitFromFileName(const std::string& fileName){
    std::ifstream characterDataFile;

    characterDataFile.open(fileName);
    return parseUnitFromStream(&characterDataFile);
}

std::map<std::string, std::string> JSONParser::parseUnitFromContent(const std::string& content){
    return parse(content);
}
