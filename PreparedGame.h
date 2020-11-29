#pragma once
#ifndef PREPAREDGAME_H
#define PREPAREDGAME_H

#include "Game.h"
#include "MarkedMap.h"

class PreparedGame : public Game
{
public:
	PreparedGame(std::string filename);

};
#endif