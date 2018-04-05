// Assignment_07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#pragma warning(disable : 4996)


using namespace std;
const int daysForRent = 7;

enum Type {
	VHS, LaserDisc, DVD
};

enum Status {
	available, rented, damaged
};

enum Genre {
	action, drama, documentary, horror, kids, mystery, scienceFiction
};

const string currentDate() {
	time_t rawtime;
	tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%Y-%m-%d", timeinfo);

	return string(buffer);
}

string getAge(string date) {
	int birth_year = stoi(date.substr(0, 4));
	int birth_month = stoi(date.substr(5, 2));
	int birth_day = stoi(date.substr(8, 2));

	string current = currentDate();
	int curr_year = stoi(current.substr(0, 4));
	int curr_month = stoi(current.substr(5, 2));
	int curr_day = stoi(current.substr(8, 2));

	curr_year -= birth_year;
	curr_month -= birth_month;
	if (curr_month <= 0) {
		curr_year--;
		curr_month = 12 - curr_month;
	}
	curr_day -= birth_day;

	int daysInMonth = 30;
	if (birth_month == 1 || birth_month == 3 || birth_month == 5 || birth_month == 7 || birth_month == 8 || birth_month == 10 || birth_month == 12) {
		//31
		daysInMonth = 31;

	}
	else if (birth_month == 2) {
		daysInMonth = 28;
	}

	if (curr_day <= 0) {
		curr_month -= 1;
		curr_day = daysInMonth - birth_day;
	}

	string month = to_string(curr_month);
	string day = to_string(curr_day);

	if (curr_month <= 9) {
		month = "0" + month;
	}

	if (curr_day <= 9) {
		day = "0" + day;
	}

	return to_string(curr_year) + "-" + month + "-" + day;
}

class Rental {
private:
	// yyyy-mm-dd
	string dateOut;
	int memeberId;
	int movieId;
	string returnDate;
	string actualReturnDate;
public:
	Rental(int memberId, int movieId, string dateOut) {
		this->memeberId = memberId;
		this->movieId = movieId;

		int return_year = stoi(dateOut.substr(0, 4));
		int return_month = stoi(dateOut.substr(5, 2));
		int return_day = stoi(dateOut.substr(8, 2));

		return_day += daysForRent;

		int daysInMonth = 30;
		if (return_month == 1 || return_month == 3 || return_month == 5 || return_month == 7 || return_month == 8 || return_month == 10 || return_month == 12) {
			//31
			daysInMonth = 31;
			
		}
		else if (return_month == 2) {
			daysInMonth = 28;
		}

		if (return_day > daysInMonth) {
			return_month += 1;
			return_day = 1;
			if (return_month > 12) {
				return_year += 1;
				return_month = 1;
			}
		}

		string month = to_string(return_month);
		string day = to_string(return_day);

		if (return_month <= 9) {
			month = "0" + month;
		}

		if (return_day <= 9) {
			day = "0" + day;
		}

		this->returnDate = to_string(return_year) + "-" + month + "-" + day;
	}

	string getDetails() {
		return to_string(memeberId) + "\t" + to_string(movieId) + "\t" + actualReturnDate + "\t" + returnDate + "\t" + dateOut;
	}

	void returnMovie() {
		this->actualReturnDate = currentDate();
	}

	bool isLate() {
		int return_year = stoi(returnDate.substr(0, 4));
		int return_month = stoi(returnDate.substr(5,2));
		int return_day = stoi(returnDate.substr(8,2));

		int actual_return_year = stoi(actualReturnDate.substr(0, 4));
		int actual_return_month = stoi(actualReturnDate.substr(5, 2));
		int actual_return_day = stoi(actualReturnDate.substr(8, 2));

		if (return_year < actual_return_year) {
			return true;
		}
		else {
			if (return_month < actual_return_month && return_year == actual_return_year) {
				return true;
			}
			else {
				if (return_day < actual_return_day && return_month == actual_return_month && return_year == actual_return_year) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
};

class Movie {
private:
	int id;
	string title;
	int year;
	Genre genre;
	Type type;
	bool newRelease;
	int timesRented;
	Status status;
public:
	Movie() {
		//TODO make constructor
	}
	string getTitle() {
		return title;
	}
	int getYear() {
		return year;
	}
	Type getType(){
		return type;
	}
	Genre getGenre() {
		return genre;
	}
	bool getNewRelease() {
		return newRelease;
	}
	void setIsNewRelease(bool newRelease) {
		this->newRelease = newRelease;
	}
	void addTimesRented(int timesRented) {
		this->timesRented += timesRented;
	}
	Status getStatus() {
		return status;
	}
	Status setStatus(Status status) {
		this->status = status;
	}
};

class Member {
private:
	int memberId;
	string name;
	string address;
	string phone;
	string email;
	float lateFees;
	string birthDay;
	int memberPoints;
public:
	string getName() {
		return name;
	}
	string getDetails() {
		return to_string(memberId) + "\t" + name + "\t" + address + "\t" + phone + "\t" + email + "\t" + to_string(lateFees) + "\t" + to_string(getIsOver18()) + "\t" + to_string(memberPoints);
	}
	float getLateFees() {
		return lateFees;
	}
	bool getIsOver18() {
		string age = getAge(birthDay);

		int birth_age = stoi(age.substr(0, 4));
		if (birth_age >= 18) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	cout << "Welcome to Justin's Movie Rental Program v0.0.1" << endl;
	cout << "Current Date: " << currentDate() << endl;

	cout << getAge("2000-01-25") << endl;

	Rental rental(123, 456, currentDate());
	rental.returnMovie();
    return 0;
}

