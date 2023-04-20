#pragma once
#ifndef GRID_H
#define GRID_H

#include "SFML/Graphics.hpp"

#include "StateMachine.cpp"
#include "Box.h"
#include "vector"

class Grid
{
private:
	int _size = 200, _numbox = 5;
	stateLevel _level = stateLevel::easy;
	Box** box = new Box*;
	sf::Text** text = new sf::Text*;
	sf::Font font;
public:
	Grid();
	Grid(stateLevel level);
	void run();
	void level();
	void gridElement();
	void CounterBomb_level();
};
#endif // !GRID_H


