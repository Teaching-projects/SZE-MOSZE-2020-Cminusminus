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
  Character(std::string name, int health, unsigned int damage, double attackCooldown);
  Character() {};
  ///It returns the name of the character.
  ///\return name
  std::string GetName() const;
  ///It returns the health of the character.
  ///\return health
  int GetHealth() const;
  ///It returns the damage of the character.
  ///\return damage
  unsigned int GetDamage() const;
  ///It checks if the character is alive.
  ///\return true or false.
  bool IsAlive() const;
  /**
  *\brief A function which attacks the enemy.
  *\param enemy The enemy the character attacks.
  */
  void Attack(Character& enemy) const;
  ///It returns the attack speed of the character.
  ///\return attackCooldown
  double GetAttackCooldown() const;
  static Character* parseUnit(const std::string& fileName);
private:
	void getAttacked(const Character& enemy);
	std::vector<std::string> splittedString(std::string text, char delimiter);
  const std::string name = "";
  int health = 0;
  const unsigned int damage = 0;
  double attackCooldown = 0;
};

#endif // CHARACTER_H