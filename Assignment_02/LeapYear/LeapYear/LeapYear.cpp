// LeapYear.cpp : Defines the entry point for the console application.
//  Author:	Justin Baker
//  inputs:	Year to check
// outputs: Is leap year or not

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int year;

	cout << "What year do you want to check?" << endl;
	cin >> year;

	if ((year % 400 == 0) || ((year % 4 == 0) && ((year % 100 > 0) || (year % 100 < 0)))) {
		cout << year << " is a leap year!" << endl;
	}
	else {
		cout << year << " is not a leap year!" << endl;
	}
    return 0;
}

