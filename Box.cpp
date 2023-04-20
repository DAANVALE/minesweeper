#include "Box.h"

using namespace std;

Box::Box(){
	visual_box.setSize(sf::Vector2f(39,39));
	state = stateBox::cover;
}

void Box::bombRandom() {
	int random = rand() % 20;
	if (random == 12) {
		bomb = true;
		nearbombs = 0;
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