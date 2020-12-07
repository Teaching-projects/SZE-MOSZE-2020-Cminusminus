#include "PreparedGame.h"

PreparedGame::PreparedGame(const std::string filename) : Game()
{
	JSON file = JSON::parseFromFile(filename);

	MarkedMap mm(file.get<std::string>("map"));

	Game::setMap(mm);
	setMaxCols(mm.getMaxCols());
	Game::putHero(Hero::parse(file.get<std::string>("hero")),mm.getHeroPosition().first,mm.getHeroPosition().second);

	for (auto p : mm.getMonsterPosition('1'))
	{
		Game::putMonster(Monster::parse(file.get<std::string>("monster-1")), p.first, p.second);
	}
	for (auto p : mm.getMonsterPosition('2'))
	{
		Game::putMonster(Monster::parse(file.get<std::string>("monster-2")), p.first, p.second);
	}
	for (auto p : mm.getMonsterPosition('3'))
	{
		Game::putMonster(Monster::parse(file.get<std::string>("monster-3")), p.first, p.second);
	}
}
