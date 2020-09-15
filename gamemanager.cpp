#include "gamemanager.h"

GameManager* GameManager::instance = 0;

GameManager* GameManager::Instance() {
  if (!instance) {
    instance = new GameManager();
  }
  return instance;
}

GameManager::~GameManager(){
  delete instance;
}

void GameManager::Battle(std::shared_ptr<Character> character1, std::shared_ptr<Character> character2){
  while (character1->IsAlive() && character2->IsAlive()) {
    std::cout << character1;
    std::cout << character2;
    std::cout << character1->GetName() << " -> " << character2->GetName() << '\n';

    character1->Attack(*character2);
    std::cout << character1;
    std::cout << character2;

    if(character2->IsAlive()){
      std::cout << character2->GetName() << " -> " << character1->GetName() << '\n';
      character2->Attack(*character1);
    }
  }

  if(character1->IsAlive()){
    std::cout << character2->GetName() << " died. " << character1->GetName() << " wins.\n";
  }
  else{
    std::cout << character1->GetName() << " died. " << character2->GetName() << " wins.\n";
  }
}
