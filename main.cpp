#include <iostream>

#include <character.h>
#include <string>

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

int checkHealthOrDamageInputArgument(char *argument){
  int number;
  try {
    number = std::atoi(argument);
  } catch (...) {}

  return number;
}

int main(int argc, char *argv[])
{
  if(argc != 7){
    std::cout << "Something is wrong with the arguments.\nExample: Maple 150 10 Sally 45 30\n";
    return 1;
  }
  else{
    std::string character1_name(argv[1]);

    int character1_health = checkHealthOrDamageInputArgument(argv[2]);
    if(character1_health == 0){
      std::cout << argv[2] << " is not valid for health\n";
      return 1;
    }

    int character1_damage = checkHealthOrDamageInputArgument(argv[3]);
    if(character1_damage == 0){
      std::cout << argv[3] << " is not valid for damage\n";
      return 1;
    }

    Character character1(character1_name, character1_health, character1_damage);

    std::string character2_name(argv[4]);

    int character2_health = checkHealthOrDamageInputArgument(argv[5]);
    if(character2_health == 0){
      std::cout << argv[5] << " is not valid for health\n";
      return 1;
    }

    int character2_damage = checkHealthOrDamageInputArgument(argv[6]);
    if(character2_damage == 0){
      std::cout << argv[6] << " is not valid for damage\n";
      return 1;
    }

    Character character2(character2_name, character2_health, character2_damage);

    battle(character1, character2);
  }

  return 0;
}
