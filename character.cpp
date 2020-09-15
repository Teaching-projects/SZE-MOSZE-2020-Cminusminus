#include "character.h"

Character::Character(const std::string name, int health, const unsigned int damage) :
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

void Character::TakeDamage(const int damage){
  health -= damage;
  health < 0 ? 0 : health;
}

void Character::Attack(Character& enemy) const{
  enemy.TakeDamage(damage);
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Character> character)
{
    os << character->GetName() << ": HP: " << character->GetHealth() << ", DMG: " << character->GetDamage() << '\n';
    return os;
}
