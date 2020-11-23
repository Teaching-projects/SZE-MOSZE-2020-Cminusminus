#pragma once
#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Map
{
/**
*\brief A class for loading a map.
*\param filename The filename we load.
*/

public:
	Map(std::string filename);
	
	///brief The enum ,,type" for the map
	enum type
	{
		Free, ///This represents the free spaces: ' '
		Wall ///This represents the walls: '#'
	};

	class WrongIndexException : std::exception
	{
	/**
	*\brief A class to handle out of index.
	*\param exceptionString The string we name the exception.
	*/
	public:
		WrongIndexException(std::string exceptionString) : exceptionString(exceptionString) {}
	private:
		std::string exceptionString;
	};

	///brief Function to get the free spaces or the walls on the map.
	///\param x The rows of the map
	///\param y The columns of the map
	///\return Map::type
	Map::type get(int x, int y) const;

private:
	std::vector<std::string> map;
};

#endif