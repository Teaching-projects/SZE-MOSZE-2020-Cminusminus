#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<memory>
#include <vector>

class Character
{
	/**
  *\brief A class for creating a character.
  *\param name The name of the character.
  *\param health The health of the character.
  *\param damage The damage of the character.
  *\param attackCooldown The speed of the character's attack.
  */
public:


	Character(std::string name, int health, int damage, double attackCooldown);
	Character() {};
	///It returns the name of the character.
	///\return name
  std::string GetName() const;
  ///It returns the health of the character.
	///\return health
  int GetHealth() const;
  void SetHealth(const int health);
  ///It returns the damage of the character.
  ///\return damage
  int GetDamage() const;
  void GainDamage(const double multiplier);
  //It checks if the character is alive.
  ///\return true or false.
  bool IsAlive() const;
  ///\brief A function to simulate the battle of two given characters.
  ///\param enemy The enemy which the character attacks.
  void battle(Character& enemy);
  ///It returns the attack speed of the character.
  ///\return attackCooldown
  double GetAttackCooldown() const;
  ///\brief A function to get the characters parameters from a file.
  ///\param fileName The name of the file used to read the data from.
  ///\return Character*
  static Character* parseUnit(const std::string& fileName);
  void getAttacked(Character& enemy);
private:
	virtual void Attack(Character& enemy);
	
	static std::vector<std::string> splittedString(std::string text, char delimiter);
	const std::string name = "";
	int health = 0;
	int damage = 0;
	double attackCooldown = 0;
};

#endif // CHARACTER_H
