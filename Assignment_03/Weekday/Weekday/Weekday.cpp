// Weekday.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };


int main()
{
	week today;
	today = Wednesday;

	cout << "Day " << today ;
    return 0;
}

