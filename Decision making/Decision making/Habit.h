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

class Habit {
private:
	string name;
	int streak;
	bool  completedToday;
public:
	Habit() {}
	Habit(string n, int s, bool c) {
		if (n.empty()) {
			throw invalid_argument("Name can not be empty");
		}
		if (s < 0) {
			throw invalid_argument("Streak must be greter than 0");
		}
		name = n;
		streak = s;
		completedToday = c;
	}
	void setName(string n) {
		if (n.empty()) {
			throw invalid_argument("Name can not be empty");
		}
		name = n;
	}
	void setStreak(int s) {
		if (s < 0) {
			throw invalid_argument("Streak must be greter than 0");
		}
		streak = s;
	}
	void setCompletedToday(bool c) {
		completedToday = c;
	}
	void updateStreak() {
		if (completedToday) {
			streak++;
		}
		else {
			resetStreak();
		}
	}
	void markCompletedToday(bool c) {
		completedToday = c;
		if (c) {
			updateStreak();
		}
		else {
			resetStreak();
		}
	}
	void markNotCompletedToday() {
		completedToday = false;
		resetStreak();
	}
	void resetStreak() {
		streak = 0;
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string n;
		int s;
		bool c;
		setColor(10);
		cout << "*****************************" << endl;
		cout << "*                           *" << endl;
		setColor(14);
		cout << "*       Habit Input          *" << endl;
		setColor(10);
		cout << "*                           *" << endl;
		cout << "*****************************" << endl;
		setColor(15);
		cout << "*       Enter habit name: " << "        " << endl;
		getline(cin, n);
		cout << "*       Enter current streak: " << "        " << endl;
		cin >> s;
		cin.ignore();
		cout << "Did you complete it today? (1/0): " << "        " << endl;
		cin >> c;
		cin.ignore();
		setColor(10);
		cout << "*                           *" << endl;
		cout << "*****************************" << endl;
		name = n;
		streak = s;
		completedToday = c;
		updateStreak();
	}
	void display() {
		cout << "*****************************" << endl;
		cout << "*                           *" << endl;
		cout << "*       Habit               *" << endl;
		cout << "*                           *" << endl;
		cout << "*****************************" << endl;
		cout << "*       Name:" << name << "       *" << endl;
		cout << "*       Streak: " << streak << "       *" << endl;
		cout << "Today: " << (completedToday ? "Done" : "Not Done") << endl;
		cout << "*                           *" << endl;
		cout << "*****************************" << endl;
	}

};