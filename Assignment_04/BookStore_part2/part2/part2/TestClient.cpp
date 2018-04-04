#include "stdafx.h"
#include "TestClient.h"
#include <string>

Client::Client(string name) {
	Client::name = name;
	Client::discount = 0;
	Client::purchaseAmount = 0.0f;
}

string Client::getName() {
	return name;
}

void Client::addPurchase(float amount) {
	this->purchaseAmount += amount;
}

float Client::getPurchase() {
	return this->purchaseAmount;
}

void Client::setDiscount(int discount) {
	this->discount = discount;
}

int Client::getDiscount() {
	return this->discount;
}

void Client::resetClient() {
	this->discount = 0;
	this->purchaseAmount = 0.0f;
}
