#include "JSON.h"
#include <iostream>

#include <fstream>
#include <regex>

JSON::JSON(std::map<std::string, std::any> data) : data(data)
{
}

void JSON::Validator(const std::string& text)
{
    static const std::regex JSONvalidator("^\\s*\\{(\\s*(\"[a-zA-Z0-9_]+\")\\s*:\\s*(\"[^\"]+\"|\\d+.\\d+|\\d+)\\s*,*)*\\s*\\}\\s*$");

    if (!std::regex_match(text, JSONvalidator))
    {
        throw std::runtime_error("Invalid Json!");
    }
}

int JSON::count(const std::string& key)
{
    return data.count(key);
}

JSON JSON::parseFromString(const std::string& input)
{
    std::string text = input;
    std::map<std::string, std::any> mapedData;

    Validator(text);

    static const std::regex JSONparser("\\s*(\"[a-zA-Z0-9_]+\")\\s*:\\s*(\"[^\"]+\"|\\d+.\\d+|\\d+)\\s*[,}]\\s*");
    std::smatch match;

    while (std::regex_search(text, match, JSONparser))
    {
        if (match.size() == 3)
        {
            std::string key = match[1].str();
            std::string value = match[2].str();

            key.erase(remove(key.begin(), key.end(), '\"'), key.end());
            value.erase(remove(value.begin(), value.end(), '\"'), value.end());

            if (isNumber(value))
            {
                if (value.find(".") != std::string::npos)
                {
                    mapedData[key] = stof(value);
                }
                else
                {
                    mapedData[key] = stoi(value);
                }
            }
            else
            {
                mapedData[key] = value;
            }
        }
        text = match.suffix();
    }
    return JSON(mapedData);
}

JSON JSON::parseFromStream(std::istream& stream)
{
    std::string text, currentLine;

    while (getline(stream, currentLine))
    {
        text.append(currentLine);
    }
    return parseFromString(text);
}

JSON JSON::parseFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("file " + filename + " doesn't exist");

    return  parseFromStream(file);
}

bool JSON::isNumber(const std::string& x)
{
    std::regex e("^[0-9.]*$");
    if (std::regex_match(x, e)) return true;
    else return false;
}