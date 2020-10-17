#include "character.h"
#include <string>
#include <cmath>
#include <fstream>

Character::Character(std::string name, int health, int damage, double attackCooldown) :
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

void Character::SetHealth(const int health)
{
	this->health = health;
}

int Character::GetDamage() const{
  return damage;
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
			std::vector<std::string> splittedLine = splittedString(line, ':');

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
void Character::GainDamage(const double multiplier)
{
	damage = (int)round(multiplier*this->damage);
}

bool Character::IsAlive() const{
  return health > 0;
}

void Character::getAttacked(Character& enemy){
  health -= enemy.GetDamage();
  if(health < 0){
    health = 0;
  }
}

void Character::Attack(Character& enemy){
	enemy.getAttacked(*this);
}

double Character::GetAttackCooldown() const
{
	return attackCooldown;
}

void Character::battle(Character& enemy) {


	this->Attack(enemy);
	enemy.Attack(*this);
	double temp1 = this->GetAttackCooldown();
	double temp2 = enemy.GetAttackCooldown();

	while (this->IsAlive() && enemy.IsAlive())
	{
		if (temp1 >= temp2)
		{
			temp1 -= temp2;
			temp2 = 0;
		}
		else
		{
			temp2 -= temp1;
			temp1 = 0;

		}

		if ((temp1 == 0) && (temp2 != 0))
		{
			this->Attack(enemy);
			temp1 = this->GetAttackCooldown();
		}
		else if ((temp2 == 0) && (temp1 != 0))
		{
			enemy.Attack(*this);
			temp2 = enemy.GetAttackCooldown();
		}
		else if ((temp1 == 0) && (temp2 == 0))
		{
			this->Attack(enemy);
			if (enemy.IsAlive())
			{
				enemy.Attack(*this);
			}
			else
			{
				break;
			}
			temp1 = this->GetAttackCooldown();
			temp2 = enemy.GetAttackCooldown();
		}

	}

	if (this->IsAlive()) {
		std::cout << this->GetName() << " wins. Remaining HP:" << this->GetHealth() << '\n';
	}
	else {

		std::cout << enemy.GetName() << " wins. Remaining HP:" << enemy.GetHealth() << '\n';
	}
}
