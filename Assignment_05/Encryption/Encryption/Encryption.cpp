// Encryption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";


bool isValidAlpha(string value) {
	bool valid = true;
	if (value == "" || value == "\n") {
		return false;
	}
	for (int i = 0; i < value.length(); i++) {
		if (!isalpha(value[i])) {
			valid = false;
		}
	}
	if(!valid)
		cout << "value must only contain letters" << endl;
	return valid;
}

string removeDuplicates(string content) {
	for (string::size_type i = 0; i < content.size(); i++)
	{
		string::size_type j = i + 1;
		while (j < content.size())
		{
			if (content[i] == content[j])
			{
				content.erase(j, 1);
			}
			else
			{
				++j;
			}
		}
	}

	return content;
}

string getEncryptionAlhabet(string key) {
	key += alphabet;
	return removeDuplicates(key);
}

string toLower(string value) {
	for (int i = 0; i < value.length(); i++) {
		value[i] = tolower(value[i]);
	}

	return value;
}

string encryption(string encryptedAlphabet, string password) {
	string encryption = "";
	for (int i = 0; i < password.length(); i++) {
		int index = alphabet.find(password[i]);
		encryption += encryptedAlphabet[index];
	}
	return encryption;
}

int main()
{
	string shouldContinue = "y";
	string key, password, encryptedAlphabet;

	cout << "Enter your key" << endl;
	cin >> key;
	key = toLower(key);

	while (!isValidAlpha(key)) {
		cout << "Enter your key: " << endl;
		cin >> key;
		key = toLower(key);
	}

	encryptedAlphabet = getEncryptionAlhabet(removeDuplicates(key));

	while (shouldContinue.find('y') != string::npos) {

		cout << "\nEnter the password you would like to be encrypted:" << endl;

		cin >> password;
		password = toLower(password);

		while (!isValidAlpha(password) || password == key) {
			if (password == key) {
				cout << "password cannot be the key..." << endl;
			}
			cout << "\nEnter your password:" << endl;
			cin >> password;
			password = toLower(password);
		}

		cout << "Encrypted Password: " << encryption(encryptedAlphabet, password) << endl;
		//do encryption
		shouldContinue = "";
		password = "";

		cout << "\nContinue(y/n)?" << endl;
		cin >> shouldContinue;
	}
    return 0;
}

