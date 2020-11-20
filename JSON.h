#ifndef JSON_H
#define JSON_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<map>
#include <sstream>

class JSON
{
public:
	JSON(std::map<std::string, std::string> hero_map, std::map<std::string, std::string> monsters_map) : hero_map(hero_map), monsters_map(monsters_map) {};

	static JSON parseFromFile(const std::string& fileName);
	int count(const std::string& type);
	template <class T>
	T get(T type)
	{
		if (type == "hero")
		{
			return hero_map.find("hero")->second;

		}
		else if (type == "monsters")
		{
			return monsters_map.find("monsters")->second;
		}
		else
		{
			return "";
		}
	};
	static std::map<std::string, std::string> parseUnitFromStream(std::ifstream* stream);
	static std::map<std::string, std::string> parseUnitFromFileName(const std::string& fileName);
	class ParseException : public std::runtime_error
	{
	public:
		explicit ParseException(const std::string& content) : std::runtime_error(content) {}
	};
private:
	 std::map<std::string, std::string> hero_map;
	std::map<std::string, std::string> monsters_map;
	
	static std::vector<std::string> splittedString(std::string text, char delimiter);
	static std::map<std::string, std::string> parse(const std::string text);
};

#endif //JSON_H
