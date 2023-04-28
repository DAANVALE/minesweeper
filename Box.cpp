#include "Box.h"

using namespace std;

Box::Box(){
	visual_box.setSize(sf::Vector2f(39,39));
	state = stateBox::cover;
}

void Box::bombRandom() {
	int random = rand() % int_level;
	if (random == 2) {
		bomb = true;
		nearbombs = 0;
	}
}

void Box::setLevel(stateLevel type_level) {
	switch (type_level)
	{
	case stateLevel::easy:
		int_level = 20;
		break;
	case stateLevel::medium:
		int_level = 15;
		break;
	case stateLevel::hard:
		int_level = 3;
		break;
	default:
		int_level = 20;
		break;
	}
}

void Box::discover() {
	setType();
}

void Box::setNearBomb() {
	this->nearbombs++;
}

void Box::setType() {
		if (nearbombs == 0) {
			if (bomb) {
				this->state = stateBox::bomb;
			}
			else {
				this->state = stateBox::empty;
			}
		}
		else {
			this->state = stateBox::nearBomb;
		}
	setVisual(this->state);
}

void Box::setState(stateBox state) {
	setVisual(state);
	this->state = state;
}

void Box::setPos(sf::Vector2f position) {
	visual_box.setPosition(position);
}

sf::RectangleShape Box::get_box() {
	setVisual(state);
	return visual_box;
}

stateBox Box::getState() {
	return state;
}