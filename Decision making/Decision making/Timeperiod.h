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

class Timeperiod {
private:
	string parofday;
	string activity;
public:
	Timeperiod() {}
	Timeperiod(string p, string a) {
		parofday = p;
		activity = a;
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string p, a;
		setColor(10);
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		setColor(14);
		cout << "*     Time Period Activity    *" << endl;
		setColor(10);
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		setColor(12);
		cout << "*        Enter part of day: " << "        " << endl;
		getline(cin, p);
		cout << "*        Enter activity: " << "        " << endl;
		getline(cin, a);
		setColor(11);
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		parofday = p;
		activity = a;
	}
	void display() {
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		cout << "*     Time Period Activity   *" << endl;
		cout << parofday << " : " << activity << "       *" << endl;
		cout << "*                             *" << endl;
		cout << "******************************" << endl;
	}
};
