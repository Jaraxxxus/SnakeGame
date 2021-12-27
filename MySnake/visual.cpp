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



void visual::printgameOver(int x, int y, char dir)
{
	std::string s;

	switch (dir)
	{
	case '^':
		s= "^";
		break;
	case 'v':
		s = "v";
		break;
	case '>':		
		s = ">";		
		break;
	case '<':	
		s = "<";	
		break;
	}
	for (int i = 0; i < 6; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY| 12);
		setCursor(10 + x, 10 + y);
		std::cout << s;
		Sleep(500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY| 12);
		setCursor(10 + x, 10 + y);
		std::cout << " ";
		Sleep(500);
		
	}
	Endgame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f  );
}

void visual::printfield(int width, int height) {
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	for (int j = 0; j < width; j++) {

		for (int i = 0; i < height; i++) {
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
				setCursor(10 + i, 10 + j);
				std::cout << "#";

			}
			else {
				
				std::cout << " ";
			
			}

		}

	}
	SetConsoleTextAttribute(handle, 0x0f);

}

void visual::printhead(int x, int y, char dir)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	setCursor(10 + x, 10 + y);
	std::cout << dir;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY| 12);
	setCursor(10 + x, 10 + y);
	std::cout << "@";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
}

void visual::erese(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	setCursor(10 + x, 10 + y);
	std::cout << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
}

void visual::printmove(int oldx, int oldy, char dir)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY| 14);
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);

}

void visual::showscore(int score)
{
	setCursor(25, 8);
	std::cout << "score: "<<score;
}

void visual::Endgame()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	for (int j = 0; j < 20; j++) {

		for (int i = 0; i < 40; i++) {

			setCursor(10 + i, 10 + j);
			std::cout << " ";



		}
	}
	setCursor(25 , 20);
	std::cout << "Game Over";
	Sleep(10000);
}