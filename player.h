#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include "character.h"
#include<memory>

class Player : public Character
{
	/**
*\brief A class for creating a player.
*\param name The name of the player.
*\param health The health of the player.
*\param damage The damage of the player.
*\param attackCooldown The speed of the player's attack.
*/
public:
	Player(const std::string name, int health, int damage, double attackCooldown);
	///\brief Returns the player's level
	///\return level
	int GetLevel() const;
	int GetMaxHP() const;
private:
	void XPManager(Character& enemy);
	void Attack(Character& enemy) override;
	
	int level;
	int xp;
	int maxHP;

};

#endif