#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include "character.h"
#include<memory>

class Player : public Character
{
public:
	Player(const std::string& name, unsigned long health, unsigned long damage);

	void XPManager(const Player& player);
	unsigned int GetLevel() const;
private:

	unsigned int level;
	unsigned long xp;
	unsigned long maxHP;

};

#endif