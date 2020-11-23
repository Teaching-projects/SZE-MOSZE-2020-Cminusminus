#pragma once
#ifndef JSON_H
#define JSON_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <variant>
#include <list>


typedef std::map<std::string, std::variant<std::string, int, double>> map_data;

class JSON
{
private:
	static std::string word_split(std::string& line);
	map_data input_datas;
public:
	/**
	*\brief A class for JSON parsing.
	*\param _input_datas The map_data we give.
	*/
	JSON(map_data input_datas) : input_datas(input_datas) {}

	typedef std::list<std::variant<std::string, int, double>> list;
	
	///\brief Get function for the JSON class.
	///\param key the JSON element's key
	///\return T template
	template <typename T>
	inline typename std::enable_if<std::is_same<T, JSON::list>::value, JSON::list>::type get(const std::string& key)
	{
		if (!input_datas.count(key))
		{
			throw "No json key found!";
		}

		JSON::list monsters;

		std::string input_list = std::get<std::string>(input_datas[key]);
		std::string value;

		int pos = 0;

		while (pos < (int)input_list.length())
		{
			int comma = input_list.find(',', pos);
			if (comma < 0)
			{
				comma = (int) input_list.length();
			}

			value = input_list.substr(pos, comma - pos);
			monsters.push_back(value);

			pos = comma + 1;
		}

		return monsters;
	}

	///\brief Count function for the JSON class.
	///\param key The name of the key
	///\return bool
	bool count(std::string key) { return input_datas.count(key); }

	static JSON parseFromFile(const std::string& filename);
	static JSON parseFromString(const std::string& inputtext);
	static JSON parseFromStream(std::istream& inputStream);

	///\brief Get function for the JSON class.
	///\param key the JSON element's key
	///\return T template
	template <typename T>
	inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type get(const std::string& key)
	{
		if (input_datas.find(key) == input_datas.end()) throw "Wrong JSON key!";
		try {
			return std::get<T>(input_datas[key]);
		}
		catch (const std::exception& e) {
			throw ParseException("Wrong JSON type!");
		}
	}

	class ParseException : public std::string
	{
		/**
  *\brief A class for JSON errors.
  *\param exceptionString The string for the error.
  */
	public:
		ParseException(std::string exceptionString) : exceptionString(exceptionString) {}
		~ParseException() {}
	private:
		std::string exceptionString;
	};
};

#endif 