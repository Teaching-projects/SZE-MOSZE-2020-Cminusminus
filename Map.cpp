#include "Map.h"


Map::Map(std::string filename)
{
	std::ifstream ifst;
	std::string line;
	
	ifst.open(filename);
	while(!ifst.eof())
	{
		std::getline(ifst, line);
		map.push_back(line);
	}
}

Map::type Map::get(int x, int y) const
{
	if (x < 0 || x >= (int)map.size())
	{
		throw WrongIndexException("Wrong index!");
	}
	else if (y < 0 || y >= (int)map[x].length())
	{
		throw WrongIndexException("Wrong index!");
	}

	std::string types = " #";
	return type(types.find(map[x][y]));
}