#include "MarkedMap.h"

MarkedMap::MarkedMap(std::string filename) : Map(filename)
{
	std::ifstream ifst;
	std::string line;
	try
	{
		ifst.open(filename);
	}
	catch (const std::exception& e)
	{
		throw e.what();
	}

	while (!ifst.eof() && ifst.is_open())
	{
		std::getline(ifst, line);
		markedmap.push_back(line);
	}
	ifst.close();
}

Map::type MarkedMap::get(int x, int y) const
{
	if (x < 0 || x >= (int)markedmap.size())
	{
		throw WrongIndexException("Wrong index!");
	}
	else if (y < 0 || y >= (int)markedmap[x].length())
	{
		throw WrongIndexException("Wrong index!");
	}

	if (markedmap[x][y] == '#')
	{
		return type(1);
	}
	else if (markedmap[x][y] == ' ')
	{
		return type(0);
	}
}

std::pair<int, int> MarkedMap::getHeroPosition() const
{
	for (int i = 0; i < markedmap.size(); i++)
	{
		for (int j = 0; j < markedmap[i].length(); j++)
		{

			if (markedmap[i][j] == 'H')
			{
				return std::make_pair(i, j);
			}
		}
	}
	
	return std::make_pair(-1, -1);
}

std::list<std::pair<int, int>> MarkedMap::getMonsterPosition(char c) const
{
	char type = c;
	std::list <std::pair<int, int>> templist;

	for (int i = 0; i < markedmap.size(); i++)
	{
		for (int j = 0; j < markedmap[i].length(); j++)
		{
			if (markedmap[i][j] == type)
			{

				templist.push_back(std::make_pair(i, j));
			}
		}
	}
	return templist;
	
}

int MarkedMap::getMaxCols()
{
	int max = 0;
	for (int i = 0; i < markedmap.size(); i++)
	{
		if (max < markedmap[i].length())
		{
			max = markedmap[i].length();
		}
	}
	return max;
}
