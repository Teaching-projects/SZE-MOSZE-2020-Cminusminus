#pragma once

#include <string>
#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include <vector>


class Game
{
public:
	Game();
	Game(std::string mapfilename);
	~Game()
	{
		delete mapHero;
	};
	void setMap(Map map);
	void putHero(Hero hero, int x, int y);
	void putMonster(Monster monster, int x, int y);
	
	void run();
	void mapDraw();
	int monsterCount(int x, int y);
	void moveHero(int x, int y);

	class OccupiedException : std::exception
	{
		/**
		*\brief A class to handle out of index.
		*\param exceptionString The string we name the exception.
		*/
	public:
		OccupiedException(std::string exceptionString) : exceptionString(exceptionString) {}
	private:
		std::string exceptionString;
	};

	class AlreadyHasHeroException : std::exception
	{
		/**
		*\brief A class to handle out of index.
		*\param exceptionString The string we name the exception.
		*/
	public:
		AlreadyHasHeroException(std::string exceptionString) : exceptionString(exceptionString) {}
	private:
		std::string exceptionString;
	};

	class AlreadyHasUnitsException : std::exception
	{
		/**
		*\brief A class to handle out of index.
		*\param exceptionString The string we name the exception.
		*/
	public:
		AlreadyHasUnitsException(std::string exceptionString) : exceptionString(exceptionString) {}
	private:
		std::string exceptionString;
	};

	class NotInitializedException : std::exception
	{
		/**
		*\brief A class to handle out of index.
		*\param exceptionString The string we name the exception.
		*/
	public:
		NotInitializedException(std::string exceptionString) : exceptionString(exceptionString) {}
	private:
		std::string exceptionString;
	};

	class GameAlreadyStartedException : std::exception
	{
		/**
		*\brief A class to handle out of index.
		*\param exceptionString The string we name the exception.
		*/
	public:
		GameAlreadyStartedException(std::string exceptionString) : exceptionString(exceptionString) {}
	private:
		std::string exceptionString;
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