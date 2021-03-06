// BookStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "TestClient.h"

class Book {
private:
	string title;
	float price;
	int discount;
public:

	Book(string title, float price) {
		this->title = title;
		this->price = price;
		this->discount = 0;
	}

	Book(string title, float price, int discount) {
		this->title = title;
		this->price = price;
		this->discount = discount;
	}

	string getTitle() {
		return this->title;
	}

	float getPrice() {
		return this->price;
	}

	void setPrice(float price) {
		this->price = price;
	}

	int getDiscount() {
		return this->discount;
	}
};




int main() {

	string name = "";
	float price = 0.0f;
	int discount = 0;

	cout << fixed << setprecision(2);

	cout << "what is the name of the first book?" << endl;
	getline(cin, name);
	cout << "how much does the book cost?" << endl;
	cin >> price;
	cout << "what is the books discount precentage(0-100)?" << endl;
	cin >> discount;

	Book book1(name, price, discount);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "what is the name of the second book?" << endl;
	getline(cin, name);
	cout << "how much does the book cost?" << endl;
	cin >> price;

	Book book2(name, price);

	book1.setPrice(30.0f);

	Client AndreaSmith("Andrea Smith");
	AndreaSmith.setDiscount(15);

	float book1Cost = (book1.getPrice() * (1.0-(book1.getDiscount() / 100.0f)));
	float book2Cost = (book2.getPrice() * (1.0-(book2.getDiscount() / 100.0f)));

	AndreaSmith.addPurchase(book1Cost);
	AndreaSmith.addPurchase(book2Cost);

	cout << AndreaSmith.getName() << endl;
	cout << "$ " << book1Cost << " " << book1.getTitle() << endl;
	cout << "$ " << book2Cost << " " << book2.getTitle() << endl;
	cout << "------------------------" << endl;
	cout << "$ " << AndreaSmith.getPurchase() << " " << " subtotal" << endl;
	cout << "$ " << AndreaSmith.getPurchase() * ((AndreaSmith.getDiscount()/100.0f)) << " " << " Client's Discount" << endl;
	cout << "------------------------" << endl;
	cout << "$ " << AndreaSmith.getPurchase() * (1.0-(AndreaSmith.getDiscount() / 100.0f)) << " " << "Total" << endl;
	cout << endl;

	cout << "name: " << AndreaSmith.getName() << endl;
	cout << "discount: " << AndreaSmith.getDiscount() << endl;
	cout << "cumulative purchase: " << AndreaSmith.getPurchase() << endl;


	cout << endl << "enter a number to continue" << endl;
	cin >> price;

	return 0;
}
