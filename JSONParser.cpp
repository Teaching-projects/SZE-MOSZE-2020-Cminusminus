#include "JSONParser.h"
#include "character.h"
#include "characterMaker.h"

Character* JSONParser::parseUnitFromStream(std::ifstream* stream){
    std::string fileContent = "";
    std::string line;
    int lineIndex = 0;
    if(stream->is_open()){
        while (std::getline(*stream, line))
        {
            fileContent += line + '\n';
        }
        stream->close();
    }
    else 
    {
        throw 1;
    }

    CharacterMaker characterMaker;
    return characterMaker.createCharacter(fileContent);
}

Character* JSONParser::parseUnitFromFileName(const std::string& fileName){
    std::ifstream characterDataFile;

    characterDataFile.open(fileName);
    return parseUnitFromStream(&characterDataFile);
}

Character* JSONParser::parseUnitFromContent(const std::string& content){
    CharacterMaker characterMaker;
    return characterMaker.createCharacter(content);
}
