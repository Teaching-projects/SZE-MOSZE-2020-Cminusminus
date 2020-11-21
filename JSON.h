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

    template <typename T>
    T get(const std::string& key)
    {
        if (inputdatas.find(key) == inputdatas.end()) throw "Wrong JSON key!";
        try {
            return std::get<T>(inputdatas[key]);
        }
        catch (const std::exception & e) {
            throw ParseException("Wrong JSON type!");
        }
    }

    JSON(jsonMap _inputdatas) : inputdatas(_inputdatas) {}

    static JSON parseFromFile(const std::string& filename);

    static JSON parseFromString(const std::string& inputtext);

    static JSON parseFromStream(std::istream& inputStream);

    bool count(std::string key) { return inputdatas.count(key); }


    class ParseException : public std::string
    {
    private:
        std::string msg;

    public:
        ParseException(std::string msg) : msg(msg) {}
        ~ParseException() {}
    };
};

#endif 