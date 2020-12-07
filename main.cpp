#include <iostream>
#include <string>
#include "Map.h"
#include "PreparedGame.h"
#include "MarkedMap.h"
#include "Game.h"
#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Renderer.h"

int main(int argc, char** argv) {
	try{
			PreparedGame game("game.json");
			game.registerRenderer(new HeroTextRenderer());
			game.registerRenderer(new ObserverTextRenderer(new std::ofstream("ObsText.txt")));
			game.registerRenderer(new HeroTextRenderer(new std::ofstream("heroText.txt")));
			game.registerRenderer(new CharacterSVGRenderer("characterSVG.svg"));
			game.registerRenderer(new ObserverSVGRenderer("observerSVG.svg"));
			game.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what();
	}
}