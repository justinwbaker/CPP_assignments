// Vowels.cpp : Defines the entry point for the console application.
//Author: Justin Baker
//Input : text
//output: num of each vowel and other letters

#include "stdafx.h"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

void vowels(string text) {
	int as = 0, es = 0, is = 0, os = 0, us = 0, others = 0;
	int stringSize = text.length();
	for (int i = 0; i < stringSize; i++) {
		switch (text[i]) {
		case 'a':
			as++;
			break;
		case 'e':
			es++;
			break;
		case 'i':
			is++;
			break;
		case 'o':
			os++;
			break;
		case 'u':
			us++;
			break;
		default:
			others++;
		}
	}
	cout << "a:" << as << endl;
	cout << "e:" << es << endl;
	cout << "i:" << is << endl;
	cout << "o:" << os << endl;
	cout << "u:" << us << endl;
	cout << "others:" << others << endl;
}

int main()
{
	string input;
	cout << "Enter text:" << endl;
	getline(cin, input);
	vowels(input);
	return 0;
}

