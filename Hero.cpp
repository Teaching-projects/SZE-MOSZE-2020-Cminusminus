#include "Hero.h"
#include <string>
#include <cmath>
#include <fstream>

Hero::Hero(const std::string name, int base_health, int base_damage, double base_attackCooldown, int xpPerLevel, int hpPerLevel, int dmgBonusPerLevel, double atcdMultiplier) : 
	Monster(name, base_health, base_damage, base_attackCooldown), xpPerLevel(xpPerLevel), hpPerLevel(hpPerLevel), dmgBonusPerLevel(dmgBonusPerLevel), atcdMultiplier(atcdMultiplier) 
	{ xp = 0; level = 1, maxHP = base_health; }

Hero Hero::parse(std::string file)
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
		throw 1;
	}
	std::map<std::string, std::string> parsedData;

	for (const auto& line : splittedString(fileContent, '\n'))
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
	return Hero(parsedData.find("name")->second, std::stoi(parsedData.find("bhp")->second),
		std::stoi(parsedData.find("bd")->second), std::stod(parsedData.find("bac")->second),
		std::stoi(parsedData.find("epl")->second), std::stoi(parsedData.find("hpbpl")->second),
		std::stoi(parsedData.find("dbpl")->second), std::stod(parsedData.find("cmpl")->second));
	
	
}

int Hero::getLevel() const
{
	return level;
}

int Hero::getMaxHealthPoints() const
{
	return maxHP;
}

int Hero::GetXP() const
{
	return xp;
}

void Hero::Attack(Monster& enemy){

	if (enemy.getHealthPoints() < this->getDamage())
	{
		XPManager(enemy);
	}
	else
	{
		XPManager(enemy);
	}

	
}
void Hero::XPManager(Monster& enemy)
{
	if (enemy.getHealthPoints() < this->getDamage())
	{
		xp += enemy.getHealthPoints();
		enemy.Monster::getAttacked(*this);
	}
	else
	{
		xp += this->getDamage();
		enemy.Monster::getAttacked(*this);
	}
	

	if ((xp-(level*xpPerLevel)) >= 0)
	{
		level++;
		
		AcdMultiplier(atcdMultiplier);
		maxHP += hpPerLevel;
		SetHealth(maxHP);
		GainDamage(dmgBonusPerLevel);
		//xp -= xpPerLevel;
	}
			

}
