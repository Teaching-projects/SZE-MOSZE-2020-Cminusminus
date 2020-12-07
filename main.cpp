#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

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
			game.registerRenderer(new ObserverTextRenderer(new std::ofstream("log.txt")));
			game.registerRenderer(new HeroTextRenderer(new std::ofstream("log2.txt")));
			game.registerRenderer(new CharacterSVGRenderer("pretty.svg"));
			game.registerRenderer(new ObserverSVGRenderer("pretty2.svg"));
			game.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what();
	}
}