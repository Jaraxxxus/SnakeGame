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

void visual::choosecolor(color clr, Background back)
{
	if (clr == visual::color::Red && back == visual::Background::Green) 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY | 12);
	else if (clr == visual::color::White && back == visual::Background::Black)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	else if (clr == visual::color::Black && back == visual::Background::Green)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	else if (clr == visual::color::Yellow && back == visual::Background::Green)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY | 14);
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
		choosecolor(visual::color::Red, visual::Background::Green);
		setCursor(10 + x, 10 + y);
		std::cout << s;
		Sleep(500);
		
		setCursor(10 + x, 10 + y);
		std::cout << " ";
		Sleep(500);
		
	}
	Endgame();
	choosecolor(visual::color::White, visual::Background::Black);
}

void visual::printfield(int width, int height) {
	HANDLE handle;
	setCursor(15,2);
	std::cout << "Please use only ENG keyboard layout";
	setCursor(25, 3);
	std::cout<<"control"<<std::endl;
	setCursor(20, 4);
	std::cout << "UP   = W  DOWN  = S" << std::endl;
	setCursor(20, 5);
	std::cout << "LEFT = A  RIGHT = D" << std::endl;
	
	choosecolor(visual::color::Black, visual::Background::Green);
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
	choosecolor(visual::color::White, visual::Background::Black);
}

void visual::printhead(int x, int y, char dir)
{
	choosecolor(visual::color::Black, visual::Background::Green);
	setCursor(10 + x, 10 + y);
	std::cout << dir;
	choosecolor(visual::color::White, visual::Background::Black);
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
	choosecolor(visual::color::Red, visual::Background::Green);
	setCursor(10 + x, 10 + y);
	std::cout << "@";
	choosecolor(visual::color::White, visual::Background::Black);
}

void visual::erese(int x, int y)
{
	choosecolor(visual::color::Black, visual::Background::Green);
	setCursor(10 + x, 10 + y);
	std::cout << " ";
	choosecolor(visual::color::White, visual::Background::Black);
}

void visual::printmove(int oldx, int oldy, char dir)
{
	choosecolor(visual::color::Yellow, visual::Background::Green);
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
	choosecolor(visual::color::White, visual::Background::Black);

}

void visual::showscore(int score)
{
	setCursor(25, 8);
	std::cout << "score: "<<score;
}

void visual::Endgame()
{
	choosecolor(visual::color::White, visual::Background::Black);
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