// SpaceStation.cpp : Defines the entry point for the console application.
// author Justin Baker
// inputs: text file containing ships docing times and stuff
// outputs: bays used and if available name of ship else print not available

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>

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


int main()
{
	float time = 12.0f; //.5 = 30min
	DockingBay bays[12];

	string line;

	ifstream file("DockingSchedule.txt");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			//cout << line << '\n';

			//get time string
			int timeEnd = line.find(',');
			string time_string = line.substr(0, timeEnd);
			line.erase(0, timeEnd + 1);

			//create temp variables for time floats
			float now = time;
			float hours = 0;
			float minutes = 0;

			//get hours from string
			hours = stof(time_string.substr(0, 2));
			// if its pm and pas 12 time aujments by 12 so 1 == 13 and if its 12am set to 0
			if (time_string.find("pm") != string::npos) {
				if (hours < 12) hours += 12;
			}
			else {
				if (hours == 12) hours -= 12;
			}
			//get minutes float
			minutes = stoi(time_string.substr(3, 2));
			//if 30 set to 0.5;
			if (minutes == 30) {
				minutes = 0.5f;
			}
			// set now to the current time float
			now = (hours + minutes);
			//calculate time passed
			float timePassed = now - time;

			//to do update all bays
			for (int i = 0; i < 12; i++) {
				//if bay is not available update time
				if (!bays[i].isAvailable()) {
					bays[i].updateTimeToAvailable(timePassed);
					if (bays[i].getTimeToAvailable() <= 0) {
						if (i <= 9) {
							//12:00pm, dock,moonraker,Bay02 
							cout << time_string << ", undock, " << bays[i].getShipOccupying() << ", Bay0" << i << endl;
						}
						else {
							cout << time_string << ", undock, " << bays[i].getShipOccupying() << ", Bay" << i << endl;
						}
						bays[i].undock();
					}
				}
			}
			// set time to now
			time = now;

			int classEnd = line.find(',');
			string classType_string = line.substr(0, classEnd);
			line.erase(0, classEnd + 1);

			int namesEnd = line.find(',');
			string name_string = line.substr(0, namesEnd);
			line.erase(0, namesEnd + 1);

			int hoursEnd = line.find(',');
			string hours_string = line.substr(0, hoursEnd);
			line.erase(0, hoursEnd + 1);
			float hoursDocked = stof(hours_string);

			int securityEnd = line.find(',');
			string security_string = line.substr(0, securityEnd);
			line.erase(0, securityEnd + 1);

			bool hasDocked = false;

//			cout << "docking " << name_string << "...\n";

			if (security_string.find("yes") != string::npos) {
				//from 1-8
				if (classType_string.find("Shuttle") != string::npos) {
					//even
					for (int i = 0; i < 12; i++) {
						if (i % 2 == 0 && i <= 8) {
							if (bays[i].isAvailable()) {
								bays[i] = DockingBay(name_string, hoursDocked, true);
								hasDocked = true;
								bays[i].setType("Shuttle");
								//12:00pm, dock,moonraker,Bay02 
								cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
								break;
							}
						}
					}
					if (!hasDocked) {
						cout << "no room for " << name_string << " moving ships...\n";
						for (int i = 0; i < 12; i++) {
							if (i % 2 == 1 && i <= 8) {
								if (!bays[i].getSecurityNeeded()) {
									DockingBay shipToMove = bays[i];
									if (i <= 9) {
										//12:00pm, dock,moonraker,Bay02 
										cout << time_string << ", undock, " << shipToMove.getShipOccupying() << ", Bay0" << i << endl;
									}
									else {
										cout << time_string << ", undock, " << shipToMove.getShipOccupying() << ", Bay" << i << endl;
									}

									if (shipToMove.getType() == "Shuttle") {
										for (int j = 0; j < 12; j++) {
											if (j % 2 == 0) {
												if (bays[j].isAvailable()) {
													bays[j] = shipToMove;
													hasDocked = true;
													//12:00pm, dock,moonraker,Bay02 
													cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
													break;
												}
											}
										}
									}
									else if (shipToMove.getType() == "Large") {
										for (int j = 0; j < 12; j++) {
											if (j % 2 == 1) {
												if (bays[j].isAvailable()) {
													bays[j] = shipToMove;
													hasDocked = true;
													//12:00pm, dock,moonraker,Bay02 
													cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
													break;
												}
											}
										}
									}
									else {
										for (int j = 0; j < 12; j++) {
											if (bays[j].isAvailable()) {
												bays[j] = shipToMove;
												hasDocked = true;
												//12:00pm, dock,moonraker,Bay02 
												cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
												break;
											}
										}
									}

									bays[i] = DockingBay(name_string, hoursDocked, true);
									hasDocked = true;
									//12:00pm, dock,moonraker,Bay02 
									cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
									break;
								}
								else {
									cout << bays[i].getSecurityNeeded() << " " << bays[i].getShipOccupying() << endl;
								}
							}
						}
					}
				}
				else if (classType_string.find("large") != string::npos) {
					//odd
					for (int i = 0; i < 12; i++) {
						if (i % 2 == 1 && i <= 8) {
							if (bays[i].isAvailable()) {
								bays[i] = DockingBay(name_string, hoursDocked, true);
								hasDocked = true;
								bays[i].setType("large");
								//12:00pm, dock,moonraker,Bay02 
								cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
								break;
							}
						}
					}
					if (!hasDocked) {
						cout << "no room for " << name_string << " moving ships...\n";
						for (int i = 0; i < 12; i++) {
							if (i % 2 == 1 && i <= 8) {
								if (!bays[i].getSecurityNeeded()) {
									DockingBay shipToMove = bays[i];
									if (i <= 9) {
										//12:00pm, dock,moonraker,Bay02 
										cout << time_string << ", undock, " << shipToMove.getShipOccupying() << ", Bay0" << i << endl;
									}
									else {
										cout << time_string << ", undock, " << shipToMove.getShipOccupying() << ", Bay" << i << endl;
									}

									if (shipToMove.getType() == "Shuttle") {
										for (int j = 0; j < 12; j++) {
											if (j % 2 == 0) {
												if (bays[j].isAvailable()) {
													bays[j] = shipToMove;
													hasDocked = true;
													//12:00pm, dock,moonraker,Bay02 
													cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
													break;
												}
											}
										}
									}
									else if (shipToMove.getType() == "Large") {
										for (int j = 0; j < 12; j++) {
											if (j % 2 == 1) {
												if (bays[j].isAvailable()) {
													bays[j] = shipToMove;
													hasDocked = true;
													//12:00pm, dock,moonraker,Bay02 
													cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
													break;
												}
											}
										}
									}
									else {
										for (int j = 0; j < 12; j++) {
											if (bays[j].isAvailable()) {
												bays[j] = shipToMove;
												hasDocked = true;
												//12:00pm, dock,moonraker,Bay02 
												cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
												break;
											}
										}
									}

									bays[i] = DockingBay(name_string, hoursDocked, true);
									hasDocked = true;
									//12:00pm, dock,moonraker,Bay02 
									cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
									break;
								}
								else {
									cout << bays[i].getSecurityNeeded() << " " << bays[i].getShipOccupying() << endl;
								}
							}
						}
					}
				}
				else {
					//any but can't move for 6 hours
					for (int i = 0; i < 12; i++) {
						if (bays[i].isAvailable() && i <= 8) {
							bays[i] = DockingBay(name_string, hoursDocked, true);
							bays[i].setCanMove(false);
							hasDocked = true;
							bays[i].setType("cargo");
							//12:00pm, dock,moonraker,Bay02 
							cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
							break;
						}
					}
					if (!hasDocked) {
						cout << "no room for " << name_string << " moving ships...\n";
						for (int i = 0; i < 12; i++) {
							if (i % 2 == 1 && i <= 8) {
								if (!bays[i].getSecurityNeeded()) {
									DockingBay shipToMove = bays[i];
									if (i <= 9) {
										//12:00pm, dock,moonraker,Bay02 
										cout << time_string << ", undock, " << shipToMove.getShipOccupying() << ", Bay0" << i << endl;
									}
									else {
										cout << time_string << ", undock, " << shipToMove.getShipOccupying() << ", Bay" << i << endl;
									}

									if (shipToMove.getType() == "Shuttle") {
										for (int j = 0; j < 12; j++) {
											if (j % 2 == 0) {
												if (bays[j].isAvailable()) {
													bays[j] = shipToMove;
													hasDocked = true;
													//12:00pm, dock,moonraker,Bay02 
													cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
													break;
												}
											}
										}
									}
									else if (shipToMove.getType() == "Large") {
										for (int j = 0; j < 12; j++) {
											if (j % 2 == 1) {
												if (bays[j].isAvailable()) {
													bays[j] = shipToMove;
													hasDocked = true;
													//12:00pm, dock,moonraker,Bay02 
													cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
													break;
												}
											}
										}
									}
									else {
										for (int j = 0; j < 12; j++) {
											if (bays[j].isAvailable()) {
												bays[j] = shipToMove;
												hasDocked = true;
												//12:00pm, dock,moonraker,Bay02 
												cout << time_string << ", dock  , " << shipToMove.getShipOccupying() << ", Bay0" << j << endl;
												break;
											}
										}
									}

									bays[i] = DockingBay(name_string, hoursDocked, true);
									hasDocked = true;
									//12:00pm, dock,moonraker,Bay02 
									cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
									break;
								}
								else {
									cout << bays[i].getSecurityNeeded() << " " << bays[i].getShipOccupying() << endl;
								}
							}
						}
					}
				}
			}
			else {
				//from any
				if (classType_string.find("Shuttle") != string::npos) {
					//even
					for (int i = 0; i < 12; i++) {
						if (i % 2 == 0) {
							if (bays[i].isAvailable()) {
								bays[i] = DockingBay(name_string, hoursDocked, false);
								hasDocked = true;
								bays[i].setType("Shuttle");
								if (i <= 9) {
									//12:00pm, dock,moonraker,Bay02 
									cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
								}
								else {
									cout << time_string << ", dock  , " << name_string << ", Bay" << i << endl;
								}
								break;
							}
						}
					}
					if (!hasDocked) {
						cout << "no room...\n";
					}
				}
				else if (classType_string.find("large") != string::npos) {
					//odd
					for (int i = 0; i < 12; i++) {
						if (i % 2 == 1) {
							if (bays[i].isAvailable()) {
								bays[i] = DockingBay(name_string, hoursDocked, false);
								hasDocked = true;
								bays[i].setType("large");
								if (i <= 9) {
									//12:00pm, dock,moonraker,Bay02 
									cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
								}
								else {
									cout << time_string << ", dock  , " << name_string << ", Bay" << i << endl;
								}
								break;
							}
						}
					}
					if (!hasDocked) {
						cout << "no room...\n";
					}
				}
				else {
					//any but can't move for 6 hours
					for (int i = 8; i < 12; i++) {
						if (bays[i].isAvailable()) {
							bays[i] = DockingBay(name_string, hoursDocked, false);
							bays[i].setCanMove(false);
							hasDocked = true;
							bays[i].setType("cargo");
							if (i <= 9) {
								//12:00pm, dock,moonraker,Bay02 
								cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
							}
							else {
								cout << time_string << ", dock  , " << name_string << ", Bay" << i << endl;
							}
							break;
						}
					}
					if (!hasDocked) {
						for (int i = 0; i < 12; i++) {
							if (bays[i].isAvailable()) {
								bays[i] = DockingBay(name_string, hoursDocked, false);
								bays[i].setCanMove(false);
								hasDocked = true;
								bays[i].setType("cargo");
								if (i <= 9) {
									//12:00pm, dock,moonraker,Bay02 
									cout << time_string << ", dock  , " << name_string << ", Bay0" << i << endl;
								}
								else {
									cout << time_string << ", dock  , " << name_string << ", Bay" << i << endl;
								}
								break;
							}
						}
						if (!hasDocked) {
							cout << "no room" << endl;
						}
					}
				}
			}
		}
		file.close();
	}

	return 0;
}

