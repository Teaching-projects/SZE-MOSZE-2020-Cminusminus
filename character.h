#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<memory>

class Character
{
public:
  Character(std::string name, int health, unsigned int damage);

  std::string GetName() const;
  int GetHealth() const;
  unsigned int GetDamage() const;
  bool IsAlive() const;
  void GetAttacked(const Character& enemy);
  void Attack(Character& enemy) const;
  friend std::ostream& operator<<(std::ostream& os, const Character& character);
private:
  const std::string name;
  int health;
  const unsigned int damage;
};

#endif // CHARACTER_H
