#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<memory>

class Character
{
public:
  Character(const std::string& name, unsigned long health, unsigned long damage);

  std::string GetName() const;
  int GetHealth() const;
  void SetHealth(const int health);
  unsigned int GetDamage() const;
  void GainDamage(const double multiplier);
  bool IsAlive() const;
  void GetAttacked(const Character& enemy);
  void Attack(Character& enemy) const;
private:
  const std::string name;
  int health;
  unsigned int damage;
};

#endif // CHARACTER_H
