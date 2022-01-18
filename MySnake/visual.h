#pragma once


class visual
{
	
public:
	enum class color  { Black = 0, Red, Yellow, White};
	enum class Background { Black = 0, Green };
	visual();
	void choosecolor(color clr, Background back);
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

