#include "Box.h"
#include "SFML/Graphics.hpp"	

using namespace std;

Box::Box(){
	_box.setSize(sf::Vector2f(39,39));
	state = stateBox::cover;
}

void Box::bombRandom() {
	int random = rand() % 20;
	if (random == 12) {
		bomb = true;
		nearbombs = 0;
	}

	setType();
}

void Box::setNearBomb() {
	this->nearbombs++;
}

void Box::setType() {
	if (bomb) {
		_box.setFillColor(sf::Color(0, 255, 255, 100));
	}
	else {
		_box.setFillColor(sf::Color(255, 255, 255, 100));
	}
}

void Box::setPos(sf::Vector2f position) {
	_box.setPosition(position);
}

void Box::setState(stateBox state) {
	this->state = state;
}

sf::RectangleShape Box::get_box() {
	return _box;
}

stateBox Box::getState() {
	return state;
}