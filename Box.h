#pragma once

#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "StateMachine.cpp"
#include "VisualBox.h"

#include "SFML/Graphics.hpp"

class Box : public VisualBox
{
private:	
	bool bomb = false;
	int nearbombs = 0;

public:
	Box();
	void setPos(sf::Vector2f position);
	void setState(stateBox state);
	void bombRandom();
	void setNearBomb();
	void discover();
	void setType();

	sf::RectangleShape get_box();
	bool getBomb() { return bomb; }
	int getNearBombs() { return nearbombs; }
	stateBox getState();
};

#endif //!BOX_H
