#include "player.h"
#include <string>
#include <math.h>

Player::Player(const std::string& name, unsigned long health, unsigned long damage) : Character(name, health, damage) { xp = 0; level = 1, maxHP = health; }

unsigned int Player::GetLevel() const
{
	return level;
}

void Player::XPManager(const Player& player)
{
	xp += player.GetDamage();
	
	if (xp >= 100)
	{
		
		int i = xp / 100;
		
		for (int j = 0; j < i; j++)
		{
			level++;
			maxHP = (unsigned long)(round(1.1*maxHP));
			SetHealth(maxHP);
			GainDamage(1.1);
			xp -= 100;
		}	
		//std::cout << player.GetName() << "'s level: " << player.GetLevel() << ". DMG: " << player.GetDamage() << ". HP: " << player.GetHealth() << std::endl;
	}

}
