#include "Map.h"


Map::Map(const std::string& filename)
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

	while(!ifst.eof() && ifst.is_open())
	{
		std::getline(ifst, line);
		map.push_back(line);
	}
	ifst.close();
}

Map::type Map::get(const int x, const int y) const
{
	if (x < 0 || x >= (int)map.size())
	{
		throw WrongIndexException("Wrong index!");
	}
	else if (y < 0 || y >= (int)map[x].length())
	{
		throw WrongIndexException("Wrong index!");
	}

	if (map[x][y] == '#')
	{
		return type(1);
	}
	else if(map[x][y] == ' ')
	{
		return type(0);
	}
	return type(-1);
}

int Map::getColumns(const int x) const
{
	return map[x].length();
}

int Map::getRows() const
{
	return map.size();
}

int Map::getMaxCols() const
{
	int max = 0;
	for (int i = 0; i < (int)map.size(); i++)
	{
		if (max < (int)map[i].length())
		{
			max = map[i].length();
		}
	}
	return max;
}

std::vector<std::string> Map::getMap() const
{
	return map;
}

Map::WrongIndexException::WrongIndexException(const std::string& exceptionString) : std::runtime_error(exceptionString) {}