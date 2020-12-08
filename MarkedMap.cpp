#include "MarkedMap.h"

MarkedMap::MarkedMap(std::string filename) : Map(filename) {}

std::pair<int, int> MarkedMap::getHeroPosition() const
{
	for (int i = 0; i < (int)getMap().size(); i++)
	{
		for (int j = 0; j < (int)getMap()[i].length(); j++)
		{

			if (getMap()[i][j] == 'H')
			{
				return std::make_pair(i, j);
			}
		}
	}
	
	return std::make_pair(-1, -1);
}

std::list<std::pair<int, int>> MarkedMap::getMonsterPosition(const char c) const
{
	char type = c;
	std::list <std::pair<int, int>> templist;

	for (int i = 0; i < (int)getMap().size(); i++)
	{
		for (int j = 0; j < (int)getMap()[i].length(); j++)
		{
			if (getMap()[i][j] == type)
			{

				templist.push_back(std::make_pair(i, j));
			}
		}
	}
	return templist;

}
