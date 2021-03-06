// UML.cpp : Defines the entry point for the console application.
// author: justin baker
// inputs: 9 products 3books, 3pc games, 3console games (information)
// ouputs: the 9 products tostring methods

#include "stdafx.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

const unsigned int CURRENT_YEAR = 2018;

enum ageRating
{
	Everyone, Teens, Mature
};

enum Type
{
	Playstation, Xbox, Wii
};

class UserRating {
private:
	string user;
	float rating;
	string comment;
public:
	UserRating(string user, float rating, string comment) {
		if (user.length() >= 5 && user.length() <= 12) {
			if (rating >= 1.0f && rating <= 5.0) {
				this->user = user;
				this->rating = rating;
				this->comment = comment;
			}
			else {
				throw invalid_argument("rating must be between 1.0 and 5.0");
			}
		}
		else {
			throw invalid_argument("user must be between 5 and 12 characters long");
		}
	}
	string getUser() {
		return user;
	}
	float getRating() {
		return rating;
	}
	string getComment() {
		return comment;
	}
	string toString() {
		return "User: " + getUser() + "\nRating: " + to_string(getRating()) + "\nComment: " + getComment();
	}
};

class Product {
protected:
	string title;
	string barcode;
	float cost;
	float weight;
	unsigned int quantityInStock;
	vector<UserRating> ratings;
public:
	Product(string title, string barcode, float cost, float weight, unsigned int quantityInStock, vector<UserRating> ratings) {

		this->title = title;
		this->barcode = barcode;
		this->cost = cost;
		this->weight = weight;
		this->quantityInStock = quantityInStock;
		this->ratings = ratings;
	}
	string getBarcode() {
		return barcode;
	}
	float getCost() {
		return cost;
	}
	float getWeight() {
		return weight;
	}
	int getQuantity() {
		return quantityInStock;
	}
	string getRatings() {
		string user_ratings;
		for (int i = 0; i < ratings.size(); i++) {
			user_ratings += ratings[i].toString() + "\n";
		}
		return user_ratings;
	}
	float SellingPrice() {}
	float getAvgRating() {
		float avg;
		for (int i = 0; i < ratings.size(); i++) {
			avg += ratings[i].getRating();
		}
		avg /= ratings.size();
		return avg;
	};
	string toString() {
		string thisString = "Title: " + title + "\nBarcode: " + barcode + "\nCost: " + to_string(cost) + "$\nWeight: " + to_string(weight) + "g\nAmt In Stock: " + to_string(quantityInStock);
		thisString += "\n\nReviews:\n\n";
		for (int i = 0; i < ratings.size(); i++) {
			thisString += ratings[i].toString() + "\n\n";
		}
		return thisString;
	}
};

class Book : public Product{
private:
	bool Hardcover;
	string author;
	unsigned int numberPages;
	float markup;
	unsigned int year;
public:
	Book(string title, string barcode, float cost, unsigned int quantityInStock, vector<UserRating> ratings, bool Hardcover, string author, unsigned int numberPages, float markup, unsigned int year)
	: Product(title, barcode, cost, (float)numberPages, quantityInStock, ratings) {
		this->title = title;
		this->author = author;
		this->numberPages = numberPages;
		this->markup = markup;
		this->year = year;
		if (Hardcover) {
			this->weight += 200.0f;
		}
	}
	float SellingPrice() {
		return (markup * (((rand() % 45) + 30.0f )/100.0f)+1.0f) / (CURRENT_YEAR-this->year);
	}
	bool isHardCover() {
		return this->Hardcover;
	}
	string getAuthor() {
		return this->author;
	}
	int getNumPages() {
		return numberPages;
	}
	float getMarkup() {
		return this->markup;
	}
	void setYear(unsigned int year) {
		this->year = year;
	}
	string toString() {
		string thisString = "Author: " + author + ", " + to_string(year) + "\npages: " + to_string(numberPages);
		if (Hardcover) {
			thisString += "\nHardcover";
		}
		else {
			thisString += "\nSoftcover";
		}
		thisString += "\n" + Product::toString();
		return thisString;
	}
};

class VideoGame : public Product {
protected:
	string genre;
	ageRating rating;
	unsigned int year;
	float markup;
public:
	VideoGame(string title, string barcode, float cost, float weight, unsigned int quantityInStock, vector<UserRating> ratings, string genre, ageRating rating, unsigned int year, float markup) 
	: Product(title, barcode, cost, weight, quantityInStock, ratings) {
		this->genre = genre;
		this->rating = rating;
		this->year = year;
		this->markup = markup;
	}
	string getGenre() {
		return this->genre;
	}
	ageRating getAgeRating() {
		return this->rating;
	}
	unsigned int getYear() {
		return this->year;
	}
	float getMarkup() {
		this->markup;
	}

	float SellingPrice() {
		return (markup * (((rand() % 250) + 50.0f) / 100.0f) + 1.0f) / (CURRENT_YEAR - this->year);
	}

	string toString() {
		string returnString = "";
		returnString += "Genre: " + this->genre + "\n";
		returnString += "Rating: ";
		switch (rating)
		{
		case Everyone:
			returnString += "Everyone";
			break;
		case Teens:
			returnString += "Teens";
			break;
		case Mature:
			returnString += "Mature";
			break;
		default:
			break;
		}
		returnString += "\nYear: " + to_string(this->year) + "\n";
		returnString += "markup: " + to_string(this->markup) + "\n";
		returnString += Product::toString();
		return returnString;
	}
};

class PC : public VideoGame {
public:
	string systemRequirements;
	bool isPhysicalMedia;
	PC(string title, string barcode, float cost, unsigned int quantityInStock, vector<UserRating> ratings, string genre, ageRating rating, unsigned int year, float markup, bool isPhysicalMedia, string systemRequirements)
	: VideoGame(title, barcode, cost, isPhysicalMedia ? 200.0f : 0.01f, quantityInStock, ratings, genre, rating, year, markup) {
		this->systemRequirements = systemRequirements;
		this->isPhysicalMedia = isPhysicalMedia;
	}

	string toString() {
		string returnString = "";
		returnString += "\nIs Physical Copy: ";
		returnString += isPhysicalMedia ? "True\n" : "False\n";
		returnString += "Requirements:\n" + systemRequirements + "\n\n";
		returnString += VideoGame::toString();
		return returnString;
	}
};

class Console : public VideoGame {
	public:
	Type type;
	Console(string title, string barcode, float cost, unsigned int quantityInStock, vector<UserRating> ratings, string genre, ageRating rating, unsigned int year, float markup, Type type)
	: VideoGame(title, barcode, cost, 200.0f, quantityInStock, ratings, genre, rating, year, markup) {
		this->type = type;
	}

	string toString() {
		string returnString = "";
		returnString += "Console: ";
		switch (type)
		{
		case Playstation:
			returnString += "Playstation";
			break;
		case Xbox:
			returnString += "Xbox";
			break;
		case Wii:
			returnString += "Wii";
			break;
		default:
			break;
		}
		returnString += "\n" + VideoGame::toString();
		return returnString;
	}
};

bool isAlpha(string string) {
	bool valid = true;
	for (int i = 0; i < string.length(); i++) {
		if (!isalpha(string[i])) {
			valid = false;
		}
	}
	return valid;
}

bool isValidBarcode(string barcode) {
	if (isAlpha(barcode)) {
		return false;
	} else if (barcode.length() != 8) {
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	srand(time(NULL));
	vector<Book> books;
	vector<PC> pcs;
	vector<Console> consoles;


	int year;
	float cost;
	string title;
	float markup;
	string genre;
	string author;
	string answer;
	string barcode;
	bool hardcover;
	Type consoleType;
	int numberOfPages;
	int quantityInStock;
	bool isPhysicalMedia;
	ageRating age_rating;
	string systemRequirements;
	vector<UserRating> ratings;


	//Books
	for (int i = 0; i < 3; i++) {

		cout << "\nBOOK " << i+1 << ":" << endl << endl;

		cout << "What is the title of the book?" << endl;
		getline(cin, title, '\n');

		cout << "Who is the author?" << endl;
		getline(cin, author, '\n');

		cout << "in what year was the book published?" << endl;
		cin >> year;
		while (year < 0) {
			cout << "the year must be greater then 0, please enter a valid year..." << endl;
			cin >> year;
		}
		cin.ignore();

		cout << "is the book hardcover?" << endl;
		cin >> answer;
		while (answer.find("yes") == string::npos && answer.find("no") == string::npos) {
			cout << "you must answer yes or no, please answer yes or no..." << endl;
			cin >> answer;
		}
		if (answer.find("yes") != string::npos) {
			hardcover = true;
		}
		else {
			hardcover = false;
		}
		cin.ignore();

		cout << "How many pages are in the book?" << endl;
		cin >> numberOfPages;
		while (numberOfPages < 0) {
			cout << "nuber of pages must be greater then 0, please enter a valid number of pages..." << endl;
			cin >> numberOfPages;
		}
		cin.ignore();

		cout << "What is the books barcode?" << endl;
		getline(cin, barcode, '\n');
		while (!isValidBarcode(barcode)) {
			cout << "Barcode must be 8 digits, please enter a valid barcode..." << endl;
			getline(cin, barcode, '\n');
		}

		cout << "How much does the book cost?" << endl;
		cin >> cost;
		while (cost < 0.0f) {
			cout << "cost must be greater then 0, please enter a valid cost..." << endl;
			cin >> cost;
		}
		cin.ignore();

		cout << "what is the books markup?" << endl;
		cin >> markup;
		cin.ignore();

		cout << "How many do you have in stock?" << endl;
		cin >> quantityInStock;
		while (quantityInStock < 0) {
			cout << "cost must be greater then 0, please enter a valid cost..." << endl;
			cin >> quantityInStock;
		}
		cin.ignore();

		answer = "";
		cout << "Enter 2 or more user reviews: \n" << endl;
		while (ratings.size() < 2 || answer.find("yes") != string::npos) {
			string user;
			float rating;
			string comment;

			cout << "Who is the reviewer?" << endl;
			getline(cin, user, '\n');

			cout << "what did they rate it?(1.0-5.0)" << endl;
			cin >> rating;
			while (rating < 1.0f || rating > 5.0f) {
				cout << "rating must be between 1.0 and 5.0, please enter a valid rating..." << endl;
				cin >> rating;
			}
			cin.ignore();

			cout << "what was their comment?" << endl;
			getline(cin, comment, '\n');

			UserRating userRating(user, rating, comment);
			ratings.push_back(userRating);
			if (ratings.size() >= 2) {
				cout << "add another user review?" << endl;
				cin >> answer;
				cin.ignore();
			}
		}

		//Book book(title, barcode, 19.75f, 7, ratings, true, author, 308, 13.00f, 2008);
		Book book(title, barcode, cost, quantityInStock, ratings, hardcover, author, numberOfPages, markup, year);
		books.push_back(book);
	}

	//PC games
	for (int i = 0; i < 3; i++) {
		cout << "\nPC GAME " << i + 1 << ":" << endl << endl;

		cout << "What is the title of the game?" << endl;
		getline(cin, title, '\n');

		cout << "What is the genre of the game?" << endl;
		getline(cin, genre, '\n');

		cout << "in what year was the game published?" << endl;
		cin >> year;
		while (year < 0) {
			cout << "the year must be greater then 0, please enter a valid year..." << endl;
			cin >> year;
		}
		cin.ignore();

		cout << "is the game a physical copy?" << endl;
		cin >> answer;
		while (answer.find("yes") == string::npos && answer.find("no") == string::npos) {
			cout << "you must answer yes or no, please answer yes or no..." << endl;
			cin >> answer;
		}
		if (answer.find("yes") != string::npos) {
			isPhysicalMedia = true;
		}
		else {
			isPhysicalMedia = false;
		}
		cin.ignore();

		cout << "what is the games age rating?(Everyone, Teens or Mature)" << endl;
		cin >> answer;
		while (answer.find("Everyone") == string::npos && answer.find("Teens") == string::npos && answer.find("Mature") == string::npos) {
			cout << "you must answer Everyone, Teens or Mature, please answer Everyone, Teens or Mature..." << endl;
			cin >> answer;
		}
		if (answer.find("Everyone") != string::npos) {
			age_rating = Everyone;
		}
		else if(answer.find("Teens") != string::npos){
			age_rating = Teens;
		}
		else {
			age_rating = Mature;
		}
		cin.ignore();

		cout << "what is the games system requirements?" << endl;
		getline(cin, systemRequirements, '\n');

		cout << "What is the games barcode?" << endl;
		getline(cin, barcode, '\n');
		while (!isValidBarcode(barcode)) {
			cout << "Barcode must be 8 digits, please enter a valid barcode..." << endl;
			getline(cin, barcode, '\n');
		}

		cout << "How much does the game cost?" << endl;
		cin >> cost;
		while (cost < 0.0f) {
			cout << "cost must be greater then 0, please enter a valid cost..." << endl;
			cin >> cost;
		}
		cin.ignore();

		cout << "what is the games markup?" << endl;
		cin >> markup;
		cin.ignore();

		cout << "How many do you have in stock?" << endl;
		cin >> quantityInStock;
		while (quantityInStock < 0) {
			cout << "cost must be greater then 0, please enter a valid cost..." << endl;
			cin >> quantityInStock;
		}
		cin.ignore();

		answer = "";
		cout << "Enter 2 or more user reviews: \n" << endl;
		while (ratings.size() < 2 || answer.find("yes") != string::npos) {
			string user;
			float rating;
			string comment;

			cout << "Who is the reviewer?" << endl;
			getline(cin, user, '\n');

			cout << "what did they rate it?(1.0-5.0)" << endl;
			cin >> rating;
			while (rating < 1.0f || rating > 5.0f) {
				cout << "rating must be between 1.0 and 5.0, please enter a valid rating..." << endl;
				cin >> rating;
			}
			cin.ignore();

			cout << "what was their comment?" << endl;
			getline(cin, comment, '\n');

			UserRating userRating(user, rating, comment);
			ratings.push_back(userRating);
			if (ratings.size() >= 2) {
				cout << "add another user review?" << endl;
				cin >> answer;
				cin.ignore();
			}
		}

		PC pc(title, barcode, cost, quantityInStock, ratings, genre, age_rating, year, markup, isPhysicalMedia, systemRequirements);
		pcs.push_back(pc);
	}

	//Console games
	for (int i = 0; i < 3; i++) {
		cout << "\nCONSOLE GAME " << i + 1 << ":" << endl << endl;

		cout << "What is the title of the game?" << endl;
		getline(cin, title, '\n');

		cout << "What is the genre of the game?" << endl;
		getline(cin, genre, '\n');

		cout << "in what year was the game published?" << endl;
		cin >> year;
		while (year < 0) {
			cout << "the year must be greater then 0, please enter a valid year..." << endl;
			cin >> year;
		}
		cin.ignore();

		cout << "what is the games age rating?(Everyone, Teens or Mature)" << endl;
		cin >> answer;
		while (answer.find("Everyone") == string::npos && answer.find("Teens") == string::npos && answer.find("Mature") == string::npos) {
			cout << "you must answer Everyone, Teens or Mature, please answer Everyone, Teens or Mature..." << endl;
			cin >> answer;
		}
		if (answer.find("Everyone") != string::npos) {
			age_rating = Everyone;
		}
		else if (answer.find("Teens") != string::npos) {
			age_rating = Teens;
		}
		else {
			age_rating = Mature;
		}
		cin.ignore();

		cout << "on which console was the game released?(Playstation, Xbox, Wii)" << endl;
		cin >> answer;
		while (answer.find("Playstation") == string::npos && answer.find("Xbox") == string::npos && answer.find("Wii") == string::npos) {
			cout << "you must answer Playstation, Xbox, Wii, please answer Playstation, Xbox, Wii..." << endl;
			cin >> answer;
		}
		if (answer.find("Playstation") != string::npos) {
			consoleType = Playstation;
		}
		else if (answer.find("Xbox") != string::npos) {
			consoleType = Xbox;
		}
		else {
			consoleType = Wii;
		}
		cin.ignore();

		cout << "What is the games barcode?" << endl;
		getline(cin, barcode, '\n');
		while (!isValidBarcode(barcode)) {
			cout << "Barcode must be 8 digits, please enter a valid barcode..." << endl;
			getline(cin, barcode, '\n');
		}

		cout << "How much does the game cost?" << endl;
		cin >> cost;
		while (cost < 0.0f) {
			cout << "cost must be greater then 0, please enter a valid cost..." << endl;
			cin >> cost;
		}
		cin.ignore();

		cout << "what is the games markup?" << endl;
		cin >> markup;
		cin.ignore();

		cout << "How many do you have in stock?" << endl;
		cin >> quantityInStock;
		while (quantityInStock < 0) {
			cout << "cost must be greater then 0, please enter a valid cost..." << endl;
			cin >> quantityInStock;
		}
		cin.ignore();

		answer = "";
		cout << "Enter 2 or more user reviews: \n" << endl;
		while (ratings.size() < 2 || answer.find("yes") != string::npos) {
			string user;
			float rating;
			string comment;

			cout << "Who is the reviewer?" << endl;
			getline(cin, user, '\n');

			cout << "what did they rate it?(1.0-5.0)" << endl;
			cin >> rating;
			while (rating < 1.0f || rating > 5.0f) {
				cout << "rating must be between 1.0 and 5.0, please enter a valid rating..." << endl;
				cin >> rating;
			}
			cin.ignore();

			cout << "what was their comment?" << endl;
			getline(cin, comment, '\n');

			UserRating userRating(user, rating, comment);
			ratings.push_back(userRating);
			if (ratings.size() >= 2) {
				cout << "add another user review?" << endl;
				cin >> answer;
				cin.ignore();
			}
		}
		//Console(title, barcode, cost, quantityInStock, ratings, genre, age_rating, year, markup, Type consoleType)
	
		Console console(title, barcode, cost, quantityInStock, ratings, genre, age_rating, year, markup, consoleType);
		consoles.push_back(console);
	}

	for (int i = 0; i < books.size(); i++) {
		cout << books[i].toString();
	}
	for (int i = 0; i < pcs.size(); i++) {
		cout << pcs[i].toString();
	}

	for (int i = 0; i < consoles.size(); i++) {
		cout << consoles[i].toString();
	}

    return 0;
}

