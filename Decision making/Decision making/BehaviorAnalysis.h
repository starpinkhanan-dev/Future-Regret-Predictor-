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

class  BehaviorAnalysis {
private:
	int procrastinationcount;
public:
	BehaviorAnalysis() {}
	BehaviorAnalysis(int pt) {
		if (pt < 0) {
			throw invalid_argument("Behavior analysis not be empty ");;
		}
		procrastinationcount = pt;
	}
	void analyzeBehavior() {

		if (procrastinationcount == 0) {
			cout << "Excellent! No procrastination today." << endl;
		}

		else if (procrastinationcount <= 3) {
			cout << "Good, but try to reduce delays." << endl;
		}

		else if (procrastinationcount <= 6) {
			cout << "Warning: You delay tasks frequently." << endl;
		}

		else {
			cout << "High procrastination detected!" << endl;
		}
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);
	}
	void input() {
		int pt;
		setColor(10);
		cout << "******************************************" << endl;
		cout << "*                                        *" << endl;
		setColor(14);
		cout << "*         Behavior Analysis              *" << endl;
		setColor(10);
		cout << "*                                        *" << endl;
		cout << "******************************************" << endl;
		setColor(11);
		cout << "*         Procrastintion count: " << "          " << endl;
		cin >> pt;
		cin.ignore();
		setColor(10);
		cout << "**************************************************" << endl;
		procrastinationcount = pt;

	}
	void displayBehaviorAnalysis() {
		cout << "*******************************************" << endl;
		cout << "*                                         *" << endl;
		cout << "*         Behavior Analysis               *" << endl;
		cout << "*                                         *" << endl;
		cout << "*******************************************" << endl;
		cout << "*          Procrastintion count: " << procrastinationcount << endl;
		cout << "****************************************************" << endl;
		analyzeBehavior();
	}
};

