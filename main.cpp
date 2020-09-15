#include <iostream>

#include <gamemanager.h>

int main()
{
  GameManager* game_manager = game_manager->Instance();

  std::shared_ptr<Character> Maple(new Character("Maple", 150, 50));
  std::shared_ptr<Character> Sally(new Character("Sally", 45, 30));

  game_manager->Battle(Maple, Sally);

  return 0;
}
