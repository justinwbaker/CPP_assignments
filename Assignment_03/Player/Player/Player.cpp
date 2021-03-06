// Player.cpp : Defines the entry point for the console application.
//Author: justin baker
//input : player name
//output: n/a

#include "stdafx.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

class Player {
	string _name;
	int _x = 0;
	int _y = 0;

public:
	Player(string name) {
		_name = name;
		_x = 0;
		_y = 0;
	}

	void setX(int x) {
		_x = x;
	}

	void setY(int y) {
		_y = y;
	}

	void move() {
		int xRand = rand() % 6 - 3;
		int yRand = rand() % 6 - 3;

		_x += xRand;
		_y += yRand;
	}

	string printLocation() {
		return ( _name + " x: " + to_string(_x) + " y: " + to_string(_y));
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	string name = "";

	cout << "what is the players name?" << endl;
	cin >> name;

	Player player(name);
	player.move();

	cout << player.printLocation() << endl;

    return 0;
}

