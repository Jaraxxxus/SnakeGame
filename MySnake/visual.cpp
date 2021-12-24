#include "visual.h"
#include <iostream>
#include <Windows.h>

void visual::setCursor(int x, int y)
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
	

}


visual::visual()
{

}

void visual::printfield(int width, int height) {

	//int x = body.getx();
	//int y = body.gety();

	for (int j = 0; j < width; j++) {

		for (int i = 0; i < height; i++) {
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
				setCursor(10 + i, 10 + j);
				std::cout << "#";

			}

		}

	}


}

void visual::printhead(int x, int y, char dir)
{
	setCursor(10 + x, 10 + y);
	std::cout << dir;
}

void visual::printtail(int x, int y)
{
	setCursor(10 + x, 10 + y);
	std::cout <<"●" ;
}

void visual::hidecursor()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

void visual::printapple(int x, int y)
{
	setCursor(10 + x, 10 + y);
	std::cout << "@";
}

void visual::erese(int x, int y)
{
	setCursor(10 + x, 10 + y);
	std::cout << " ";
}

void visual::printmove(int oldx, int oldy, char dir)
{
	switch (dir)
	{
	case '^':
		setCursor(10 + oldx, 10 + oldy);
		std::cout << 'o';
		setCursor(10+ oldx, 9 + oldy);
		std::cout << dir;
		break;
	case 'v':
		setCursor(10 + oldx, 10 + oldy);
		std::cout << 'o';
		setCursor(10 + oldx, 11 + oldy);
		std::cout << dir;
		break;
	case '>':
		setCursor(10 + oldx, 10 + oldy);
		std::cout << 'o';
		setCursor(11 + oldx, 10 + oldy);
		std::cout << dir;
		break;
	case '<':
		setCursor(10 + oldx, 10 + oldy);
		std::cout << 'o';
		setCursor(9 + oldx, 10 + oldy);
		std::cout << dir;
		break;
	}
}

void visual::showscore(int score)
{
	setCursor(25, 8);
	std::cout << "score: "<<score;
}
