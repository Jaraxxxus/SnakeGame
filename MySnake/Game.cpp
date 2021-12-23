#include "Game.h"
class Game
{
public:
	void prepare();
	void play();
	Game() {
		speed = 50;
		gameOver = 0;
	}


private:
	int curx, cury;
	static const int width = 40;
	static const int height = 40;
	static const int field_size = 1600;
	int speed ;
	bool gameOver;
};