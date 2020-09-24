#include "character.h"
#include <string>

Character::Character(std::string name, int health, unsigned int damage) :
                    name(name),
                    health(health),
                    damage(damage) {}

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

void Character::GetAttacked(const Character& enemy){
  health -= enemy.GetDamage();
  if(health < 0){
    health = 0;
  }
}

void Character::Attack(Character& enemy) const{
  enemy.GetAttacked(*this);
}

std::ostream& operator<<(std::ostream& os, const Character& character)
{
    os << ":name: " << character.GetName() << ": HP: " << character.GetHealth() << ", DMG: " << character.GetDamage() << '\n';
    return os;
}
