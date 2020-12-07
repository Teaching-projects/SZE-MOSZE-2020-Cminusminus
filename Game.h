#pragma once

#include <string>
#include "Hero.h"
#include "MarkedMap.h"
#include "Renderer.h"
#include <vector>

class Renderer; //Forward declaration of the Renderer class.
class Game
{
/**
*\brief A class for load and initialize a game.
*\param mapfilename The name of the map file we load.
*/
public:
	Game();
	Game(const std::string mapfilename);
	~Game()
	{
		delete mapHero;
	};
	///\brief It returns the stored monsters and their positions.
	///\return std::vector<std::pair<Monster, std::pair<int, int>>>
	std::vector<std::pair<Monster, std::pair<int, int>>> getMonsters() const;
	///\brief It returns the stored hero's pointer
	///\return Hero*
	Hero* getHero() const;
	///\brief It returns the stored hero's positions.
	///\return std::pair<int,int>
	std::pair<int, int> getHeroPos() const;
	///\brief A function to run a game.
	void run();
	///\brief A function to set the map for the game.
	///\param map The map we set.
	void setMap(const Map map);
	///\brief A function to put a hero on the map.
	///\param hero The hero we put.
	///\param x the x coordinates.
	///\param y the y coordinates
	void putHero(const Hero hero, const int x, const int y);
	///\brief A function to put a monster on the map.
	///\param monster The monster we put.
	///\param x the x coordinates.
	///\param y the y coordinates
	void putMonster(const Monster monster, const int x, const int y);
	///\brief It returns the stored map.
	///\return Map
	Map getMap() const;
	///\brief A function to count the monsters on the map.
	///\param x The x coordinates
	///\param y the y coordinates
	int monsterCount(const int x, const int y) const;
	///\brief It pushes the given renderer's pointer into a vector.
	void registerRenderer(Renderer* renderer);

protected:
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
	std::vector<Renderer*> renderers;
	int maxColumns = 0;
	bool mapSet = false;
	bool heroPut = false;
	bool monsterPut = false;
	bool gameStarted = false;
};