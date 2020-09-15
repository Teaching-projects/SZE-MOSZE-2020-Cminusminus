#include "character.h"

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

bool Character::IsAlive(){
  return health > 0;
}

void Character::TakeDamage(const int damage){
  health -= damage;
  if(health < 0){
    health = 0;
  }
}

void Character::Attack(std::shared_ptr<Character> enemy){
  enemy->TakeDamage(damage);
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Character>& character)
{
    os << character->GetName() << ": HP: " << character->GetHealth() << ", DMG: " << character->GetDamage() << '\n';
    return os;
}
