#include "JSON.h"
#include <string>

JSON::JSON(map_data input_datas) : input_datas(input_datas) {}

JSON JSON::parseFromStream(std::istream& inputStream) 
{

	std::string line = "";
	std::string input_txt = "";

	while (std::getline(inputStream, line))
	{
		input_txt += line;
	}

	return parseFromString(input_txt);
}

std::string JSON::word_split(std::string& line) 
{

	std::size_t first_index = 0;
	std::size_t last_index = line.length() - 1;

	while (first_index < line.length() && (line[first_index] == '{' || line[first_index] == '\"' || line[first_index] == '[' || line[first_index] == ']' || line[first_index] == '\t' || line[first_index] == ' ' )) 
	{ 
		first_index++; 
	}
	while ((line[last_index] == ' ' || line[last_index] == '\t' || line[last_index] == '\"' || line[last_index] == '[' || line[last_index] == ']' || line[last_index] == '}')) 
	{
		last_index--; 
	}

	return line.substr(first_index, last_index - first_index + 1);
}

JSON JSON::parseFromFile(const std::string& filename) 
{

	std::ifstream stream(filename);

	if (stream.fail())
	{
		throw ParseException("Can't open the json file.");
	}

	std::string line;
	std::string textFromInput = "";

	while (std::getline(stream, line))
	{
		textFromInput += line;
	}

	stream.close();
	return parseFromString(textFromInput);
}

JSON JSON::parseFromString(const std::string& inputtext)
{
	map_data hero_data;

	std::size_t current_position = 1;
	std::size_t colon_num = 0;
	std::size_t comma_num = 0;
	std::size_t data_num = 0;

	std::string key;
	std::string key_value;
	std::string monsterList;

	while (current_position < inputtext.length())
	{
		bool position_good = true;
		int colon_position = inputtext.find(':', current_position);
		int comma_position = current_position;

		while (comma_position < (int)inputtext.length() && (!position_good || inputtext[comma_position] != ','))
		{
			if (inputtext[comma_position] == '\"')
			{
				position_good = !position_good;
			}
			++comma_position;
		}

		if (inputtext[comma_position] == ',')
		{
			comma_num++;
		}

		if (comma_position < 0)
		{
			comma_position = inputtext.length();
		}

		if (colon_position >= 0)
		{
			colon_num++;
			key = inputtext.substr(current_position + 1, colon_position - current_position - 1);
			key_value = inputtext.substr(colon_position + 1, comma_position - (colon_position + 1));

			int monsterListStart = (int)key_value.find('[');

			if (monsterListStart >= 0)
			{
				int monsterListEnd = (int)inputtext.find(']', monsterListStart + 1);

				if (monsterListEnd < 0)
				{
					throw "Incorrect json format";
				}

				key_value = inputtext.substr(colon_position + monsterListStart + 2, inputtext.find(']', monsterListStart + 1) - (colon_position + monsterListStart + 2));
				key = word_split(key);

				std::string monster_files = "";
				unsigned int filenameStartPos = 0;
				while (filenameStartPos < (unsigned int)key_value.length())
				{
					int nextCommaInList = (int)key_value.find(',', filenameStartPos);
					if (nextCommaInList < 0)
					{
						nextCommaInList = (int)key_value.length() - 1;
					}
					std::string filename = key_value.substr(filenameStartPos + 1, nextCommaInList - (filenameStartPos + 1));
					filename = word_split(filename);
					monster_files += filename + ",";
					filenameStartPos = (unsigned int)nextCommaInList + 1;
				}

				monster_files.erase(monster_files.end() - 1);
				hero_data[key] = monster_files;
				data_num++;
				comma_position = monsterListEnd;

				if (monster_files.find(',' != std::string::npos))
				{
					comma_num--;
				}
			}
			else
			{
				bool string_keyvalue = key_value.find('\"') != std::string::npos;
				key = word_split(key);
				key_value = word_split(key_value);
				if (string_keyvalue)
				{
					hero_data[key] = key_value;
				}
				else if (key_value.find('.') != std::string::npos)
				{
					hero_data[key] = std::stod(key_value);
				}
				else
				{
					hero_data[key] = std::stoi(key_value);
				}

				data_num++;
			}
		}

		current_position = comma_position + 1;
	}
	return JSON(hero_data);
}

JSON::ParseException::ParseException(std::string exceptionString) : std::runtime_error(exceptionString) {}

