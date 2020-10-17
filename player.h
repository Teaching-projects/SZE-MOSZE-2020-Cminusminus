#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include "character.h"
#include<memory>

class Player : public Character
{
public:
	Player(const std::string& name, int health, int damage, double attackCooldown);
	int GetLevel() const;
	static Player* parseUnit(const std::string& fileName);
private:
	void XPManager(Character& enemy);
	void Attack(Character& enemy) override;
	
	int level;
	int xp;
	int maxHP;

};

#endif