#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<memory>

class Character
{
public:
  Character(const std::string& name, int health, int damage);

  std::string GetName() const;
  int GetHealth() const;
  void SetHealth(const int health);
  int GetDamage() const;
  void GainDamage(const double multiplier);
  bool IsAlive() const;
  void GetAttacked(const Character& enemy);
  void Attack(Character& enemy) const;
private:
  const std::string name;
  int health;
  int damage;
};

#endif // CHARACTER_H
