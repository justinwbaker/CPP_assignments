// main.cpp : Defines the entry point for the console application.
// author: Justin Baker
// inputs: if the user has seen the movie
// outputs: oldest and newest film, (to a file) a list of how many films in each decade, % they have seen + wich decade seen most of, list in alphbetical order

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// class for every Movie
class Movie {
private:
	int year;
	string title;
public:
	Movie(int year, string title) {
		this->year = year;
		this->title = title;
	}

	int getYear() {
		return year;
	}

	string getTitle() {
		return title;
	}
};

//map for storing the decades and the vector of movies in that decade
map<int, vector<Movie>> decades;

//returns the year of the movie from the string
int getYear(string movie) {
	return stoi(movie.substr(movie.find("(") + 1, 4));
}

//converts a year to its decade
int getDecade(int year) {
	return year - (year % 10);
}

//sorts the specified decade by acending year
void sortDecade(int decade) {
	for (int i = 0; i < decades.at(decade).size(); i++) {
		for (int j = i; j < decades.at(decade).size(); j++) {
			if (decades.at(decade)[i].getYear() > decades.at(decade)[j].getYear()) {
				Movie temp = decades.at(decade)[i];
				decades.at(decade)[i] = decades.at(decade)[j];
				decades.at(decade)[j] = temp;
			}
		}
	}
}

//print the movies in the specified decade with no repeating years
void printDecadeNoRepeat(int decade) {
	int year = 0;
	for (int i = 0; i < decades.at(decade).size(); i++) {
		int this_year = decades.at(decade)[i].getYear();
		if (year != this_year) {
			cout << this_year << "\t" << decades.at(decade)[i].getTitle() << endl;
			year = this_year;
		}
	}
}

//prints the movies in the specified decade
void printDecade(int decade) {
	for (int i = 0; i < decades.at(decade).size(); i++) {
		int this_year = decades.at(decade)[i].getYear();
		cout << this_year << "\t" << decades.at(decade)[i].getTitle() << endl;
	}
}

void oldestToNewest(vector<Movie> movies) {

	//temporary storing of the movies in each decade
	vector<Movie> y1920;
	vector<Movie> y1930;
	vector<Movie> y1940;
	vector<Movie> y1950;
	vector<Movie> y1960;
	vector<Movie> y1970;
	vector<Movie> y1980;
	vector<Movie> y1990;
	vector<Movie> y2000;
	vector<Movie> y2010;

	//loop through movies vector
	for (size_t i = 0; i < movies.size(); i++) {
		int decade = getDecade(movies[i].getYear());
		//check which decade it is in and add to appropriate vector
		if (decade == 1920) {
			y1920.push_back(movies[i]);
		}
		else if (decade == 1930) {
			y1930.push_back(movies[i]);
		}
		else if (decade == 1940) {
			y1940.push_back(movies[i]);
		}
		else if (decade == 1950) {
			y1950.push_back(movies[i]);
		}
		else if (decade == 1960) {
			y1960.push_back(movies[i]);
		}
		else if (decade == 1970) {
			y1970.push_back(movies[i]);
		}
		else if (decade == 1980) {
			y1980.push_back(movies[i]);
		}
		else if (decade == 1990) {
			y1990.push_back(movies[i]);
		}
		else if (decade == 2000) {
			y2000.push_back(movies[i]);
		}
		else if (decade == 2010) {
			y2010.push_back(movies[i]);
		}
	}

	
	//create lists and associate with year in the decades map
	decades.insert(pair<int, vector<Movie>>(1920, y1920));
	decades.insert(pair<int, vector<Movie>>(1930, y1930));
	decades.insert(pair<int, vector<Movie>>(1940, y1940));
	decades.insert(pair<int, vector<Movie>>(1950, y1950));
	decades.insert(pair<int, vector<Movie>>(1960, y1960));
	decades.insert(pair<int, vector<Movie>>(1970, y1970));
	decades.insert(pair<int, vector<Movie>>(1980, y1980));
	decades.insert(pair<int, vector<Movie>>(1990, y1990));
	decades.insert(pair<int, vector<Movie>>(2000, y2000));
	decades.insert(pair<int, vector<Movie>>(2010, y2010));

	//sort the decates from the 1920's to the 2010's
	for (int i = 1920; i < 2020; i += 10) {
		sortDecade(i);
	}
	
	cout << "Oldest: " << decades.at(1920)[0].getTitle() << endl;
	cout << "Newest: " << decades.at(2010)[decades.at(2010).size()-1].getTitle() << endl;
	
}

//write the amount of movies in each decates to the example file
void writeAmountInDecades() {
	for (int i = 1920; i < 2020; i+=10) {
		cout << i << "'s: " << decades.at(i).size() << " films" << endl;
	}
}

void randomFilms(vector<Movie> movies) {
	int seen = 0;
	int decade = 1900;

	int years[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	string answer = "";
	for (int i = 0; i < 20; i++) {
		int movieIndex = rand() % movies.size();
		cout << "have you seen " << movies[movieIndex].getTitle() << "?" << endl;
		getline(cin, answer);
		while (!(answer.compare("yes") == 0 || answer.compare("no") == 0)) {
			cout << answer << "enter yes or no..." << endl;
			cin >> answer;
		}

		if (answer.compare("yes") == 0) {
			seen++;
			switch (getDecade(movies[movieIndex].getYear())) {
			case 1920:
				years[0]++;
				break;
			case 1930:
				years[1]++;
				break;
			case 1940:
				years[2]++;
				break;
			case 1950:
				years[3]++;
				break;
			case 1960:
				years[4]++;
				break;
			case 1970:
				years[5]++;
				break;
			case 1980:
				years[6]++;
				break;
			case 1990:
				years[7]++;
				break;
			case 2000:
				years[8]++;
				break;
			case 2010:
				years[9]++;
				break;
			}
		}
	}
	cout << "you have seen " << (seen / 20.0f) * 100 << "% of the 20 movies" << endl;
	int largest = 0;
	for (int i = 0; i < 10; i++) {
		if (years[i] > largest) {
			largest = years[i];
			switch (i) {
			case 0:
				decade = 1920;
				break;
			case 1:
				decade = 1930;
				break;
			case 2:
				decade = 1940;
				break;
			case 3:
				decade = 1950;
				break;
			case 4:
				decade = 1960;
				break;
			case 5:
				decade = 1970;
				break;
			case 6:
				decade = 1980;
				break;
			case 7:
				decade = 1990;
				break;
			case 8:
				decade = 2000;
				break;
			case 9:
				decade = 2010;
				break;
			}
		}
	}
	cout << "most of them are from the " << decade << "'s" << endl;
}

void printName(const string& item) {
	cout << item << endl;
}

void printInAlphabeticalOrder(vector<Movie> movies) {
	set<string> names;

	for (int i = 0; i < movies.size(); i++) {
		names.insert(movies[i].getTitle());
	}

	for_each(names.begin(), names.end(), &printName);
}

int main()
{
	srand(time(NULL));
	ifstream file_in;
	string line;
	vector<Movie> movies;
	int decade;


	file_in.open("top_100_Sci-Fi_Films.txt");

	while (getline(file_in, line)) {
		int year = getYear(line);
		Movie movie(year, line.substr(0, line.find("(")-1));
		movies.push_back(movie);
	}

	oldestToNewest(movies);

	writeAmountInDecades();

	cout << "\nwhich decade would you like to display?" << endl;
	cin >> decade;

	printDecade(decade);

	cout << endl;

	randomFilms(movies);

	cout << endl;

	printInAlphabeticalOrder(movies);

    return 0;
}

