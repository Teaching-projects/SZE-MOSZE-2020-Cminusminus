#pragma once
#ifndef MARKEDMAP_H
#define MARKEDMAP_H

#include "Map.h"
#include <list>

class MarkedMap : public Map
{

/**
*\brief A class for loading a marked map.
*\param filename The filename we load.
*/

public:
	MarkedMap(std::string filename) : Map(filename) {};
	///\brief Function to get the hero's position.
	///\return std::pair<int,int>
	std::pair<int,int> getHeroPosition() const;
	///\brief Function to get the monster's position.
	///\param c The monster's type we want to get
	///\return std::list<std::pair<int,int>>
	std::list<std::pair<int,int>> getMonsterPosition(const char c) const;
};
#endif