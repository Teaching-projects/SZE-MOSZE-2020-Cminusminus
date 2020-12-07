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
	Map() {};
	Map(const std::string filename);
	
	///\brief The enum ,,type" for the map
	enum type
	{
		///This represents the free spaces: ' '
		Free,
		///This represents the walls: '#'
		Wall 
	};

	class WrongIndexException : public std::runtime_error
	{
	/**
	*\brief A class to handle out of index.
	*\param exceptionString The string we name the exception.
	*/
	public:
		WrongIndexException(const std::string& exceptionString) : std::runtime_error(exceptionString) {};
	};

	///\brief Function to get the free spaces or the walls on the map.
	///\param x The rows of the map
	///\param y The columns of the map
	///\return Map::type
	virtual Map::type get(const int x, const int y) const;
	///\brief A function to get the columns number of the map.
	///\param x The x coordinates
	///\return int
	int getColumns(const int x) const;
	///\brief A function to get the rows number of the map.
	///\return int
	int getRows() const;
	///\brief A function to get the max columns number of the map.
	///\return int
	int getMaxCols() const;
	///\brief It returns the stored map
	///\return int
	std::vector<std::string> getMap() const;

private:
	std::vector<std::string> map;
};

#endif