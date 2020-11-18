#include "character.h"
#include <string>
#include <cmath>
#include <fstream>

Character::Character(std::string name, int health, int damage, double attackCooldown) :
	name(name),
	health(health),
	damage(damage),
	attackCooldown(attackCooldown) {}

std::string Character::GetName() const{
  return name;
}

int Character::GetHealth() const{
  return health;
}

void Character::SetHealth(const int health)
{
	this->health = health;
}

int Character::GetDamage() const{
  return damage;
}

void Character::GainDamage(const double multiplier)
{
	damage = (int)round(multiplier*this->damage);
}

bool Character::IsAlive() const{
  return health > 0;
}


void Character::getAttacked(const Character& enemy){
  health -= enemy.GetDamage();
  if(health < 0){
    health = 0;
  }
}

void Character::Attack(Character& enemy){
	enemy.getAttacked(*this);
}

double Character::GetAttackCooldown() const
{
	return attackCooldown;
}

void Character::battle(Character& enemy) {


	this->Attack(enemy);
	enemy.Attack(*this);
	double temp1 = this->GetAttackCooldown();
	double temp2 = enemy.GetAttackCooldown();

	while (this->IsAlive() && enemy.IsAlive())
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
			temp1 = this->GetAttackCooldown();
		}
		else if ((temp2 == 0) && (temp1 != 0))
		{
			enemy.Attack(*this);
			temp2 = enemy.GetAttackCooldown();
		}
		else if ((temp1 == 0) && (temp2 == 0))
		{
			this->Attack(enemy);
			if (enemy.IsAlive())
			{
				enemy.Attack(*this);
			}
			else
			{
				break;
			}
			temp1 = this->GetAttackCooldown();
			temp2 = enemy.GetAttackCooldown();
		}

	}

	if (this->IsAlive()) {
		std::cout << this->GetName() << " wins. Remaining HP:" << this->GetHealth() << '\n';
	}
	else {

		std::cout << enemy.GetName() << " wins. Remaining HP:" << enemy.GetHealth() << '\n';
	}
}


bool operator==(const Character character1, const Character character2){
  return character1.GetName() == character2.GetName() &&
         character1.GetDamage() == character2.GetDamage() &&
         character1.GetHealth() == character2.GetHealth();
}

bool operator!=(const Character character1, const Character character2){
  return !(character1 == character2);
}