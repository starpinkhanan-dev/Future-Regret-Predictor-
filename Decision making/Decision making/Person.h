#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <windows.h>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

class Person {
protected:
	string name;
	int id;
public:
	Person() {}
	Person(string n, int userid) {
		for (char c : n) {
			if (!isalpha(c) && c != ' ') {
				throw invalid_argument("Name must contain only letters and spaces.");
			}
		}
		name = n;
		if (userid <= 0 || userid > 9999) {
			throw invalid_argument("ID must be between 1 and 9999.");
		}
		id = userid;
	}
	void setName(string n) {
		for (char c : n) {
			if (!isalpha(c) && c != ' ') {
				throw invalid_argument("Name must contain only letters and spaces.");
			}
		}
		if (n.empty()) {
			throw invalid_argument("Name cannot be empty.");
		}
		name = n;
	}
	void setId(int userid) {
		if (userid <= 0 || userid > 9999) {
			throw invalid_argument("ID must be between 1 and 9999.");
		}
		id = userid;
	}
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}

	void updateInfo(string n, int userid) {
		setName(n);
		setId(userid);
	}
	void setInfo(string n, int userid) {
		updateInfo(n, userid);
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string n;
		int userid;

		setColor(10);
		cout << "************************" << endl;
		cout << "*                      *" << endl;
		setColor(14);
		cout << "*      PERSON INFO       *" << endl;
		setColor(10);
		cout << "*                      *" << endl;
		cout << "************************" << endl;
		setColor(15);
		cout << "*       Enter your name:" << endl;
		getline(cin, n);
		cout << "*       Enter your Id: " << endl;
		cin >> userid;
		cin.ignore();
		setColor(10);
		cout << "*                       *" << endl;
		cout << "************************" << endl;
		setName(n);
		setId(userid);
	}
	virtual void display() {
		cout << "******************************" << endl;
		cout << "*        PERSON INFO         *" << endl;
		cout << "******************************" << endl;
		cout << "* Name: " << name << endl;
		cout << "* ID  : " << id << endl;
		cout << "******************************" << endl;
	}
};


