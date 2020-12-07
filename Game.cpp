#include "Game.h"

Game::Game() { }

Game::Game(std::string mapfilename)
{
	Map map(mapfilename);
	setMap(map);
	setMaxCols(map.getMaxCols());
}

void Game::setMap(Map map)
{
	if (heroPut || monsterPut)
	{
		throw AlreadyHasUnitsException("The units are already set up. Map cannot be changed.");
	}
	if (gameStarted)
	{
		throw GameAlreadyStartedException("Game already started!");
	}
	mapToSet = map;
	mapSet = true;
}

void Game::putHero(Hero hero, int x, int y)
{
	if (mapSet == false)
	{
		throw Map::WrongIndexException("No map initialized!");
	}
	if (mapToSet.get(x, y) == 1)
	{
		throw OccupiedException("There's a wall in this position!\n");
	}
	if (heroPut)
	{
		throw AlreadyHasHeroException("A hero has already been set!");
	}
	if (gameStarted)
	{
		throw GameAlreadyStartedException("The game has already started!");
	}

	heroPos = std::make_pair(x,y);
	mapHero = new Hero(hero);
	heroPut = true;
}

void Game::putMonster(Monster monster, int x, int y)
{
	if (mapSet == false)
	{
		throw Map::WrongIndexException("No map initialized!");
	}
	if (mapToSet.get(x, y) == 1)
	{
		throw OccupiedException("There's a wall in this position!");
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

std::vector<std::pair<std::string, std::string>> Game::getMonsterTexture() const
{
	std::vector<std::pair<std::string, std::string>> textures;
	for (auto p : mapMonsters)
	{
		textures.push_back(std::make_pair(p.first.getName(), p.first.getTexture()));
	}
	return textures;
}

void Game::run()
{

	if ((heroPut == false) || (mapSet == false))
	{
		throw NotInitializedException("The game is not initialized!");
	}

	std::string move;
	gameStarted = true;
	unsigned int deadMonsterCount = 0;

	while (mapMonsters.size() > deadMonsterCount && mapHero != nullptr)
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
		catch (OccupiedException e)
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
	if (heroPut == false)
	{
		mapHero = nullptr;
	}


}

int Game::monsterCount(int x, int y) const
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
		throw OccupiedException("There's a wall in this position!\n");
	}

	heroPos = std::make_pair(x, y);
}

void Game::setMaxCols(int mc)
{
	maxColumns = mc;
}
