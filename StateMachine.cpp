#pragma once
#ifndef STATE_MACHINE
#define STATE_MACHINE

enum class stateBox {
	cover,
	flag,
	bomb,
	nearBomb,
	empty
};

enum class stateGame {
	start,
	playing,
	lose,
	win
};

#endif // STATE_MACHINE