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
	Map(std::string filename);
	
	///brief The enum ,,type" for the map
	enum type
	{
		///This represents the free spaces: ' '
		Free,
		///This represents the walls: '#'
		Wall 
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
	///brief A function to get the columns number of the map.
	///\param x The x coordinates
	///\return int
	int getColumns(int x);
	///brief A function to get the rows number of the map.
	///\return int
	int getRows();
	///brief A function to get the max columns number of the map.
	///\return int
	int getMaxCols();

private:
	std::vector<std::string> map;
};

#endif