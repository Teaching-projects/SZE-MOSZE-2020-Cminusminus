#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<memory>

class Character
{
public:
  Character(const std::string name, int health, const unsigned int damage);

  std::string GetName() const;
  int GetHealth() const;
  unsigned int GetDamage() const;
  bool IsAlive() const;
  void TakeDamage(const int damage);
  void Attack(Character& enemy) const;
  friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Character> character);
private:
  const std::string name;
  int health;
  const unsigned int damage;
};

#endif // CHARACTER_H
