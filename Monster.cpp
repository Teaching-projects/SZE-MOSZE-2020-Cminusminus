#include "Monster.h"
#include <string>
#include <cmath>
#include <fstream>


Monster::Monster(std::string name, int health, int damage, double attackCooldown, int defense) :
	name(name),
	health(health),
	damage(damage),
	attackCooldown(attackCooldown),
	defense(defense) {}

int Monster::getDefense()
{
	return defense;
}

void Monster::setDefense(int bonus)
{
	defense += bonus;
}

Monster Monster::parse(const std::string& s)
{

	JSON file = JSON::parseFromFile(s);
	return Monster
	(file.get<std::string>("name"),
		file.get<int>("health_points"),
		file.get<int>("damage"),
		file.get<double>("attack_cooldown"),
		file.get<int>("defense")
	);
}

Monster Monster::parse(std::istream& stream)
{

	JSON file = JSON::parseFromStream(stream);
	return Monster
	(file.get<std::string>("name"),
		file.get<int>("health_points"),
		file.get<int>("damage"),
		file.get<double>("attack_cooldown"),
		file.get<int>("defense")
	);
}


std::string Monster::getName() const {
	return name;
}

int Monster::getHealthPoints() const {
	return health;
}

void Monster::SetHealth(const int hp)
{
	this->health = hp;
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


void Monster::getAttacked(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

void Monster::Attack(Monster& enemy) {
	if (enemy.getDefense() < this->getDamage())
	{
		enemy.getAttacked(this->damage - enemy.getDefense());
	}
}

double Monster::getAttackCoolDown() const
{
	return attackCooldown;
}

void Monster::fightTilDeath(Monster& enemy) {


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
		}
		else if ((temp2 == 0) && (temp1 != 0))
		{
			enemy.Attack(*this);
			temp2 = enemy.getAttackCoolDown();
		}
		else if ((temp1 == 0) && (temp2 == 0))
		{
			this->Attack(enemy);

			if (enemy.isAlive())
			{
				enemy.Attack(*this);

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