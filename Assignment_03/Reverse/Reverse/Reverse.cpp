// Reverse.cpp : Defines the entry point for the console application.
// Author: Justin Baker
// input : string
// output: revesed string

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

string reverse(string inputString) {
	int stringLength = inputString.length();
	string temp = inputString;

	for (int i = stringLength; i > 0; i--) {
		temp[stringLength - i] = inputString[i-1];
	}

	return temp;

}

int main()
{
	string input;
	cin >> input;
	cout << reverse(input) << endl;
    return 0;
}

