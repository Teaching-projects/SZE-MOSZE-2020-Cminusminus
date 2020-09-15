#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include <character.h>

class GameManager
{
public:
  GameManager();
  static GameManager* Instance();
  void Battle(std::shared_ptr<Character> character1, std::shared_ptr<Character> character2);

private:
  static GameManager* instance;
};

#endif // GAMEMANAGER_H
