#include "player.h"
#include <string>
#include <cmath>
#include <fstream>

Player::Player(const std::string& name, int health, int damage, double attackCooldown) : Character(name, health, damage, attackCooldown) { xp = 0; level = 1, maxHP = health; }

int Player::GetLevel() const
{
	return level;
}

void Player::Attack(Character& enemy){
	enemy.Character::getAttacked(*this);
	XPManager(enemy);
}

void Player::XPManager(Character& enemy)
{
	if (enemy.GetHealth() < this->GetDamage())
	{
		xp += enemy.GetHealth();
	}
	else
	{
		xp += this->GetDamage();
	}
	

		int i = xp / 100;
		
		for (int j = 0; j < i; j++)
		{
			level++;
			maxHP = (int)(round(1.1*maxHP));
			SetHealth(maxHP);
			GainDamage(1.1);
			xp -= 100;
		}	

}
Player* Player::parseUnit(const std::string& fileName) {
	std::string name = "";
	int health = 0;
	int damage = 0;
	double attackCooldown = 0;

	std::fstream characterDataFile;
	characterDataFile.open(fileName);

	std::string line;
	int lineIndex = 0;
	if (characterDataFile.is_open()) {
		while (std::getline(characterDataFile, line))
		{
			std::vector<std::string> splittedLine = splittedString(line, ':');

			if (splittedLine.front().find("name") != std::string::npos) {
				name = splittedLine.back();
				name = name.substr(2, name.length() - 4);
			}
			else  if (splittedLine.front().find("hp") != std::string::npos) {
				std::string inputHealth = splittedLine.back();
				inputHealth = inputHealth.substr(0, inputHealth.length() - 1);
				health = std::stoi(inputHealth);
			}
			else  if (splittedLine.front().find("dmg") != std::string::npos) {
				std::string damageHealth = splittedLine.back();
				damage = std::stoi(damageHealth);
			}
			else  if (splittedLine.front().find("attackCooldown") != std::string::npos) {
				std::string timerInput = splittedLine.back();
				attackCooldown = std::stod(timerInput);
			}
		}
		characterDataFile.close();
	}
	else
	{
		throw 1;
	}

	return new Player(name, health, damage, attackCooldown);
}
