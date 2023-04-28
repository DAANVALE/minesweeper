#pragma once
#ifndef VISUAL_BOX
#define VISUAL_BOX

#include "SFML/Graphics.hpp"

#include "StateMachine.cpp"

class VisualBox
{
protected:
	sf::RectangleShape visual_box;
	stateBox state;
public:
	VisualBox();
	~VisualBox() {};
	void setVisual(stateBox state);
	void setCover();
	void setFlag();
	void setBomb();
	void setNearBomb();
	void setEmpty();

	sf::RectangleShape getVisualBox();
};

#endif // !VISUAL_BOX
