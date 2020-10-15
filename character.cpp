#include "character.h"
#include <string>
#include <fstream>

Character::Character(std::string name, int health, unsigned int damage, double attackCooldown) :
                    name(name),
                    health(health),
                    damage(damage), 
					attackCooldown(attackCooldown) {}

std::string Character::GetName() const{
  return name;
}

int Character::GetHealth() const{
  return health;
}

std::vector<std::string> Character::splittedString(std::string text, char delimiter) {
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
Character* Character::parseUnit(const std::string& fileName) {
	std::string name = "";
	int health = 0;
	int damage = 0;
	double attackCooldown = 0;

	std::fstream characterDataFile;
	characterDataFile.open(fileName);

	std::string line;
	int lineIndex = 0;
	if (characterDataFile.is_open()) {
		while (std::getline(characterDataFile, line))
		{
			Character kar;
			std::vector<std::string> splittedLine = kar.splittedString(line, ':');
			
			if (splittedLine.front().find("name") != std::string::npos) {
				name = splittedLine.back();
				name = name.substr(2, name.length() - 4);
			}
			else  if (splittedLine.front().find("hp") != std::string::npos) {
				std::string inputHealth = splittedLine.back();
				inputHealth = inputHealth.substr(0, inputHealth.length() - 1);
				health = std::stoi(inputHealth);
			}
			else  if (splittedLine.front().find("dmg") != std::string::npos) {
				std::string damageHealth = splittedLine.back();
				damage = std::stoi(damageHealth);
			}
			else  if (splittedLine.front().find("attackCooldown") != std::string::npos) {
				std::string timerInput = splittedLine.back();
				attackCooldown = std::stod(timerInput);
			}
		}
		characterDataFile.close();
	}
	else
	{
		throw 1;
	}

	return new Character(name, health, damage, attackCooldown);
}
unsigned int Character::GetDamage() const{
  return damage;
}

bool Character::IsAlive() const{
  return health > 0;
}

void Character::getAttacked(const Character& enemy){
  health -= enemy.GetDamage();
  if(health < 0){
    health = 0;
  }
}

double Character::GetAttackCooldown() const
{
	return attackCooldown;
}

void Character::Attack(Character& enemy) const{

  enemy.getAttacked(*this);
}

