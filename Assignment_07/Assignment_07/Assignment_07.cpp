// Assignment_07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
//#include <boost/format.hpp>
#pragma warning(disable : 4996)


using namespace std;

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
	Rental(int memberId, int movieId, string dateOut, int daysForRent) {
		this->memeberId = memberId;
		this->movieId = movieId;
		this->dateOut = dateOut;

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
		return to_string(memeberId) + "\t" + to_string(movieId)  + "\t" + returnDate + "\t" + dateOut + " " + actualReturnDate;
	}

	int getMovieId() {
		return this->movieId;
	}

	int getMemberId() {
		return this->memeberId;
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
	Movie(int id, string title, int year, Genre genre, Type type, bool newRelease) {
		this->id = id;
		this->title = title;
		this->year = year;
		this->genre = genre;
		this->type = type;
		this->newRelease = newRelease;
		this->timesRented = 0;
		this->status = available;
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
	int getId() {
		return this->id;
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
	string getDetails() {

		string Title = title;

		if(title.length() > 14)
			Title = string(title.begin(), title.begin()+14);
		else if (title.length() < 14) {
			int diff = 14 - title.length();
			for (int i = 0; i < diff; i++)
				Title += " ";
		}

		string returnString = "|" + to_string(id) + "  |" + Title + "|" + to_string(year) + "\t   |";
		//action, drama, documentary, horror, kids, mystery, scienceFiction
		switch (genre) {
		case action:
			returnString += "action\t";
			break;
		case drama:
			returnString += "drama\t";
			break;
		case documentary:
			returnString += "documentary\t";
			break;
		case horror:
			returnString += "horror\t";
			break;
		case kids:
			returnString += "kids\t";
			break;
		case mystery:
			returnString += "mystery\t";
			break;
		case scienceFiction:
			returnString += "scienceFiction";
			break;
		}
		returnString += "\t|";
		//VHS, LaserDisc, DVD
		switch (type) {
		case VHS:
			returnString += "VHS\t";
			break;
		case LaserDisc:
			returnString += "Laser Disc";
			break;
		case DVD:
			returnString += "D.V.D\t";
			break;
		}
		returnString += "\t|";
		switch (newRelease) {
		case true:
			returnString += "New";
			break;
		case false:
			returnString += "Old";
			break;
		}

		returnString += "\t\t|";
		//available, rented, damaged
		switch (status)
		{
		case available:
			returnString += "available";
			break;
		case rented:
			returnString += "rented\t";
			break;
		case damaged:
			returnString += "damaged\t";
			break;
		default:
			break;
		}

		returnString += "\t|";
		return returnString;
	}
	Status getStatus() {
		return status;
	}
	void setStatus(Status status) {
		this->status = status;
	}
};

class Member {
private:
	int id;
	string name;
	string address;
	string phone;
	string email;
	float lateFees;
	string birthDay;
	int memberPoints;
public:
	Member(int memberId, string name, string address, string phone, string email, string birthDay) {
		this->id = memberId;
		this->name = name;
		this->address = address;
		this->phone = phone;
		this->email = email;
		this->birthDay = birthDay;
		this->lateFees = 0.0f;
		this->memberPoints = 0;
	}
	string getName() {
		return name;
	}
	string getDetails() {
		//return str(format("%2% %2% %1%\n") % "world" % "hello");
		return to_string(id) + ": " + name + "\t" + address + ", " + phone + ", " + email + "\t" + to_string(lateFees) + "\t" + birthDay + "\t" + to_string(memberPoints);
	}
	int getId() {
		return this->id;
	}
	void addLateFees(float lateFees) {
		this->lateFees += lateFees;
	}
	void payLateFess() {
		this->lateFees = 0.0f;
	}
	float getLateFees() {
		return this->lateFees;
	}
	void addMemberPoints(int points) {
		this->memberPoints += points;
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

vector<Movie> searchGenre(vector<Movie> movies, Genre genre) {
	vector<Movie> genreMovies;
	for (int i = 0; i < movies.size(); i++) {
		if (movies[i].getGenre() == genre) {
			genreMovies.push_back(movies[i]);
		}
	}
	return genreMovies;
}

void rent(int memberid, int movieid, int days, vector<Movie> &movies, vector<Member> &members, vector<Rental> &rentals) {
	Rental rent(memberid, movieid, currentDate(), days);

	int movieIndex = 0;
	int memberIndex = 0;
	bool movieExists = false;
	bool memberExists = false;

	bool isAvailable = false;
	bool hasOutstandingLateFees = false;
	bool isNewRelease = false;


	for (int i = 0; i < movies.size(); i++) {
		if (movies[i].getId() == movieid) {
			movieIndex = i;
			movieExists = true;
		}
	}

	for (int i = 0; i < members.size(); i++) {
		if (members[i].getId() == memberid) {
			memberIndex = i;
			memberExists = true;
		}
	}

	cout << memberIndex << endl;

	if (movieExists && memberExists) {
		if (movies[memberIndex].getStatus() == available) {
			isAvailable = true;
		}
		isNewRelease = movies[movieIndex].getNewRelease();

		if (members[memberIndex].getLateFees() >= 10.00f) {
			hasOutstandingLateFees = true;
		}

	}


	if (!hasOutstandingLateFees && isAvailable && movieExists && memberExists) {
		if (isNewRelease) {
			members[memberIndex].addMemberPoints(2);
		}
		else {
			members[memberIndex].addMemberPoints(1);
		}
		movies[movieIndex].setStatus(rented);
		rentals.push_back(rent);
	}
}

void returnRental(int movieid, vector<Movie> &movies, vector<Member> &members, vector<Rental> &rentals ) {
	int movieIndex = 0;
	int memberIndex = 0;
	int rentalIndex = 0;
	int memberId = 0;

	bool movieExists = false;
	bool memeberExists = false;
	bool rentalExists = false;

	for (int i = 0; i < movies.size(); i++) {
		if (movies[i].getId() == movieid) {
			movieIndex = i;
			movieExists = true;
			continue;
		}
	}

	for (int i = 0; i < rentals.size(); i++) {
		if (rentals[i].getMovieId() == movieid) {
			rentalIndex = i;
			memberId = rentals[i].getMemberId();
			rentalExists = true;
			continue;
		}
	}

	for (int i = 0; i < members.size(); i++) {
		if (members[i].getId() == memberId) {
			memberIndex = i;
			memeberExists = true;
			continue;
		}
	}
}

void printMovies(vector<Movie> &movies) {
	cout << "Movies: " << endl;
	string star(105, '-');
	cout << star << endl;
	cout << "|ID:       |Title\t  |Year\t   |Genre\t\t|Type\t\t|Release\t|Status\t\t|" << endl;

	cout << star << endl;
	for (int i = 0; i < movies.size(); i++) {

		cout << movies[i].getDetails() << endl;

		cout << star << endl;
	}
}

void printMembers(vector<Member> &members) {
	cout << endl << "Memebers: " << endl;
	cout << "ID: name\taddress, phone, email\tlate fees\tbirth day\tpoints" << endl;
	for (int i = 0; i < members.size(); i++) {

		cout << members[i].getDetails() << endl;
	}
}

void printRentals(vector<Rental> &rentals) {
	cout << endl << "Rentals: " << endl;
	cout << "Member ID:\tMovie ID:\tDate Due\tDate Out\tReturned Date" << endl;
	for (int i = 0; i < rentals.size(); i++) {

		cout << rentals[i].getDetails() << endl;
	}
}

int main()
{
	vector<Movie> movies;
	vector<Member> members;
	vector<Rental> rentals;

	members.emplace_back(Member(19840267, "John Connor", "45 maple cres", "555-5555", "john@skynet.ca", "1990-10-05"));
	members.emplace_back(Member(19569762, "Stevet Rogers", "1 capital street", "652-7649", "NA", "1979-03-26"));
	members.emplace_back(Member(19446289, "John Doe", "1234 street cres", "123-4567", "john.doe@email.net", "2000-01-01"));
	members.emplace_back(Member(19940567, "Cody Cormier", "406 gauvin rd", "229-1155", "cody.cormier@easternstudent.ca", "1992-10-10"));
	
	members[0].addLateFees(45.18f);
	members[0].addMemberPoints(7);
	members[1].addMemberPoints(127);

	movies.push_back(Movie(19991065, "The Matrix", 1999, action, DVD, false));
	movies.push_back(Movie(19970666, "Cube", 1997, scienceFiction, VHS, false));
	movies.push_back(Movie(19771234, "Star Wars", 1977, scienceFiction, LaserDisc, false));
	movies.push_back(Movie(19853658, "Brazil", 1985, scienceFiction, VHS, false));
	movies.push_back(Movie(19853658, "The Cove", 2009, documentary, DVD, false));

	movies[0].addTimesRented(56);
	movies[1].addTimesRented(37);
	movies[2].addTimesRented(287);
	movies[3].addTimesRented(24);

	rent(19840267, 19991065, 7, movies, members, rentals);
	rent(19569762, 19991065, 7, movies, members, rentals);


	cout << "Welcome to Justin's Movie Rental Program v0.0.1" << endl;
	cout << "Current Date: " << currentDate() << endl << endl;

	printMovies(movies);

	printMembers(members);

	printRentals(rentals);

	
    return 0;
}

