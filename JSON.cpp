#include "JSON.h"
#include <map>


std::vector<std::string> JSON::splittedString(std::string text, char delimiter) {
    std::vector<std::string> splittedStrings;
    std::string addString = "";

    for (unsigned int i = 0; i < text.length(); i++) {
        if (text[i] == delimiter) {
            splittedStrings.push_back(addString);
            addString = "";
        }
        else {
            addString += text[i];
        }
    }

    splittedStrings.push_back(addString);

    return splittedStrings;
}

std::map<std::string, std::string> JSON::parse(const std::string text) {
    std::map<std::string, std::string> parsedData;

    for (const auto& line : splittedString(text, '\n'))
    {
        std::vector<std::string> splittedLine = splittedString(line, ':');

        if (splittedLine.front().find("hero") != std::string::npos) {
            std::vector<std::string> hero = splittedString(splittedLine.back(), ',');
            hero[0].erase(hero[0].begin(), hero[0].begin()+2);
            hero[0].erase(hero[0].end()-1, hero[0].end());
            parsedData.insert(std::pair<std::string, std::string>("hero", hero[0]));
        }

        else  if (splittedLine.front().find("monsters") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            monsters[0].erase(monsters[0].begin(), monsters[0].begin() + 2);
            monsters[0].erase(monsters[0].end() - 2, monsters[0].end());
            parsedData.insert(std::pair<std::string, std::string>("monsters", monsters[0]));
        }
    }

    return parsedData;
}

std::map<std::string, std::string> JSON::parseUnitFromStream(std::ifstream* stream) {
    std::string fileContent = "";
    std::string line;

    if (stream->is_open()) {
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

std::map<std::string, std::string> JSON::parseUnitFromFileName(const std::string& fileName) {
    std::ifstream characterDataFile;

    characterDataFile.open(fileName);
    return parseUnitFromStream(&characterDataFile);
}

JSON JSON::parseFromFile(const std::string& fileName)
{
    std::map <std::string, std::string> parsedMap = parseUnitFromFileName(fileName);
    std::map <std::string, std::string> hero; 
    hero.insert(std::pair<std::string,std::string>(parsedMap.find("hero")->first, parsedMap.find("hero")->second));
    std::map <std::string, std::string> monster;
    monster.insert(std::pair<std::string, std::string>(parsedMap.find("monsters")->first, parsedMap.find("monsters")->second));

    return JSON(hero, monster);
    
}

int JSON::count(const std::string& type)
{
    if ((monsters_map.find(type) != monsters_map.end()) || (hero_map.find(type) != hero_map.end()))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}