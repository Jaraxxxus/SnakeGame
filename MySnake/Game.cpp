
#include "Game.h"
#include <stdlib.h>
#include "SBody.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "visual.h"

	void Game::prepare() {
	//������ ����

		myscreen.showscore(score);
		myscreen.hidecursor();
		myscreen.printfield(height, width);
		myscreen.printhead(body.getx(),body.gety(),'<');
		generate_apple();
		
	
	}
	void Game::play(){
		while (!gameOver) {
			input();
			move();
			check_colisions();
		}
		
		
	};

	Game::Game() {
		score = 0;
		badgen = 0;
		speed = 50;
		gameOver = 0;
		dir = Game::edirect::stop;
		olddir = Game::edirect::stop;
		visual myscreen;
	}



	void Game::check_colisions() {
		if (check_wall()|| check_tail())
		{
			gameOver++;
			gameoverprint();
		}
		if (check_apple()) {
			score += 5;
			myscreen.showscore(score);
			generate_apple();
		}
		
		else {
			myscreen.erese(body.getTx(), body.getTy());
			body.DeleteTail();
		}
		
	}

	bool Game::check_apple(){
		if (appleX == body.getx() && appleY == body.gety()) return true;
		return false;
	}
	bool Game::check_wall() {
		if (body.getx() == 0 || body.gety()==0 || body.gety() == height - 1 || body.getx() == width - 1) return true;
		else return false;

	}
	bool Game::check_tail() {
		return (body.checkTail(body.getx(), body.gety()));
	
	}
	void Game::input()
	{

		switch (_getch())
		{
		case 'a':
			if (dir != Game::edirect::right) {
				dir = Game::edirect::left;
			}
			
			break;
		case 'd':
			if (dir != Game::edirect::left) {
				dir = Game::edirect::right;
			}
			break;
		case 'w':
			if (dir != Game::edirect::down) {
				dir = Game::edirect::up;
			}
			break;
		case 's':
			if (dir != Game::edirect::up) {
				dir = Game::edirect::down;
			}
			break;

		case 'q':
			gameOver = true;
			break;
		}

	}
	//������
	void Game::generate_apple(){
		appleX = rand() % 38 + 1;
		appleY = rand() % 18 + 1;
	
		if (body.checkTail(appleX, appleY, 1)){

			badgen++;
			void generate_apple();
		}else  myscreen.printapple(appleX, appleY);
			
	}
	//������
	void Game::move() { 
		switch (dir)
		{
		case Game::edirect::left:
			myscreen.printmove(body.getx(), body.gety(), '<');
			body.move('x', -1);
			break;
		case Game::edirect::right:
			myscreen.printmove(body.getx(), body.gety(), '>');
			body.move('x', 1);
			break;
		case Game::edirect::up:
			myscreen.printmove(body.getx(), body.gety(), '^');
			body.move('y', -1);
			break;
		case Game::edirect::down:
			myscreen.printmove(body.getx(), body.gety(), 'v');
			body.move('y', 1);
			break;
		}
	}

	void Game::gameoverprint() {

		myscreen.printgameOver(body.getx(), body.gety(), getdir());

	}

	char Game::getdir()
	{
		switch (dir)
		{
		case Game::edirect::up:
			return '^';
			break;
		case Game::edirect::down:
			return 'v';
			break;
		case Game::edirect::right:
			return '>';
			break;
		case Game::edirect::left:
			return '<';
			break;
		
	
		}
	}


	
