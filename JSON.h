#ifndef JSON_H
#define JSON_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <variant>


typedef std::map<std::string, std::variant<std::string, int, float>> jsonMap;

class JSON
{
private:

    static std::string searchandCleanJsonWord(std::string& line);

    static jsonMap parsePair(const std::string& line);
    jsonMap inputdatas; 
public:
  /**
  *\brief A class for JSON parsing.
  *\param _inputdatas The jsonMap we give.
  */
    JSON(jsonMap _inputdatas) : inputdatas(_inputdatas) {}

    static JSON parseFromFile(const std::string& filename);

    static JSON parseFromString(const std::string& inputtext);

    static JSON parseFromStream(std::istream& inputStream);
	
     ///\brief Get function for the JSON class.
     ///\param key the JSON element's key
     ///\return T template
    template <typename T>
    T get(const std::string& key)
    {
        if (inputdatas.find(key) == inputdatas.end())
		{
			throw "There's no key like this.";
		}
        try {
            return std::get<T>(inputdatas[key]);
        }
        catch (const std::exception & e) {
            throw ParseException("Bad JSON! Check the file.");
        }
    }
	 ///\brief Count function for the JSON class.
     ///\param key The name of the key
     ///\return bool
    bool count(std::string key) { return inputdatas.count(key); }


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