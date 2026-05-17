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

class DecisionHistory {
private:
	string olddecicion;
	bool wassucessful;
public:
	DecisionHistory() {}
	DecisionHistory(string od, bool ws) {
		for (char c : od) {
			if (!isalpha(c) && c != ' ') {
				throw invalid_argument("DecisionHistory");
			}
		}
		olddecicion = od;
		wassucessful = ws;

	}

	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string od;
		bool ws;
		setColor(10);
		cout << "*****************************" << endl;
		cout << "*                           *" << endl;
		setColor(14);
		cout << "*     Decision History       *" << endl;
		setColor(10);
		cout << "*                           *" << endl;
		cout << "*****************************" << endl;
		setColor(15);
		cout << "*       Enter old decision: " << "       " << endl;
		getline(cin, od);
		cout << "*       Was it successful? (1 for yes, 0 for no): " << "       " << endl;
		cin >> ws;
		cin.ignore();
		setColor(10);
		cout << "*                           *" << endl;
		cout << "****************************************************" << endl;
		olddecicion = od;
		wassucessful = ws;

	}
	void display() {
		cout << "*****************************" << endl;
		cout << "*                           *" << endl;
		cout << "*      Old Decicion: " << olddecicion << "       *" << endl;
		cout << "*      Was sucessful: " << wassucessful << "       *" << endl;
		cout << "*                           *" << endl;
		cout << "****************************************************" << endl;
	}


};
