// IteratorTimesTwo.cpp : Defines the entry point for the console application.
// Author: Justin Baker
// inputs: n/a
//outputs: count down by 2

#include "stdafx.h"
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	for (int i = 100; i > 0; i -= 2) {
		cout << i << endl;
	}
    return 0;
}

