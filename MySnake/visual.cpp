#include "visual.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <chrono>
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

void visual::changecolor()
{
	
}

void visual::printgameOver(int x, int y, char dir)
{
	std::string s;

	switch (dir)
	{
	case '^':
		s= "\x1b[31;1m^\x1b[0m\n";
		break;
	case 'v':
		s = "\x1b[31;1mv\x1b[0m\n";
		break;
	case '>':		
		s = "\x1b[31;1m>\x1b[0m\n";		
		break;
	case '<':	
		s = "\x1b[31;1m<\x1b[0m\n";	
		break;
	}
	for (int i = 0; i < 10; i++) {
		setCursor(10 + x, 10 + y);
		std::cout << s;
		Sleep(500);
		setCursor(10 + x, 10 + y);
		std::cout << " ";
		Sleep(500);
	}
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
	/*SetConsoleTextAttribute(handle,
		BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);*/
}

void visual::printapple(int x, int y)
{
	setCursor(10 + x, 10 + y);
	std::cout << "\x1b[32;1m@\x1b[0m\n";
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
