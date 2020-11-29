#ifndef HERO_H
#define HERO_H

#include<iostream>
#include "Monster.h"
#include<memory>
#include "JSON.h"

class Hero : public Monster
{
	/**
*\brief A class for creating a hero.
*\param name The name of the hero.
*\param base_health The health of the hero.
*\param damage The damage of the hero (physical and magical).
*\param base_attackCooldown The speed of the hero's attack.
*\param defense The defense of the hero.
*\param xpPerLevel The xp we need to level up.
*\param hpPerLevel The health bonus we get after level up.
*\param dmgBonusPerLevel The physical damage bonus we get after level up.
*\param atcdMultiplier The attack cooldown multiplier we multiply the attack cooldown after level up.
*\param defBonusPerLevel The defense bonus we get after level up.
*\param magbonperlev The magical damage bonus we get after level up.
*\param lightr The light radius of the hero.
*\param lightrbonusPerLevel The light radius bonus we get after level up.
*/
public:
	Hero(const std::string name, int base_health, Damage damage, double base_attackCooldown, int defense, int xpPerLevel, int hpPerLevel,
		int dmgBonusPerLevel, double atcdMultiplier,  int defBonusPerLevel, int magbonperlev, int lightr, int lightrbonusPerLevel);
	///This function parse a Hero from a file.
	///\param s
	///\return Hero
	static Hero parse(const std::string& s);
	///This function parse a Hero from a file.
	///\param s
	///\return Hero
	static Hero parse(std::istream& stream);
	///\brief Returns the hero's level.
	///\return int
	int getLevel() const;
	///\brief Returns the hero's hp.
	///\return int
	int getMaxHealthPoints() const;
	///\brief Returns the hero's xp.
	///\return int
	int GetXP() const;
	///\brief Returns the hero's light radius.
	///\return int
	int getRadius() const;
private:
	void XPManager(Monster& enemy);
	void Attack(Monster& enemy) override;

	int level = 1;
	int xp = 0;
	int maxHP = getHealthPoints();
	int xpPerLevel = 0;
	int hpPerLevel = 0;
	int dmgBonusPerLevel = 0;
	double atcdMultiplier = 0.0;
	int defBonusPerLevel = 0;
	int magicalBonusPerLevel = 0;
	int lightRadius = 0;
	int lightRadiusBonusPerLevel = 0;
};

#endif

