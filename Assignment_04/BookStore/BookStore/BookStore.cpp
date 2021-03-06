// BookStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Client {
private:
	string name;
	int discount;
	float purchaseAmount;
public:
	Client(string name) {
		this->name = name;
		this->discount = 0;
		this->purchaseAmount = 0.0f;
	}

	string getName() {
		return name;
	}

	void addPurchase(float amount) {
		this->purchaseAmount += amount;
	}

	float getPurchase() {
		return this->purchaseAmount;
	}

	void setDiscount(int discount) {
		this->discount = discount;
	}

	int getDiscount() {
		return this->discount;
	}

	void resetClient() {
		this->discount = 0;
		this->purchaseAmount = 0.0f;
	}
protected:
	//not used
};


int main() {

	string name;
	int discount;
	float purchaseTotal;

	cout << fixed << setprecision(2);

	cout << "What is the name of the client?" << endl;
	getline(cin, name);

	Client TestClient(name);

	cout << "what is the clients discount percentage?(0-100)" << endl;
	cin >> discount;
	TestClient.setDiscount(discount);

	cout << "How much is the clients total current purchase before their discount?" << endl;
	cin >> purchaseTotal;
	purchaseTotal *= (TestClient.getDiscount() / 100.0f) + 1.0f;

	cout << "total amount to be paid: " << purchaseTotal << endl;

	TestClient.addPurchase(purchaseTotal);

	cout << "what is the clients new discount percentage?(0-100)" << endl;
	cin >> discount;
	TestClient.setDiscount(discount);

	cout << "How much is the clients total current purchase before their discount?" << endl;
	cin >> purchaseTotal;
	purchaseTotal *= (TestClient.getDiscount() / 100.0f) + 1.0f;

	cout << "total amount to be paid: " << purchaseTotal << endl;

	TestClient.addPurchase(purchaseTotal);

	cout << "name: " << TestClient.getName() << "\nDiscount: " << TestClient.getDiscount() << "\nCumulative purchase: " << TestClient.getPurchase() << endl;

	TestClient.resetClient();

	cout << "name: " << TestClient.getName() << "\nDiscount: " << TestClient.getDiscount() << "\nCumulative purchase: " << TestClient.getPurchase() << endl;

	cout << "enter a number to exit" << endl;
	cin >> purchaseTotal;

	return 0;
}
