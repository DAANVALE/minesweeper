#pragma once

#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "StateMachine.cpp"
#include "SFML/Graphics.hpp"

class Box
{
private:	
	bool bomb = false;
	int nearbombs = 0;
	sf::RectangleShape _box;
	stateBox state;
public:
	Box();
	void setPos(sf::Vector2f position);
	void setState(stateBox state);
	void bombRandom();
	void setNearBomb();
	void setType();

	sf::RectangleShape get_box();
	bool getBomb() { return bomb; }
	int getNearBombs() { return nearbombs; }
	stateBox getState();
};

#endif //!BOX_H
