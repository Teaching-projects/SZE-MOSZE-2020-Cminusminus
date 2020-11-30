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




const std::map<int, std::string> error_messages = {
	{ 1 , "Bad number of arguments. Only a single scenario file should be provided." },
	{ 2 , "The provided scenario file is not accessible." },
	{ 3 , "The provided scenario file is invalid." },
	{ 4 , "JSON parsing error." }
};

void bad_exit(int exitcode) {
	std::cerr
		<< (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
		<< std::endl;
	exit(exitcode);
}

int main(int argc, char** argv) {
	try{
		PreparedGame game("game.json");
		game.run();
	}
	catch (const Map::WrongIndexException& e)
	{
		std::cout << e.what();
	}
	catch (const Game::AlreadyHasUnitsException& e)
	{
		std::cout << e.what();
	}
	catch (const Game::GameAlreadyStartedException& e)
	{
		std::cout << e.what();
	}
	catch (const Game::OccupiedException& e)
	{
		std::cout << e.what();
	}
	catch (const Game::AlreadyHasHeroException& e)
	{
		std::cout << e.what();
	}
	catch (const Game::NotInitializedException& e)
	{
		std::cout << e.what();
	}
	catch (const Game::NotInitializedException& e)
	{
		std::cout << e.what();
	}
	catch (const JSON::ParseException& e)
	{
		std::cout << e.what();
	}
}