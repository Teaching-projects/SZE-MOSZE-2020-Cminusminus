#ifndef HERO_H
#define HERO_H

#include<iostream>
#include "Monster.h"

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
*\param texture The texture of the hero in svg.
*/
public:
	Hero(const std::string& name, const int base_health, Damage damage, const double base_attackCooldown, const int defense, const int xpPerLevel, const int hpPerLevel,
		const int dmgBonusPerLevel, const double atcdMultiplier, const int defBonusPerLevel, const int magbonperlev, const int lightr, const int lightrbonusPerLevel, const std::string& texture);
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
	const int xpPerLevel = 0;
	const int hpPerLevel = 0;
	const int dmgBonusPerLevel = 0;
	const double atcdMultiplier = 0.0;
	const int defBonusPerLevel = 0;
	const int magicalBonusPerLevel = 0;
	int lightRadius = 0;
	const int lightRadiusBonusPerLevel = 0;
};

#endif

