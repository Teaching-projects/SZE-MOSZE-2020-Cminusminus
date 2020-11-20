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

std::map<std::string, std::string> JSON::parseh(const std::string text) {
    std::map<std::string, std::string> parsedData;

    for (const auto& line : splittedString(text, '\n'))
    {
        std::vector<std::string> splittedLine = splittedString(line, ':');

        if (splittedLine.front().find("name") != std::string::npos) {
            std::vector<std::string> hero = splittedString(splittedLine.back(), ',');
            hero[0].erase(hero[0].begin(), hero[0].begin() + 2);
            hero[0].erase(hero[0].end() - 1, hero[0].end());
            parsedData.insert(std::pair<std::string, std::string>("name", hero[0]));
        }
        else  if (splittedLine.front().find("base_health_points") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("bhp", monsters[0]));
        }
        else  if (splittedLine.front().find("base_damage") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("bd", monsters[0]));
        }
        else  if (splittedLine.front().find("base_attack_cooldown") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("bac", monsters[0]));
        }
        else  if (splittedLine.front().find("experience_per_level") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("epl", monsters[0]));
        }
        else  if (splittedLine.front().find("health_point_bonus_per_level") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("hpbpl", monsters[0]));
        }
        else  if (splittedLine.front().find("damage_bonus_per_level") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("dbpl", monsters[0]));
        }
        else  if (splittedLine.front().find("cooldown_multiplier_per_level") != std::string::npos) {
            std::vector<std::string> monsters = splittedString(splittedLine.back(), ',');
            parsedData.insert(std::pair<std::string, std::string>("cmpl", monsters[0]));
        }

    }
    return parsedData;


}

std::map<std::string, std::string> JSON::parsem(const std::string text) {
    std::map<std::string, std::string> parsedData;

    for (const auto& line : splittedString(text, ','))
    {
        std::vector<std::string> splittedLine = splittedString(line, ':');

        if (splittedLine.front().find("name") != std::string::npos) {
            std::vector<std::string> hero = splittedString(splittedLine.back(), ',');
            hero[0].erase(hero[0].begin(), hero[0].begin() + 2);
            hero[0].erase(hero[0].end() - 1, hero[0].end());
            parsedData.insert(std::pair<std::string, std::string>("name", hero[0]));

        }
        if (splittedLine.front().find("health_points") != std::string::npos) {
            std::vector<std::string> monst = splittedString(splittedLine.back(), ',');

            parsedData.insert(std::make_pair<std::string, std::string>("hp", (std::string)monst[0]));
        }
        else if (splittedLine.front().find("damage") != std::string::npos) {
            std::vector<std::string> monst = splittedString(splittedLine.back(), ',');

            parsedData.insert(std::pair<std::string, std::string>("dmg", monst[0]));
        }
        else if (splittedLine.front().find("attack_cooldown") != std::string::npos) {
            std::vector<std::string> monst = splittedString(splittedLine.back(), ',');

            parsedData.insert(std::pair<std::string, std::string>("atc", monst[0]));
        }
        else if (splittedLine.front().find("lore") != std::string::npos) {
            std::vector<std::string> monst = splittedString(splittedLine.back(), ',');

            parsedData.insert(std::pair<std::string, std::string>("lore", monst[0]));
        }
        else if (splittedLine.front().find("additional_info") != std::string::npos) {
            std::vector<std::string> monst = splittedString(splittedLine.back(), ',');

            parsedData.insert(std::pair<std::string, std::string>("info", monst[0]));
        }
        else if (splittedLine.front().find("race") != std::string::npos) {

            parsedData.insert(std::pair<std::string, std::string>("race", splittedLine.back()));
        }
    }
    return parsedData;
}

std::map<std::string, std::string> JSON::parseUnitFromStream(std::ifstream* stream) {
    std::string fileContent = "";
    std::string line;
    int lineIndex = 0;
    if (stream->is_open()) {
        while (std::getline(*stream, line))
        {
            fileContent += line + '\n';
        }
        stream->close();
    }
    else
    {
        std::cerr << "Can't open file";
    }

    return parse(fileContent);
}

std::map<std::string, std::string> JSON::parseStreamM(std::ifstream* stream) {
    std::string fileContent = "";
    std::string line;
    int lineIndex = 0;
    if (stream->is_open()) {
        while (std::getline(*stream, line))
        {
            fileContent += line + '\n';
        }
        stream->close();
    }
    else
    {
        std::cerr << "Can't open file";
    }

    return parsem(fileContent);
}

std::map<std::string, std::string> JSON::parseStreamH(std::ifstream* stream) {
    std::string fileContent = "";
    std::string line;
    int lineIndex = 0;
    if (stream->is_open()) {
        while (std::getline(*stream, line))
        {
            fileContent += line + '\n';
        }
        stream->close();
    }
    else
    {
        std::cerr << "Can't open file";
    }

    return parseh(fileContent);
}

std::map<std::string, std::string> JSON::parseUnitFromFileName(const std::string& fileName) {
    std::ifstream characterDataFile;
    if (fileName.find("scenario") != std::string::npos)
    {
        characterDataFile.open(fileName);
        return parseUnitFromStream(&characterDataFile);
    }
    else if (fileName.find("Dark_Wanderer") != std::string::npos)
    {
        characterDataFile.open(fileName);
        return parseStreamH(&characterDataFile);
    }
    else if (fileName.find("Zombie") != std::string::npos || fileName.find("Fallen") != std::string::npos || fileName.find("Blood_Raven") != std::string::npos)
    {
        characterDataFile.open(fileName);
        return parseStreamM(&characterDataFile);
    }
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