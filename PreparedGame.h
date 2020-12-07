#pragma once
#ifndef PREPAREDGAME_H
#define PREPAREDGAME_H

#include "Game.h"
#include "MarkedMap.h"

class PreparedGame : public Game
{
	/**
*\brief A class for loading a prepared game.
*\param filename The filename we load from.
*/
public:
	PreparedGame(const std::string filename);

};
#endif