#include "Monster.h"
#include <string>
#include <cmath>
#include <fstream>

Monster::Monster(std::string name, int health, int damage, double attackCooldown, std::string lore, std::string add_info, std::string race) :
	name(name),
	health(health),
	damage(damage),
	attackCooldown(attackCooldown),
	lore(lore),
	add_info(add_info),
	race(race) {}

Monster::Monster(std::string name, int health, int damage, double attackCooldown) :
	name(name),
	health(health),
	damage(damage),
	attackCooldown(attackCooldown) {}

Monster Monster::parse(std::string file)
{
	std::ifstream characterDataFile;

	characterDataFile.open(file);

	std::string fileContent = "";
	std::string line;

	if (characterDataFile.is_open()) {
		while (std::getline(characterDataFile, line))
		{
			fileContent += line + '\n';
		}
		characterDataFile.close();
	}
	else
	{
		throw JSON::ParseException("error");
	}

	std::map<std::string, std::string> parsedData;

	for (const auto& line : splittedString(fileContent, ','))
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
	//std::string name, int health, int damage, double attackCooldown, std::string lore, std::string add_info, std::string race

	return Monster
	(
		parsedData.find("name")->second, 
		std::stoi(parsedData.find("hp")->second),
		std::stoi(parsedData.find("dmg")->second),
		std::stod(parsedData.find("atc")->second),
		parsedData.find("lore")->second,
		parsedData.find("info")->second,
		parsedData.find("race")->second
	);
}

std::string Monster::getName() const{
  return name;
}

int Monster::getHealthPoints() const{
  return health;
}

void Monster::SetHealth(const int health)
{
	this->health = health;
}

int Monster::getDamage() const{
  return damage;
}

void Monster::GainDamage(const int bonus)
{
	damage+= bonus;
}

void Monster::AcdMultiplier(double multiplier)
{
	attackCooldown *= multiplier;
}

bool Monster::isAlive() const{
  return health > 0;
}


void Monster::getAttacked(const Monster& enemy){
  health -= enemy.getDamage();
  if(health < 0){
    health = 0;
  }
}

void Monster::Attack(Monster& enemy){
	enemy.getAttacked(*this);
}

std::vector<std::string> Monster::splittedString(std::string text, char delimiter)
{
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

double Monster::getAttackCoolDown() const
{
	return attackCooldown;
}

void Monster::fightTilDeath(Monster& enemy) {

	//this->Attack(enemy); 
	//enemy.Attack(*this);
	double temp1 = this->getAttackCoolDown();
	double temp2 = enemy.getAttackCoolDown();

	while (this->isAlive() && enemy.isAlive())
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
			temp1 = this->getAttackCoolDown();
			//std::cout << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:"  << this->getDamage() << ", ATCD:"<< this->getAttackCoolDown() << " attacks " << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << std::endl << std::endl;
		}
		else if ((temp2 == 0) && (temp1 != 0))
		{
			enemy.Attack(*this);
			//std::cout << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << " attacks " << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:" << this->getDamage() << ", ATCD:" << this->getAttackCoolDown() << std::endl << std::endl;
			temp2 = enemy.getAttackCoolDown();
		}
		else if ((temp1 == 0) && (temp2 == 0))
		{
			this->Attack(enemy);
			//std::cout << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:" << this->getDamage() << ", ATCD:" << this->getAttackCoolDown() << " attacks " << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << std::endl << std::endl;

			if (enemy.isAlive())
			{
				enemy.Attack(*this);
				//std::cout << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << " attacks " << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:" << this->getDamage() << ", ATCD:" << this->getAttackCoolDown() << std::endl << std::endl;

			}
			else
			{
				break;
			}
			temp1 = this->getAttackCoolDown();
			temp2 = enemy.getAttackCoolDown();
		}		
	}
}


bool operator==(const Monster character1, const Monster character2){
  return character1.getName() == character2.getName() &&
         character1.getDamage() == character2.getDamage() &&
         character1.getHealthPoints() == character2.getHealthPoints();
}

bool operator!=(const Monster character1, const Monster character2){
  return !(character1 == character2);
}