// Output.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int value = 20;
	int num = 1;
	int timesRan = 1;
	for (int i = num; i < value; i*=2) {
		cout << timesRan++ << endl;
	}
    return 0;
}

