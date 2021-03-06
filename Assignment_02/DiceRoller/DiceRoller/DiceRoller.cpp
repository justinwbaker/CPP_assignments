// DiceRoller.cpp : Defines the entry point for the console application.
// Authror:		Justin Baker
//  inputs:		number of sides
// outputs:		5x die rolls

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	unsigned int total = 0;
	unsigned int number = 0;
	unsigned int average = 0;
	unsigned int diceSides = 1;

	cout << "How many sides does you dice have?" << endl;
	cin >> diceSides;

	for (int i = 0; i < 5; i++) {
		number = rand() % diceSides + 1;
		cout << "Roll" << i << ": \t " << number << endl;
		total += number;
	}

	cout << "Average: " << total / 5 << endl;

    return 0;
}

