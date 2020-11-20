#include "Hero.h"
#include <string>
#include <cmath>
#include <fstream>

Hero::Hero(const std::string name, int base_health, int base_damage, double base_attackCooldown, int xpPerLevel, int hpPerLevel, int dmgBonusPerLevel, double atcdMultiplier) : 
	Monster(name, base_health, base_damage, base_attackCooldown), xpPerLevel(xpPerLevel), hpPerLevel(hpPerLevel), dmgBonusPerLevel(dmgBonusPerLevel), atcdMultiplier(atcdMultiplier) 
	{ xp = 0; level = 1, maxHP = base_health; }

Hero& Hero::parse(std::string& file)
{
	std::map <std::string, std::string> parsedMap = JSON::parseUnitFromFileName(file);
	Hero* h = new Hero(parsedMap.find("name")->second, std::stoi(parsedMap.find("bhp")->second),
		std::stoi(parsedMap.find("bd")->second), std::stod(parsedMap.find("bac")->second),
		std::stoi(parsedMap.find("epl")->second), std::stoi(parsedMap.find("hpbpl")->second),
		std::stoi(parsedMap.find("dbpl")->second), std::stod(parsedMap.find("cmpl")->second));
	
	return *h;
	
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
