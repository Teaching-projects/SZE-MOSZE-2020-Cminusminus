
#include "characterMaker.h"
#include "character.h"
#include <map>
#include<iterator>

void CharacterMaker::showErrorMessage(std::string message){
    std::cerr << message << '\n';
    exit(1);
}

Character* CharacterMaker::createCharacter(std::map<std::string, std::string> parsedData){
    
    return new Character(parsedData.find("name")->second, std::stoi(parsedData.find("health")->second), std::stoi(parsedData.find("damage")->second));
}