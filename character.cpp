#include "character.h"
#include <string>
#include <cmath>

Character::Character(const std::string& name, int health, int damage) :
                    name(name),
                    health(health),
                    damage(damage) {}

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

void Character::GetAttacked(const Character& enemy){
  health -= enemy.GetDamage();
  if(health < 0){
    health = 0;
  }
}

void Character::Attack(Character& enemy){
  enemy.GetAttacked(*this);
}
