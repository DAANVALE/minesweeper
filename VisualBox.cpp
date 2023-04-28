#include "VisualBox.h"

VisualBox::VisualBox() {
	this->state = stateBox::cover;
}

void VisualBox::setVisual(stateBox state) {
	switch (state)
	{
	case stateBox::cover:
		setCover();
		break;
	case stateBox::flag:
		setFlag();
		break;
	case stateBox::bomb:
		setBomb();
		break;
	case stateBox::nearBomb:
		setNearBomb();
		break;
	case stateBox::empty:
		setEmpty();
		break;
	default:
		break;
	}
}

void VisualBox::setCover() {
	visual_box.setFillColor(sf::Color(0, 255, 0, 100));
}

void VisualBox::setBomb() {
	visual_box.setFillColor(sf::Color(0, 255, 255, 100));
}

void VisualBox::setNearBomb() {
	visual_box.setFillColor(sf::Color(150, 155, 200, 100));
}

void VisualBox::setEmpty() {
	visual_box.setFillColor(sf::Color(255, 255, 255, 0));
}

void VisualBox::setFlag(){
	if (state == stateBox::cover) {
		visual_box.setFillColor(sf::Color(250, 0, 0, 100));
	}
	else if (state == stateBox::flag){
		state == stateBox::cover;
	}
}

sf::RectangleShape VisualBox::getVisualBox() {
	return this->visual_box;
}