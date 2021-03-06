//	Assignment_01.cpp : Defines the entry point for the console application.
//	By: Justin Baker
//	Date: 2018-02-15
//	change method in main method

#include "stdafx.h"

using namespace std;

//inputs temperature in celcius (with decimal values)
//outputs temperature in Fahrenheit (with decimal values)
void fahrenheitConversion() {
	double temperatureFahrenheit;
	cout << "Enter the temperature in Fahrenheit" << endl;
	cin >> temperatureFahrenheit;
	double celcius = (temperatureFahrenheit - 32.0) * (5.0 / 9.0);
	cout << "the temperature in Celcius is: ";
	cout << celcius << endl;
}

//inputs name, email, address, coffee amout, donut amaount, sandwich amount
//output receipt
/*

Receipt for Marty McFly   (MMcFly@hillvalley.com)
3x Donuts @ 0.97  ---------- 2.91
6x Coffees @ 1.37 -----------8.22
1x sandwiches @ 2.88-------2.88
-----------------------------------------------
Subtotal           14.01
Tax           2.10
----------------------------------------------
Total           16.11


*/

float donutPrice = 0.97f;
float coffeePrice = 1.37f;
float sandwichPrice = 2.88;

void coffeeShop() {
	string name, email, address;
	int donutAnmount, coffeeAmount, sandwichAmount;
	float donutCost = 0.97f;
	float coffeeCost = 1.37f;
	float sandwichCost = 2.88f;

	cout << "What is your Name?" << endl;
	getline(cin, name);

	cout << "What is your Email?" << endl;
	getline(cin, email);

	cout << "What is your Address?" << endl;
	getline(cin, address);

	cout << "How many donuts do you want?" << endl;
	cin >> donutAnmount;

	cout << "How many cups of coffee do you want?" << endl;
	cin >> coffeeAmount;

	cout << "How many sandwiches do you want?" << endl;
	cin >> sandwichAmount;

	cout << "\nReceipt for " << name << " (" << email << ")" << endl;

	float totalCostBT = (donutAnmount * donutCost) + (coffeeAmount * coffeeCost) + (sandwichAmount * sandwichCost);
	float taxes = totalCostBT * 0.15f;
	cout << fixed << setprecision(2);
	cout << "\n" << donutAnmount << "x Donuts     @ " << donutCost <<    " ---------- " << donutAnmount * donutCost << endl;
	cout << "" << coffeeAmount <<   "x Coffees    @ " << coffeeCost <<   " ---------- " << coffeeAmount * coffeeCost << endl;
	cout << "" << sandwichAmount << "x Sandwiches @ " << sandwichCost << " ---------- " << sandwichAmount * sandwichCost << endl;
	cout << "--------------------------------------" << endl;
	cout << "         Subtotal      " << totalCostBT << endl;
	cout << "              Tax      " << taxes << endl;
	cout << "--------------------------------------" << endl;
	cout << "            Total      " << (totalCostBT + taxes) << endl;

}

void downloadEstimation() {
	int fileSize;
	float downloadSpeed;

	cout << "How big is the file in MB?" << endl;
	cin >> fileSize;

	cout << "How fast is your download Speed in MB/S?" << endl;
	cin >> downloadSpeed;

	int timeInHours = (fileSize / downloadSpeed) / 3600;
	int timeInMinutes = ((fileSize / downloadSpeed)/60) - (timeInHours * 60);
	int timeInSeconds = (fileSize / downloadSpeed) - (timeInMinutes*60) - (timeInHours*3600);

	cout << timeInHours << " hours, " << timeInMinutes << " minutes, " << timeInSeconds << " seconds to download" << endl;
}

int main() {
	coffeeShop();
    return 0;
}

