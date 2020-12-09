#include "Game.h"

Game::Game() { }

Game::Game(const std::string& mapfilename) : fileName(mapfilename)
{
	Map map(mapfilename);
	setMap(map);
	setMaxCols(map.getMaxCols());
}

void Game::setMap(const Map& map)
{
	if (heroPut || monsterPut)
	{
		const std::string hasUnits = "The units are already set up. Map cannot be changed.";
		throw AlreadyHasUnitsException(hasUnits);
	}
	if (gameStarted)
	{
		const std::string gameStarted = "Game already started!";
		throw GameAlreadyStartedException(gameStarted);
	}
	mapToSet = map;
	mapSet = true;
}

void Game::putHero(const Hero& hero, const int x, const int y)
{
	if (mapSet == false)
	{
		throw Map::WrongIndexException("No map initialized!");
	}
	if (mapToSet.get(x, y) == 1)
	{
		const std::string wall = "There's a wall in this position!\n";
		throw OccupiedException(wall);
	}
	if (heroPut)
	{
		const std::string hasHero = "A hero has already been set!";
		throw AlreadyHasHeroException(hasHero);
	}
	if (gameStarted)
	{
		const std::string gameStarted = "Game has already started!";
		throw GameAlreadyStartedException(gameStarted);
	}

	heroPos = std::make_pair(x,y);
	mapHero = new Hero(hero);
	heroPut = true;
}

void Game::putMonster(const Monster& monster, const int x, const int y)
{
	if (mapSet == false)
	{
		throw Map::WrongIndexException("No map initialized!");
	}
	if (mapToSet.get(x, y) == 1)
	{
		const std::string wall = "There's a wall in this position!\n";
		throw OccupiedException(wall);
	}
	if (monsterPut == false)
	{
		mapMonsters.push_back(std::make_pair(monster, std::make_pair(x, y)));
		monsterPut = true;
	}
	else
	{
		mapMonsters.push_back(std::make_pair(monster, std::make_pair(x, y)));
	}
}

Map Game::getMap() const
{
	return mapToSet;
}

std::vector<std::pair<Monster, std::pair<int, int>>> Game::getMonsters() const
{
	return mapMonsters;
}

Hero* Game::getHero() const
{
	return mapHero;
}

std::pair<int, int> Game::getHeroPos() const
{
	return heroPos;
}

std::string Game::getFileName() const
{
	return fileName;
}

void Game::run()
{

	if ((heroPut == false) || (mapSet == false))
	{
		const std::string notInit = "The game is not initialized!";
		throw NotInitializedException(notInit);
	}

	std::string move;
	gameStarted = true;
	unsigned int deadMonsterCount = 0;

	while (mapMonsters.size() > deadMonsterCount && mapHero->isAlive())
	{
		for (int i = 0; i < (int)mapMonsters.size(); i++)
		{
			if (((mapMonsters[i].second.first == heroPos.first) && (mapMonsters[i].second.second == heroPos.second))&&(mapMonsters[i].first.isAlive()))
			{
				mapHero->fightTilDeath(mapMonsters[i].first);
				if (mapMonsters[i].first.isAlive() == false)
				{
					deadMonsterCount++;
					if (deadMonsterCount == mapMonsters.size())
					{
						break;
					}
				}
				else if(mapHero->isAlive() == false)
				{
					std::cout << "The hero died." << std::endl;
					heroPut = false;
				}

			}
		}
		if (heroPut==false || mapMonsters.size() == deadMonsterCount)
		{
			gameStarted = false;
			break;
		}
		for (auto p : renderers)
		{
			p->render(*this);
		}
		std::cin >> move;
		try
		{
			if (move == "north")
			{
				moveHero(heroPos.first - 1, heroPos.second);
			}
			if (move == "south")
			{
				moveHero(heroPos.first + 1, heroPos.second);
			}
			if (move == "west")
			{
				moveHero(heroPos.first, heroPos.second - 1);
			}
			if (move == "east")
			{
				moveHero(heroPos.first, heroPos.second + 1);
			}
		}
		catch (OccupiedException& e)
		{
			std::cout << "There's a wall in this position!\n";
			continue;
		}
	}
	
	if (deadMonsterCount == mapMonsters.size())
	{
		for (auto p : renderers)
		{
			p->render(*this);
		}
		std::cout << mapHero->getName() << " cleared the map." << std::endl;
	}
}

int Game::monsterCount(const int x, const int y) const
{
	int count = 0;
	for (int i = 0; i < (int)mapMonsters.size(); i++)
	{
		if (mapMonsters[i].second.first == x && mapMonsters[i].second.second == y && mapMonsters[i].first.isAlive())
		{
			count++;
		}
	}
	return count;
}

void Game::registerRenderer(Renderer* renderer)
{
	renderers.push_back(renderer);
}

void Game::moveHero(int x, int y)
{
	if (mapToSet.get(x, y) == 1) 
	{
		const std::string wall = "There's a wall in this position!\n";
		throw OccupiedException(wall);
	}

	heroPos = std::make_pair(x, y);
}

void Game::setMaxCols(int mc)
{
	maxColumns = mc;
}
