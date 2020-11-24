#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include<string>
#include<memory>
#include <vector>
#include "JSON.h"

class Monster
{
	/**
  *\brief A class for creating a monster.
  *\param name The name of the monster.
  *\param health The health of the monster.
  *\param damage The damage of the monster.
  *\param attackCooldown The speed of the monster's attack.
  *\param defense The defense of the monster.
  */
public:


	Monster(std::string name, int health, int damage, double attackCooldown, int defense);
	Monster() {};
	///It returns the defense of the Monster
	///\return defense
	int getDefense();
	///It sets the defense of the Hero when it levels up
	///\param bonus The amount we add to the defense
	void setDefense(int bonus);
	///This function parse a Monster from a file.
	///\param s The file name we parse.
	///\return Monster
	static Monster parse(const std::string& s);
	///This function parse a Monster using istream.
	///\param stream The stream we parse from.
	///\return Monster
	static Monster parse(std::istream& stream);
	///It returns the name of the monster.
	///\return name
	std::string getName() const;
	///It returns the health of the monster.
	  ///\return health
	int getHealthPoints() const;
	///It sets the health of the monster.
	///\param health The current health of the monster
	void SetHealth(const int health);
	///It returns the damage of the monster.
	///\return damage
	int getDamage() const;
	///It sets the damage of the monster after level up
	///\param multiplier
	void GainDamage(const int bonus);
	///It multiplies the attack cooldown with the given amount.
	///\param multplier The amound we multiply the attack cooldown.
	void AcdMultiplier(double multiplier);
	///It checks if the monster is alive.
	///\return true or false.
	bool isAlive() const;
	///\brief A function to simulate the battle of two given monster.
	///\param enemy The enemy which the monster attacks.
	void fightTilDeath(Monster& enemy);
	///It returns the attack speed of the monster.
	///\return attackCooldown
	double getAttackCoolDown() const;
	///Attacks the enemy.
	///\param damage The damage we attack the enemy with
	void getAttacked(int damage);
	friend bool operator==(const Monster character1, const Monster character2);
	friend bool operator!=(const Monster character1, const Monster character2);
private:
	virtual void Attack(Monster& enemy);

	const std::string name = "";
	int health = 0;
	int damage = 0;
	double attackCooldown = 0;
	int defense = 0;
	std::string lore = "";
	std::string add_info = "";
	std::string race = "";
};

#endif // CHARACTER_H
