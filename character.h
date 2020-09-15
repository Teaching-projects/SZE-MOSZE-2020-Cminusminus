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
  bool IsAlive();
  void TakeDamage(const int damage);
  void Attack(std::shared_ptr<Character> enemy);
  friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Character>& character);
private:
  std::string name;
  int health;
  unsigned int damage;
};

#endif // CHARACTER_H
