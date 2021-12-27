#pragma once


class visual
{
	
public:
	visual();
	
	void printgameOver(int x, int y, char dir);
	void printfield(int height, int width);
	void printhead(int x, int y, char dir);
	void hidecursor();
	void printapple(int x, int y);
	void erese(int x, int y);
	void printmove(int oldx, int oldy, char dir);
	void showscore(int score);
	void Endgame();

private:

	void setCursor(int x, int y);
};

