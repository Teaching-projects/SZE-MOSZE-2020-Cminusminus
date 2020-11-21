#include "Monster.h"
#include <string>
#include <cmath>
#include <fstream>


Monster::Monster(std::string name, int health, int damage, float attackCooldown) :
	name(name),
	health(health),
	damage(damage),
	attackCooldown(attackCooldown) {}

Monster Monster::parse(const std::string& s)
{

	JSON monsterData = JSON::parseFromFile(s);
	return Monster(monsterData.get<std::string>("name"), monsterData.get<int>("health_points"),
		monsterData.get<int>("damage"), monsterData.get<float>("attack_cooldown"));
}

Monster Monster::parse(std::istream& stream)
{

	JSON monsterData = JSON::parseFromStream(stream);
	return Monster(monsterData.get<std::string>("name"), monsterData.get<int>("health_points"),
		monsterData.get<int>("damage"), monsterData.get<float>("attack_cooldown"));
}

std::string Monster::getName() const {
	return name;
}

int Monster::getHealthPoints() const {
	return health;
}

void Monster::SetHealth(const int health)
{
	this->health = health;
}

int Monster::getDamage() const {
	return damage;
}

void Monster::GainDamage(const int bonus)
{
	damage += bonus;
}

void Monster::AcdMultiplier(double multiplier)
{
	attackCooldown *= multiplier;
}

bool Monster::isAlive() const {
	return health > 0;
}


void Monster::getAttacked(const Monster& enemy) {
	health -= enemy.getDamage();
	if (health < 0) {
		health = 0;
	}
}

void Monster::Attack(Monster& enemy) {
	enemy.getAttacked(*this);
}

std::vector<std::string> Monster::splittedString(std::string text, char delimiter)
{
	std::vector<std::string> splittedStrings;
	std::string addString = "";

	for (unsigned int i = 0; i < text.length(); i++) {
		if (text[i] == delimiter) {
			splittedStrings.push_back(addString);
			addString = "";
		}
		else {
			addString += text[i];
		}
	}

	splittedStrings.push_back(addString);

	return splittedStrings;
}

double Monster::getAttackCoolDown() const
{
	return attackCooldown;
}

void Monster::fightTilDeath(Monster& enemy) {

	//this->Attack(enemy); 
	//enemy.Attack(*this);
	double temp1 = this->getAttackCoolDown();
	double temp2 = enemy.getAttackCoolDown();

	while (this->isAlive() && enemy.isAlive())
	{
		if (temp1 >= temp2)
		{
			temp1 -= temp2;
			temp2 = 0;
		}
		else
		{
			temp2 -= temp1;
			temp1 = 0;

		}

		if ((temp1 == 0) && (temp2 != 0))
		{
			this->Attack(enemy);
			temp1 = this->getAttackCoolDown();
			//std::cout << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:"  << this->getDamage() << ", ATCD:"<< this->getAttackCoolDown() << " attacks " << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << std::endl << std::endl;
		}
		else if ((temp2 == 0) && (temp1 != 0))
		{
			enemy.Attack(*this);
			//std::cout << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << " attacks " << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:" << this->getDamage() << ", ATCD:" << this->getAttackCoolDown() << std::endl << std::endl;
			temp2 = enemy.getAttackCoolDown();
		}
		else if ((temp1 == 0) && (temp2 == 0))
		{
			this->Attack(enemy);
			//std::cout << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:" << this->getDamage() << ", ATCD:" << this->getAttackCoolDown() << " attacks " << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << std::endl << std::endl;

			if (enemy.isAlive())
			{
				enemy.Attack(*this);
				//std::cout << enemy.getName() << " - HP:" << enemy.getHealthPoints() << ", DMG:" << enemy.getDamage() << ", ATCD:" << enemy.getAttackCoolDown() << " attacks " << this->getName() << " - HP:" << this->getHealthPoints() << ", DMG:" << this->getDamage() << ", ATCD:" << this->getAttackCoolDown() << std::endl << std::endl;

			}
			else
			{
				break;
			}
			temp1 = this->getAttackCoolDown();
			temp2 = enemy.getAttackCoolDown();
		}
	}
}


bool operator==(const Monster character1, const Monster character2) {
	return character1.getName() == character2.getName() &&
		character1.getDamage() == character2.getDamage() &&
		character1.getHealthPoints() == character2.getHealthPoints();
}

bool operator!=(const Monster character1, const Monster character2) {
	return !(character1 == character2);
}