#ifndef HERO_H
#define HERO_H

#include<iostream>
#include "Monster.h"
#include<memory>
#include "JSON.h"

class Hero : public Monster
{
	/**
*\brief A class for creating a player.
*\param name The name of the player.
*\param base_health The health of the player.
*\param base_damage The damage of the player.
*\param base_attackCooldown The speed of the player's attack.
*\param xpPerLevel The xp we need to level up.
*\param hpPerLevel The health we get after level up.
*\param dmgBonusPerLevel The damage we get after level up.
*\param atcdMultiplier The attack cooldown multiplier we multiply the attack cooldown after level up.
*/
public:
	Hero(const std::string name, int base_health, int base_damage, double base_attackCooldown, int xpPerLevel, int hpPerLevel, int dmgBonusPerLevel, double atcdMultiplier);
	///This function parse a Hero from a file.
	///\param s
    ///\return Hero
	static Hero parse(const std::string& s);
	///This function parse a Hero from a file.
	///\param s
    ///\return Hero
	static Hero parse(std::istream& stream);
	///\brief Returns the player's level.
	///\return int
	int getLevel() const;
	///\brief Returns the player's hp.
	///\return int
	int getMaxHealthPoints() const;
	///\brief Returns the player's xp.
	///\return int
	int GetXP() const;
private:
	void XPManager(Monster& enemy);
	void Attack(Monster& enemy) override;

	int level;
	int xp;
	int maxHP;
	int xpPerLevel;
	int hpPerLevel;
	int dmgBonusPerLevel;
	double atcdMultiplier;
};

#endif