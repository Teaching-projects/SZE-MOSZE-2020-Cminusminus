
#include "characterMaker.h"
#include "character.h"
#include <map>
#include<iterator>

void CharacterMaker::showErrorMessage(std::string message){
    std::cerr << message << '\n';
    exit(1);
}

Character* CharacterMaker::createCharacter(std::map<std::string, std::string> parsedData){
    int health = -1;
    try
    {
        health = std::stoi(parsedData.find("health")->second);
   }
    catch (const std::exception & e) { throw e; }

  int damage = -1;
   try
   {
        damage = std::stoi(parsedData.find("damage")->second);
    }
    catch(const std::exception& e){ throw e; }

    double attackCooldown = -1;
    try
    {
        attackCooldown = std::stod(parsedData.find("attackCooldown")->second);
   }
    catch (const std::exception & e) { throw e; }
    
    return new Character(parsedData.find("name")->second, health, damage, attackCooldown);
}