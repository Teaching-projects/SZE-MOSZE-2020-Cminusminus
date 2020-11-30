#pragma once

#include <string>
#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include "MarkedMap.h"
#include <vector>


class Game
{
/**
*\brief A class for load and initialize a game.
*\param mapfilename The name of the map file we load.
*/
public:
	Game();
	Game(std::string mapfilename);
	~Game()
	{
		delete mapHero;
	};
	///\brief A function to run a game.
	void run();
protected:
	///\brief A function to set the map for the game.
	///\param map The map we set.
	void setMap(Map map);
	///\brief A function to put a hero on the map.
	///\param hero The hero we put.
	///\param x the x coordinates.
	///\param y the y coordinates
	void putHero(Hero hero, int x, int y);
	///\brief A function to put a monster on the map.
	///\param monster The monster we put.
	///\param x the x coordinates.
	///\param y the y coordinates
	void putMonster(Monster monster, int x, int y);
	///\brief A function to draw the map for the game.
	void mapDraw();
	///\brief A function to count the monsters on the map.
	///\param x The x coordinates
	///\param y the y coordinates
	int monsterCount(int x, int y);
	///\brief A function to move the hero to a given coordinate.
	///\param x The x coordinates
	///\param y the y coordinates
	void moveHero(int x, int y);
	///\brief A function to set the max columns.
	///\param mc The value we set to max columns.
	void setMaxCols(int mc);
	class OccupiedException : public std::runtime_error
	{
		/**
		*\brief A class to occupied exception.
		*\param exceptionString The string we name the exception.
		*/
	public:
		OccupiedException(std::string exceptionString) : std::runtime_error(exceptionString) {}
	};

	class AlreadyHasHeroException : public std::runtime_error
	{
		/**
		*\brief A class to handle already has a hero exception.
		*\param exceptionString The string we name the exception.
		*/
	public:
		AlreadyHasHeroException(std::string exceptionString) : std::runtime_error(exceptionString) {}

	};

	class AlreadyHasUnitsException : public std::runtime_error
	{
		/**
		*\brief A class to handle already has units exception.
		*\param exceptionString The string we name the exception.
		*/
	public:
		AlreadyHasUnitsException(std::string exceptionString) : std::runtime_error(exceptionString) {}

	};

	class NotInitializedException : public std::runtime_error
	{
		/**
		*\brief A class to handle not initialized exception.
		*\param exceptionString The string we name the exception.
		*/
	public:
		NotInitializedException(std::string exceptionString) : std::runtime_error(exceptionString) {}

	};

	class GameAlreadyStartedException : public std::runtime_error
	{
		/**
		*\brief A class to handle game already started exception.
		*\param exceptionString The string we name the exception.
		*/
	public:
		GameAlreadyStartedException(std::string exceptionString) : std::runtime_error(exceptionString) {}

	};
private:
	Map mapToSet;
	Hero* mapHero = nullptr;
	std::pair<int, int> heroPos;
	std::vector<std::pair<Monster,std::pair<int,int>>> mapMonsters;
	int maxColumns = 0;
	bool mapSet = false;
	bool heroPut = false;
	bool monsterPut = false;
	bool gameStarted = false;
};