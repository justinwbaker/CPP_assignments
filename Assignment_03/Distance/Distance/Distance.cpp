// Distance.cpp : Defines the entry point for the console application.
//Author: Justin Baker
//input : two points
//output: distance

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

float distance(float x1, float y1, float x2, float y2) {

	float xPow = pow((x2 - x1), 2);
	float yPow = pow((y2 - y1), 2);
	float distance = pow((xPow + yPow), 0.5);

	return distance;
}

int main()
{
	float x1, x2, y1, y2;

	cout << "Enter the coorinates 'x1 y1 x2 y2'" << endl;

	cin >> x1 >> y1 >> x2 >> y2;

	cout << "The distance is: " << distance(x1, y1, x2, y2) << endl;

    return 0;
}

