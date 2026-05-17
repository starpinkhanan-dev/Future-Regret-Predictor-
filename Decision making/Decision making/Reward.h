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

class Reward {
private:
	int	rewaredpoint;
public:
	Reward() {}
	Reward(int p) {
		if (p < 0) {
			throw invalid_argument("Reward points cannot be negative.");
		}
		rewaredpoint = p;
	}
	void addpoints(int p) {
		rewaredpoint += p;
	}
	void addpoints(int p, string reason) {
		rewaredpoint += p;

		cout << "Reward Added For: "
			<< reason << endl;
	}
	int getPoint() {
		return rewaredpoint;
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		int p;
		setColor(10);
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		setColor(14);
		cout << "*     Reward Points Input     *" << endl;
		setColor(10);
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		setColor(15);
		cout << "*        Enter reward points: " << endl;
		cin >> p;
		cin.ignore();
		setColor(10);
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		rewaredpoint = p;
		addpoints(p, "Daily Report");

	}
	void display() {
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		cout << "*    Rewaard Point           *" << rewaredpoint << "       *" << endl;
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
	}
	friend void compareRewards(Reward r1, Reward r2);
};
