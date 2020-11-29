#ifndef MARKEDMAP_H
#define MARKEDMAP_H

#include "Map.h"
#include <list>

class MarkedMap : public Map
{
public:
	MarkedMap(std::string filename);
	Map::type get(int x, int y) const override;
	std::pair<int,int> getHeroPosition() const;
	std::list<std::pair<int,int>> getMonsterPosition(char c) const;
private:
	std::vector<std::string> markedmap;
};

#endif