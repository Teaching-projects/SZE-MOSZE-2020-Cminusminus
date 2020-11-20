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
*\param health The health of the player.
*\param damage The damage of the player.
*\param attackCooldown The speed of the player's attack.
*/
public:
	Hero(const std::string name, int base_health, int base_damage, double base_attackCooldown, int xpPerLevel, int hpPerLevel, int dmgBonusPerLevel, double atcdMultiplier);

	static Hero parse(const std::string&);
	///\brief Returns the player's level
	///\return level
	int getLevel() const;
	int getMaxHealthPoints() const;
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