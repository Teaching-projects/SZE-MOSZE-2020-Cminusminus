#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include "character.h"
#include<memory>

class Player : public Character
{
public:
	Player(const std::string& name, int health, int damage);

	void XPManager(const Player& player);
	int GetLevel() const;
private:

	int level;
	int xp;
	int maxHP;

};

#endif