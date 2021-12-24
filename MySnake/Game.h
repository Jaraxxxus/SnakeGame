#pragma once
#include "visual.h"
#include <stdlib.h>
#include "SBody.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
class Game
{
public: 
	static const int width = 40;
	static const int height = 20;
	static const int field_size = 900;
	void prepare();
	void play();
	Game();
private:
	visual myscreen;
	int badgen;
	int appleX, appleY;
	int speed, score;
	bool gameOver;
	SBody body;
	enum class edirect { stop = 0, left, right, up, down };
	edirect dir, olddir;
	void check_colisions();

	bool check_apple();
	bool check_wall();
	bool check_tail();
	void input();

	
	//������
	void generate_apple();
	
	//������
    void move();	

};

