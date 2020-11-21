#include "Hero.h"
#include <string>
#include <cmath>
#include <fstream>

Hero::Hero(const std::string name, int base_health, int base_damage, float base_attackCooldown, int xpPerLevel, int hpPerLevel, int dmgBonusPerLevel, float atcdMultiplier) :
	Monster(name, base_health, base_damage, base_attackCooldown), xpPerLevel(xpPerLevel), hpPerLevel(hpPerLevel), dmgBonusPerLevel(dmgBonusPerLevel), atcdMultiplier(atcdMultiplier)
{
	xp = 0; level = 1, maxHP = base_health;
}

Hero Hero::parse(const std::string& s)
{

	JSON heroData = JSON::parseFromFile(s);
	return Hero(heroData.get<std::string>("name"), 
		heroData.get<int>("base_health_points"), 
		heroData.get<int>("base_damage"),
		heroData.get<float>("base_attack_cooldown"),
		heroData.get<int>("experience_per_level"), 
		heroData.get<int>("health_point_bonus_per_level"), 
		heroData.get<int>("damage_bonus_per_level"),
		heroData.get<float>("cooldown_multiplier_per_level"));
}
Hero Hero::parse(std::istream& stream) {

	JSON heroData = JSON::parseFromStream(stream);
	return Hero(heroData.get<std::string>("name"),
		heroData.get<int>("base_health_points"),
		heroData.get<int>("base_damage"),
		heroData.get<float>("base_attack_cooldown"),
		heroData.get<int>("experience_per_level"),
		heroData.get<int>("health_point_bonus_per_level"),
		heroData.get<int>("damage_bonus_per_level"),
		heroData.get<float>("cooldown_multiplier_per_level"));
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
