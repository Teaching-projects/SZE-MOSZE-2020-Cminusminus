#include "Monster.h"
#include <string>
#include <cmath>
#include <fstream>

Monster::Monster(const std::string name, const int health, Damage damage, const double attackCooldown, const int defense, const std::string texture) :
	name(name),
	health(health),
	damage(damage),
	attackCooldown(attackCooldown),
	defense(defense),
	texture(texture){}

std::string Monster::getTexture() const
{
	return texture;
}

int Monster::getDefense() const
{
	return defense;
}

void Monster::setDefense(const int bonus)
{
	defense += bonus;
}

Monster Monster::parse(const std::string& s)
{

	JSON file = JSON::parseFromFile(s);
	Damage dmg;
	if (file.count("damage"))
	{
		dmg.physical = file.get<int>("damage");
	}
	else
	{
		dmg.physical = 0;
	}

	if (file.count("magical-damage"))
	{
		dmg.magical = file.get<int>("magical-damage");
	}
	else
	{
		dmg.magical = 0;
	}
	return Monster
	(file.get<std::string>("name"),
		file.get<int>("health_points"),
		dmg,
		file.get<double>("attack_cooldown"),
		file.get<int>("defense"),
		file.get<std::string>("texture")
	);
}

Monster Monster::parse(std::istream& stream)
{

	JSON file = JSON::parseFromStream(stream);

	Damage dmg;
	if (file.count("damage"))
	{
		dmg.physical = file.get<int>("damage");
	}
	else
	{
		dmg.physical = 0;
	}

	if (file.count("magical-damage"))
	{
		dmg.magical = file.get<int>("magical-damage");
	}
	else
	{
		dmg.magical = 0;
	}
	return Monster
	(file.get<std::string>("name"),
		file.get<int>("health_points"),
		dmg,
		file.get<double>("attack_cooldown"),
		file.get<int>("defense"),
		file.get<std::string>("texture")
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

int Monster::getPhysicalDmg() const
{
	return damage.physical;
}

int Monster::getMagicalDmg() const
{
	return damage.magical;
}


void Monster::GainDamage(const int bonus, const std::string type)
{
	if (type == "physical")
	{
		damage.physical += bonus;
	}
	else if (type == "magical")
	{
		damage.magical += bonus;
	}
}

void Monster::AcdMultiplier(const double multiplier)
{
	attackCooldown *= multiplier;
}

bool Monster::isAlive() const {
	return health > 0;
}


void Monster::getAttacked(const int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

void Monster::Attack(Monster& enemy) {
	if (enemy.getDefense() < this->getPhysicalDmg())
	{
		enemy.getAttacked((this->damage.physical - enemy.getDefense())+this->getMagicalDmg());
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