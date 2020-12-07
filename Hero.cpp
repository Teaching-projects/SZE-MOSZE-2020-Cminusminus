#include "Hero.h"
#include <string>
#include <cmath>
#include <fstream>

Hero::Hero(const std::string name, const int base_health, Damage damage, const double base_attackCooldown, const int defense, const int xpPerLevel,
	const int hpPerLevel, const int dmgBonusPerLevel, const double atcdMultiplier,const int defBonusPerLevel, const int magbonperlev, const int lightr, const int lightrbonusPerLevel, const std::string texture) :
	Monster(name, base_health, damage, base_attackCooldown, defense,texture),
	xpPerLevel(xpPerLevel), hpPerLevel(hpPerLevel), dmgBonusPerLevel(dmgBonusPerLevel), atcdMultiplier(atcdMultiplier), defBonusPerLevel(defBonusPerLevel), magicalBonusPerLevel(magbonperlev), lightRadius(lightr), lightRadiusBonusPerLevel(lightrbonusPerLevel)
{
}

Hero Hero::parse(const std::string& s)
{

	JSON file = JSON::parseFromFile(s);
	Damage dmg;
	int lr;
	if (file.count("base_damage"))
	{
		dmg.physical = file.get<int>("base_damage");
	}
	else
	{
		dmg.physical = 0;
	}

	if (file.count("magical-damage"))
	{
		dmg.magical = file.get<int>("magical-damage");
	}
	else
	{
		dmg.magical = 0;
	}

	if (file.count("light_radius_bonus_per_level"))
	{
		lr = file.get<int>("light_radius_bonus_per_level");
	}
	else
	{
		lr = 1;
	}
	return Hero
	(file.get<std::string>("name"),
		file.get<int>("base_health_points"),
		dmg,
		file.get<double>("base_attack_cooldown"),
		file.get<int>("defense"),
		file.get<int>("experience_per_level"),
		file.get<int>("health_point_bonus_per_level"),
		file.get<int>("damage_bonus_per_level"),
		file.get<double>("cooldown_multiplier_per_level"),
		file.get<int>("defense_bonus_per_level"),
		file.get<int>("magical_bonus_per_level"),
		file.get<int>("light_radius"),
		lr,
		file.get<std::string>("texture")
	);
}
Hero Hero::parse(std::istream& stream) {

	JSON file = JSON::parseFromStream(stream);
	Damage dmg;
	int lr;
	if (file.count("base_damage"))
	{
		dmg.physical = file.get<int>("base_damage");
	}
	else
	{
		dmg.physical = 0;
	}

	if (file.count("magical-damage"))
	{
		dmg.magical = file.get<int>("magical-damage");
	}
	else
	{
		dmg.magical = 0;
	}

	if (file.count("light_radius_bonus_per_level"))
	{
		lr = file.get<int>("light_radius_bonus_per_level");
	}
	else
	{
		lr = 1;
	}
	return Hero
	(file.get<std::string>("name"),
		file.get<int>("base_health_points"),
		dmg,
		file.get<double>("base_attack_cooldown"),
		file.get<int>("defense"),
		file.get<int>("experience_per_level"),
		file.get<int>("health_point_bonus_per_level"),
		file.get<int>("damage_bonus_per_level"),
		file.get<double>("cooldown_multiplier_per_level"),
		file.get<int>("defense_bonus_per_level"),
		file.get<int>("magical_bonus_per_level"),
		file.get<int>("light_radius"),
		lr,
		file.get<std::string>("texture")
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

int Hero::getRadius() const
{
	return lightRadius;
}

void Hero::Attack(Monster& enemy) {
	if (enemy.getDefense() < this->getPhysicalDmg())
	{
		XPManager(enemy);
	}

}
void Hero::XPManager(const Monster& enemy)
{
	if (enemy.getHealthPoints() < ((this->getPhysicalDmg()-enemy.getDefense())+this->getMagicalDmg()))
	{
		xp += enemy.getHealthPoints();
		enemy.Monster::getAttacked(this->getPhysicalDmg()-enemy.getDefense()+this->getMagicalDmg());
	}
	else
	{
		xp += (this->getPhysicalDmg()-enemy.getDefense()+this->getMagicalDmg());
		enemy.Monster::getAttacked(this->getPhysicalDmg() - enemy.getDefense() + this->getMagicalDmg());
	}


	if ((xp - (level * xpPerLevel)) >= 0)
	{
		level++;

		AcdMultiplier(atcdMultiplier);
		maxHP += hpPerLevel;
		SetHealth(maxHP);
		GainDamage(dmgBonusPerLevel,"physical");
		GainDamage(magicalBonusPerLevel, "magical");
		setDefense(defBonusPerLevel);
		lightRadius += lightRadiusBonusPerLevel;
	}


}
