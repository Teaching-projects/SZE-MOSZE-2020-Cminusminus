#include "JSONParser.h"
#include "character.h"

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

Character* JSONParser::createCharacter(const std::string& fileContent){
    std::string name = "";
    int health = 0;
    int damage = 0;

    for(const auto& line : splittedString(fileContent, '\n'))
    {
        std::vector<std::string> splittedLine = splittedString(line, ':');
        if(splittedLine.front().find("name") != std::string::npos){
            name = splittedLine.back();
            std::vector<std::string> almostName = splittedString(name, '"');
            name = almostName[1];
        }
        else  if(splittedLine.front().find("hp") != std::string::npos){
            std::string inputHealth =  splittedLine.back();
            std::vector<std::string> almostHealth = splittedString(inputHealth, ',');
            health = std::stoi(almostHealth[0]);
        }
        else  if(splittedLine.front().find("dmg") != std::string::npos){
            std::string damageHealth =  splittedLine.back();
            damage = std::stoi(damageHealth);
        }
    }

    return new Character(name, health, damage);
}


Character* JSONParser::parseUnitFromStream(std::ifstream* stream){
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

    return createCharacter(fileContent);
}

Character* JSONParser::parseUnitFromFileName(const std::string& fileName){
    std::ifstream characterDataFile;

    characterDataFile.open(fileName);
    return parseUnitFromStream(&characterDataFile);
}

Character* JSONParser::parseUnitFromContent(const std::string& content){
    return createCharacter(content);
}
