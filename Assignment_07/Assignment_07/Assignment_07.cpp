// Assignment_07.cpp : Defines the entry point for the console application.
// Authoor: justin baker
// inputs: varius commands
// outputs: movie list or other information

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
	VHS, LaserDisc, DVD, InvalidType
};

enum Status {
	available, rented, damaged
};

enum Genre {
	action, drama, documentary, horror, kids, mystery, scienceFiction, InvalidGenre
};

string commands[] = { "showRentals", "showMovies", "showMembers", "rentMovie", "returnMovie", "searchGenre", "addMember", "addMovie"};

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

string getTime(string date, string date2) {
	int birth_year = stoi(date.substr(0, 4));
	int birth_month = stoi(date.substr(5, 2));
	int birth_day = stoi(date.substr(8, 2));

	string current = date2;
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

int getAmountOfDays(string time) {
	int years = stoi(time.substr(0, 4));
	int months = stoi(time.substr(5, 2));
	int days = stoi(time.substr(8, 2));

	return (years * 365) + (months * 31) + days;
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
		return to_string(memeberId) + "\t" + to_string(movieId)  + "\t" + returnDate + "\t" + dateOut + "\t" + actualReturnDate;
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

	float getLateFees() {
		float fees = 0.0f;
		if (isLate()) {
			fees = getAmountOfDays(getTime(returnDate, actualReturnDate))*2.0f;
		}
		return fees;
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
		string NAME = name;
		string EMAIL = email;
		string ADDRESS = address;

		if (name.length() > 13)
			NAME = string(name.begin(), name.begin() + 13);
		else if (name.length() < 13) {
			int diff = 13 - name.length();
			for (int i = 0; i < diff; i++)
				NAME += " ";
		}

		if (address.length() > 13)
			ADDRESS = string(address.begin(), address.begin() + 13);
		else if (address.length() < 13) {
			int diff = 13 - address.length();
			for (int i = 0; i < diff; i++)
				ADDRESS += " ";
		}

		if (email.length() > 13)
			EMAIL = string(email.begin(), email.begin() + 13);
		else if (email.length() < 13) {
			int diff = 13 - email.length();
			for (int i = 0; i < diff; i++)
				EMAIL += " ";
		}

		if (address.length() <= 13) address += "\t";
		if (address.length() > 14) address = string(address.begin(), address.begin() + 14);
		return "|" + to_string(id) + " |" + NAME + "|" + ADDRESS + "\t|" + phone + " |" + EMAIL + " |" + to_string(lateFees) + "\t|" + birthDay + "\t|" + to_string(memberPoints) + "\t|";
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

bool rent(int memberid, int movieid, int days, vector<Movie> &movies, vector<Member> &members, vector<Rental> &rentals) {
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

	if (movieExists && memberExists) {
		if (movies[memberIndex].getStatus() == available) {
			isAvailable = true;
		}
		isNewRelease = movies[movieIndex].getNewRelease();

		if (members[memberIndex].getLateFees() >= 10.00f) {
			hasOutstandingLateFees = true;
			cout << "Has outstanding Late Fees... :(" << endl;
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
		return true;
	}
	else {
		return false;
	}
}

bool returnRental(int movieid, vector<Movie> &movies, vector<Member> &members, vector<Rental> &rentals ) {
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

	if (movieExists && memeberExists && rentalExists) {
		movies[movieIndex].setStatus(available);
		rentals[rentalIndex].returnMovie();
		members[memberIndex].addLateFees(rentals[rentalIndex].getLateFees());
		return true;
	}
	else {
		return false;
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
	string star(105, '-');
	cout << star << endl;
	cout << "|ID:      |name\t\t|address\t|phone    |email\t |late fees\t|birth day\t|points |" << endl;
	cout << star << endl;
	for (int i = 0; i < members.size(); i++) {

		cout << members[i].getDetails() << endl;

		cout << star << endl;
	}
}

void printRentals(vector<Rental> &rentals) {
	cout << endl << "Rentals: " << endl;
	cout << "Member ID:\tMovie ID:\tDate Due\tDate Out\tReturned Date" << endl;
	for (int i = 0; i < rentals.size(); i++) {

		cout << rentals[i].getDetails() << endl;
	}
}

bool isNumber(const std::string &str) {
	return !str.empty() && str.find_first_not_of("0123456789") == string::npos;
}

bool isValidDate(string date) {

	if (!isNumber(date.substr(0, 4))) {
		return false;
	}else if (!isNumber(date.substr(5, 2))) {
		return false;
	}else if (!isNumber(date.substr(8, 2))) {
		return false;
	}
	else {
		return true;
	}
}

Type getTypeFromString(string genreString) {
	//VHS, LaserDisc, DVD, InvalidType
	if (genreString.find("DVD") != string::npos) {
		return DVD;
	}
	else if (genreString.find("LaserDisc") != string::npos) {
		return LaserDisc;
	}
	else if (genreString.find("VHS") != string::npos) {
		return VHS;
	}
	else {
		return InvalidType;
	}
}

Genre getGenreFromString(string genreString) {
	//action, drama, documentary, horror, kids, mystery, scienceFiction
	if (genreString.find("action") != string::npos) {
		return action;
	}
	else if (genreString.find("drama") != string::npos) {
		return drama;
	}
	else if (genreString.find("documentary") != string::npos) {
		return documentary;
	}
	else if (genreString.find("horror") != string::npos) {
		return horror;
	}
	else if (genreString.find("kids") != string::npos) {
		return kids;
	}
	else if (genreString.find("mystery") != string::npos) {
		return mystery;
	}
	else if (genreString.find("scienceFiction") != string::npos) {
		return scienceFiction;
	}
	else {
		return InvalidGenre;
	}
}

int main()
{
	bool running = true;
	string command = "";
	int comandsLen = 8;

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

	//returnRental(19991065, movies, members, rentals);

	while (running) {
		system("cls");
		cout << "Welcome to Justin's Movie Rental Program v0.0.1" << endl;
		cout << "Current Date: " << currentDate() << endl << endl;

		cout << "Commands:" << endl << endl;
		for (int i = 0; i < comandsLen; i++) {
			if (i == 6 || i == 3 || i == 5) cout << endl;
			cout << "- " << commands[i] << endl;
		}

		cout << endl << "Enter a Command:" << endl;
		getline(cin, command, '\n');
		bool isValid = false;
		for (int i = 0; i < comandsLen; i++) {
			if (command.find(commands[i]) != string::npos) {
				command = commands[i];
				isValid = true;
			}
		}
		while (!isValid) {
			cout << "Invalid command please try again..." << endl;
			getline(cin, command, '\n');
			for (int i = 0; i < comandsLen; i++) {
				if (command.find(commands[i]) != string::npos) {
					command = commands[i];
					isValid = true;
				}
			}
		}

		//add member
		if (command == "addMember") {
			int memberId;
			string name;
			string address;
			string phone;
			string email;
			string birthDay;

			cout << "Please enter the members id" << endl;
			cin >> memberId;

			while (memberId <= 0) {
				cout << "Please enter a valid id" << endl;
				cin >> memberId;
			}
			cin.ignore();

			cout << "Please enter the members name" << endl;
			getline(cin, name);

			cout << "Please enter the address of the member" << endl;
			getline(cin, address);

			cout << "Please enter the members phone number" << endl;
			getline(cin, phone);

			cout << "Please enter the members email address" << endl;
			getline(cin, email);

			cout << "Please enter the members birtday(yyyy-mm-dd)" << endl;
			getline(cin, birthDay);

			while (!isValidDate(birthDay)) {
				cout << "Please enter a valid birtday(yyyy-mm-dd)" << endl;
				getline(cin, birthDay);
			}
			//Member(int memberId, string name, string address, string phone, string email, string birthDay)
			members.push_back(Member(memberId, name, address, phone, email, birthDay));

			printMembers(members);

			cout << "Member added" << endl;
		}

		//add movie
		if (command == "addMovie") {
			int id = 0;
			string title = "";
			int year;
			string genreString;
			string typeString;
			string isNewReleaseString;
			Genre genre;
			Type type;
			bool isNewRelease;

			cout << "what is the movie's title?" << endl;
			getline(cin, title);
			while (title == "") {
				cout << "Please enter a valid title" << endl;
				getline(cin, title);
			}

			cout << "Please enter the movies information (id year genre type newRelease)" << endl;
			cin >> id >> year >> genreString >> typeString >> isNewReleaseString;

			while (id <= 0) {
				cout << "Please enter a valid id" << endl;
				cin >> id;
			}

			while (year <= 0) {
				cout << "Please enter a valid year" << endl;
				cin >> year;
			}

			//genre

			while (getGenreFromString(genreString) == InvalidGenre) {
				cout << "Please Enter a valid genre" << endl;
				cin >> genreString;
			}
			genre = getGenreFromString(genreString);

			//type
			while (getTypeFromString(typeString) == InvalidType) {
				cout << "Please Enter a valid type" << endl;
				cin >> typeString;
			}

			type = getTypeFromString(typeString);

			//boolean
			while (isNewReleaseString.find("yes") == string::npos && isNewReleaseString.find("no") == string::npos) {
				cout << "Please Enter yes or no for the new release" << endl;
				cin >> isNewReleaseString;
			}

			isNewRelease = (isNewReleaseString.find("yes") != string::npos) ? true : false;

			//Movie(int id, string title, int year, Genre genre, Type type, bool newRelease)
			movies.emplace_back(Movie(id, title, year, genre, type, isNewRelease));
			cout << "Movie added" << endl;
			cin.ignore();
		}

		if (command == "showRentals") {
			printRentals(rentals);
		}

		if (command == "showMovies") {
			printMovies(movies);
		}

		if (command == "showMembers") {
			printMembers(members);
		}

		if (command == "rentMovie") {
			int movieId = 0;
			int memberId = 0;
			int days = 0;

			cout << "Available Movies:" << endl;
			for (int i = 0; i < movies.size(); i++) {
				if (movies[i].getStatus() == available) {
					cout << movies[i].getId() << " : " << movies[i].getTitle() << endl;
				}
			}

			cout << endl << "current member with 10$ or less in late fees" << endl;
			for (int i = 0; i < members.size(); i++) {
				if (members[i].getLateFees() <= 10.0f) {
					cout << members[i].getId() << " : " << members[i].getName() << endl;
				}
			}

			cout << "Please enter the movie id to rent..." << endl;
			cin >> movieId;
			bool isValidMovieId = false;
			for (int i = 0; i < movies.size(); i++) {
				if (movies[i].getId() == movieId && movies[i].getStatus() == available) {
					isValidMovieId = true;
				}
			}

			while (!isValidMovieId) {
				cout << "Please enter a valid id from the list above..." << endl;
				cin >> movieId;
				isValidMovieId = false;
				for (int i = 0; i < movies.size(); i++) {
					if (movies[i].getId() == movieId) {
						isValidMovieId = true;
					}
				}
			}

			cout << "Please enter the member id to rent..." << endl;
			cin >> memberId;
			bool isValidMemberId = false;
			for (int i = 0; i < members.size(); i++) {
				if (members[i].getId() == memberId) {
					isValidMemberId = true;
				}
			}

			while (!isValidMemberId) {
				cout << "Please enter a valid id..." << endl;
				cin >> memberId;
				isValidMemberId = false;
				for (int i = 0; i < members.size(); i++) {
					if (members[i].getId() == memberId) {
						isValidMemberId = true;
					}
				}
			}

			cout << "How many days will it be rented before it become late?" << endl;
			cin >> days;
			while (days <= 0) {
				cout << "not a vaild amount of days" << endl;
				cin >> days;
			}

			if (rent(memberId, movieId, days, movies, members, rentals)){
				printRentals(rentals);
			}
			else {
				cout << "can't rent movie" << endl;
			}

			cin.ignore();
		}

		if (command == "returnMovie") {
			int movieId = 0;
			for (int i = 0; i < movies.size(); i++) {
				if (movies[i].getStatus() == rented) {
					cout << movies[i].getId() << " : " << movies[i].getTitle() << endl;
				}
			}
			cout << "Please enter the movie id to return..." << endl;
			cin >> movieId;
			bool isValidId = false;
			for (int i = 0; i < movies.size(); i++) {
				if (movies[i].getId() == movieId) {
					isValidId = true;
				}
			}

			while (!isValidId) {
				cout << "Please enter a valid id from the list above..." << endl;
				cin >> movieId;
				isValidId = false;
				for (int i = 0; i < movies.size(); i++) {
					if (movies[i].getId() == movieId) {
						isValidId = true;
					}
				}
			}

			cout << endl << "Old";
			printRentals(rentals);
			if (returnRental(movieId, movies, members, rentals)) {
				cout << endl << "New ";
				printRentals(rentals);
			}
			else {
				cout << "Something went wrong..." << endl;
			}
			cin.ignore();
		}

		if (command == "searchGenre") {
			vector<Movie> moviesInGenre;

			cout << "which Genre of movie are you looking for?" << endl;
			getline(cin, command);

			while (getGenreFromString(command) == InvalidGenre) {
				cout << "not a valid genre please enter valid genre" << endl;
				getline(cin, command);
			}

			moviesInGenre = searchGenre(movies, getGenreFromString(command));
			if (moviesInGenre.size() == 0) {
				cout << "No Movies In that Genre..." << endl;
			}
			else {
				printMovies(moviesInGenre);
			}
		}

		cout << "Press enter to continue" << endl;
		getline(cin, command);
	}
	
    return 0;
}

