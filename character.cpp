#include "character.h"
#include <string>

Character::Character(std::string name, int health, unsigned int damage, double attackCooldown) :
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

unsigned int Character::GetDamage() const{
  return damage;
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

double Character::GetAttackCooldown() const
{
	return attackCooldown;
}

void Character::Attack(Character& enemy) const{

  enemy.getAttacked(*this);
}

