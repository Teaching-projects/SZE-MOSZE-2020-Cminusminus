#include <iostream>

#include <character.h>

void battle(Character& character1, Character& character2){
  while(character1.IsAlive() && character2.IsAlive()){
    std::cout << character1;
    std::cout << character2;
    std::cout << character1.GetName() << " -> " << character2.GetName() << '\n';

    character1.Attack(character2);
    std::cout << character1;
    std::cout << character2;

    if(character2.IsAlive()){
      std::cout << character2.GetName() << " -> " << character1.GetName() << '\n';
      character2.Attack(character1);
    }
  }

  if(character1.IsAlive()){
    std::cout << character2.GetName() << " died. " << character1.GetName() << " wins.\n";
  }
  else{
    std::cout << character1.GetName() << " died. " << character2.GetName() << " wins.\n";
  }
}

int main()
{
  Character Maple("Maple", 150, 50);
  Character Sally("Sally", 45, 30);

  battle(Maple, Sally);

  return 0;
}
