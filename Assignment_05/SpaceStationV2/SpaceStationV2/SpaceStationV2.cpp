// SpaceStationV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class DockingBay {
private:
	bool occupied;
	int hoursUntilVacant;
	string shipName;
	bool securityNeeded;
	bool canMove = true;
	string type;

public:

	DockingBay(string shipName, int time, bool securityNeeded) {
		this->shipName = shipName;
		this->hoursUntilVacant = time;
		this->securityNeeded = securityNeeded;
		this->occupied = true;
	}

	DockingBay() {
		this->shipName = "";
		this->hoursUntilVacant = 0;
		this->securityNeeded = false;
		this->occupied = false;
	}

	bool isAvailable() {
		return !occupied;
	}

	string getShipOccupying() {
		return this->shipName;
	}

	void setType(string type) {
		this->type = type;
	}

	string getType() {
		return this->type;
	}

	bool getCanMove() {
		return this->canMove;
	}

	void setCanMove(bool canMove) {
		this->canMove = canMove;
	}

	void setShipOccupying(string name) {
		this->shipName = name;
		this->occupied = true;
	}

	int getTimeToAvailable() {
		return hoursUntilVacant;
	}

	void setTimeToAvailable(int time) {
		this->hoursUntilVacant = time;
	}

	bool getSecurityNeeded() {
		return this->securityNeeded;
	}

	void setSecurityNeeded(bool needed) {
		this->securityNeeded = needed;
	}

	void updateTimeToAvailable(int amountOfTime) {
		this->setTimeToAvailable(this->getTimeToAvailable() - amountOfTime);
	}

	void undock() {
		this->occupied = false;
		this->shipName = "";
		this->hoursUntilVacant = 0;
		this->securityNeeded = false;
	}

};

vector<string> splitString(string line, char del) {
	vector<string> values;
	int pos = line.find(del);
	while (pos != string::npos) {
		string val = line.substr(0, pos);
		line.erase(0, pos+1);
		values.push_back(val);
		pos = line.find(del);
	}
	if (line != "") {
		values.push_back(line);
	}
	return values;
}

int getTimeFromString(string time) {
	//12:00pm
	int timeInt = 0;
	string pm = time.substr(5, 2);
	time = time.substr(0, 2) + time.substr(3, 2);

	timeInt = stoi(time);

	if (timeInt >= 100 && timeInt <= 1130 && pm.find("pm") != string::npos) {
		timeInt += 1200;
	}
	if (time.find("12")!=string::npos && pm.find("am") != string::npos) {
		timeInt -= 1200;
	}

	return timeInt;
}

string getClassFromString(string line) {
	if (line.find("Shuttle") != string::npos) {
		return "Shuttle";
	}
	else if (line.find("large") != string::npos) {
		return "large";
	}
	else {
		return "cargo";
	}
}

int getHourFromString(string hours) {
	int hour = stoi(hours);
	hour *= 100;
	return hour;
}

bool getSecurityFromString(string security) {
	bool needed;
	if (security.find("no") != string::npos) {
		needed = false;
	}
	else {
		needed = true;
	}

	return needed;
}

int main()
{
	string line = "02:00pm,Shuttle class,Moonraker,2,yes";

	vector<string> values = splitString(line, ',');

	for (int i = 0; i < values.size(); i++) {
		cout << values[i] << endl;
	}

	cout << getHourFromString(values[3]) << endl;
	cout << getSecurityFromString(values[4]) << endl;

    return 0;
}

