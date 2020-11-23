#include "Hero.h"
#include <string>
#include <cmath>
#include <fstream>

Hero::Hero(const std::string name, int base_health, int base_damage, double base_attackCooldown, int xpPerLevel, int hpPerLevel, int dmgBonusPerLevel, double atcdMultiplier) :
	Monster(name, base_health, base_damage, base_attackCooldown), xpPerLevel(xpPerLevel), hpPerLevel(hpPerLevel), dmgBonusPerLevel(dmgBonusPerLevel), atcdMultiplier(atcdMultiplier)
{
	xp = 0; level = 1, maxHP = base_health;
}

Hero Hero::parse(const std::string& s)
{

	JSON file = JSON::parseFromFile(s);
	return Hero
	(	file.get<std::string>("name"), 
		file.get<int>("base_health_points"), 
		file.get<int>("base_damage"),
		file.get<double>("base_attack_cooldown"),
		file.get<int>("experience_per_level"), 
		file.get<int>("health_point_bonus_per_level"), 
		file.get<int>("damage_bonus_per_level"),
		file.get<double>("cooldown_multiplier_per_level")
		);
}
Hero Hero::parse(std::istream& stream) {

	JSON file = JSON::parseFromStream(stream);
	return Hero
	(	file.get<std::string>("name"),
		file.get<int>("base_health_points"),
		file.get<int>("base_damage"),
		file.get<double>("base_attack_cooldown"),
		file.get<int>("experience_per_level"),
		file.get<int>("health_point_bonus_per_level"),
		file.get<int>("damage_bonus_per_level"),
		file.get<double>("cooldown_multiplier_per_level")
	);
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

void Hero::Attack(Monster& enemy) {

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


	if ((xp - (level * xpPerLevel)) >= 0)
	{
		level++;

		AcdMultiplier(atcdMultiplier);
		maxHP += hpPerLevel;
		SetHealth(maxHP);
		GainDamage(dmgBonusPerLevel);
		//xp -= xpPerLevel;
	}


}
