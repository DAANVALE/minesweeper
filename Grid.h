#pragma once
#ifndef GRID_H
#define GRID_H

#include "SFML/Graphics.hpp"

#include "StateMachine.cpp"
#include "Box.h"
#include "vector"

#include <chrono>
#include <thread>

class Grid
{
private:
	int _size = 200, _numbox = 5;
	stateLevel _level = stateLevel::easy;
	stateGame _game = stateGame::start;
	Box** box = new Box*;
	sf::Text** text = new sf::Text*;
	sf::Font font;
public:
	//input manager
	Grid();
	Grid(stateLevel level);
	~Grid() {};
	void run();
	void level();
	void gridElement();
	void counterBomb_level();
	void onClick(sf::RenderWindow &window);
	void Flood(sf::Vector2i vector);
};
#endif // !GRID_H


