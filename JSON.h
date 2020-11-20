#ifndef JSON_HEADER
#define JSON_HEADER

#include <map>
#include <string>
#include <any>
#include <iostream>

class JSON
{
    std::map<std::string, std::any> data;

private:
    static void Validator(const std::string&);
    static bool isNumber(const std::string&);

public:
    JSON(std::map<std::string, std::any>);
    int count(const std::string&);
    static JSON parseFromString(const std::string&);
    static JSON parseFromStream(std::istream&);
    static JSON parseFromFile(const std::string&);

    template <typename T>
    T get(const std::string& key)
    {
        return std::any_cast<T>(data[key]);
    }

    class ParseException : virtual public std::runtime_error
    {
    public:
        explicit ParseException(const std::string& description) : std::runtime_error("Parsing error: " + description) {}
    };

};

#endif 