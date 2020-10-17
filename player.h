#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include "character.h"
#include<memory>

class Player : public Character
{
public:
	Player(const std::string& name, int health, int damage);
	
	void Attack(Player& enemy);
	int GetLevel() const;
private:
	void XPManager(Player& player, Player& enemy);

	int level;
	int xp;
	int maxHP;

};

#endif