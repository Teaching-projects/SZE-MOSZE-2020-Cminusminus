#ifndef MONSTER_H
#define MONSTER_H

#include<iostream>
#include<memory>
#include <vector>
#include "JSON.h"

class Monster
{
	/**
  *\brief A class for creating a character.
  *\param name The name of the character.
  *\param health The health of the character.
  *\param damage The damage of the character.
  *\param attackCooldown The speed of the character's attack.
  */
public:


	Monster(std::string name, int health, int damage, double attackCooldown, std::string lore, std::string add_info, std::string race);
    Monster(std::string name, int health, int damage, double attackCooldown);
	Monster() {};

    static Monster& parse(std::string file);
	///It returns the name of the character.
	///\return name
  std::string getName() const;
  ///It returns the health of the character.
	///\return health
  int getHealthPoints() const;
  ///It sets the health of the character
  ///\param health 
  void SetHealth(const int health);
  ///It returns the damage of the character.
  ///\return damage
  int getDamage() const;
  ///It sets the damage of the character after level up
  ///\param multiplier
  void GainDamage(const int bonus);
  //It checks if the character is alive.
  ///\return true or false.
  void AcdMultiplier(double multiplier);
  bool isAlive() const;
  ///\brief A function to simulate the battle of two given characters.
  ///\param enemy The enemy which the character attacks.
  void fightTilDeath(Monster& enemy);
  ///It returns the attack speed of the character.
  ///\return attackCooldown
  double getAttackCoolDown() const;
  ///Attack the enemy character
  ///\param enemy
  void getAttacked(const Monster& enemy);
  friend bool operator==(const Monster character1, const Monster character2);
  friend bool operator!=(const Monster character1, const Monster character2);
private:
	virtual void Attack(Monster& enemy);
	
	const std::string name = "";
	int health = 0;
	int damage = 0;
	double attackCooldown = 0;
    std::string lore = "";
    std::string add_info = "";
    std::string race = "";
protected:
    static std::vector<std::string> splittedString(std::string text, char delimiter);
};

#endif // CHARACTER_H
