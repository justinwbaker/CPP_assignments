#include "stdafx.h"
#include <string>

using namespace std;

class Client {
private:
	string name;
	int discount;
	float purchaseAmount;
public:
	Client(string name);
	string getName();
	void addPurchase(float amount);
	float getPurchase();
	void setDiscount(int discount);
	int getDiscount();
	void resetClient();
};