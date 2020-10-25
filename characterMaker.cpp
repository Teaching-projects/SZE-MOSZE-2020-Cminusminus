
#include "characterMaker.h"
#include "character.h"

std::vector<std::string> CharacterMaker::splittedString(std::string text, char delimiter){
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

void CharacterMaker::showErrorMessage(std::string message){
    std::cerr << message << '\n';
    exit(1);
}

Character* CharacterMaker::createCharacter(const std::string& fileContent){
    std::string name = "";
    int health = -1;
    int damage = -1;

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

    if(name == "" || health == -1 || damage == -1){
        showErrorMessage("I cannot create the character!");
    }

    return new Character(name, health, damage);
}