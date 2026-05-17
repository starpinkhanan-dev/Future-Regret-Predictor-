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

class Task {
private:
	string title;
	string timeSlote;
	bool isDone;
public:
	Task() {}
	Task(string t, string s, bool d) {
		if (t.empty()) {
			throw invalid_argument("Title must be letters ");
		}
		if (s.empty()) {
			throw invalid_argument("TIME must be letters");
		}
		title = t;
		timeSlote = s;
		isDone = d;
	}
	void setTitle(string t) {
		if (t.empty()) {
			throw invalid_argument("Title must be letters ");

		}
		title = t;
	}
	void setTimeSlote(string s) {
		if (s.empty()) {
			throw invalid_argument("TIME must be letters");
		}
		timeSlote = s;
	}
	void setIsdone(bool  d) {
		isDone = d;
	}
	string getTitle() {
		return title;
	}
	string getTimeslote() {
		return timeSlote;
	}
	bool  getIsdone() {
		return isDone;
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string t, s;
		bool d;
		setColor(10);
		cout << "*****************************" << endl;
		cout << "*                           *" << endl;
		setColor(14);
		cout << "*       Task Input           *" << endl;
		setColor(10);
		cout << "*                           *" << endl;
		cout << "*****************************" << endl;
		setColor(15);
		cout << "*       Enter task title: " << "       " << endl;
		getline(cin, t);
		cout << "*       Enter time slote: " << "       " << endl;
		getline(cin, s);
		cout << "Is it done? (1 yes / 0 no): ";
		cin >> d;
		cin.ignore();
		setColor(10);
		cout << "*                           *" << endl;
		cout << "****************************************************" << endl;
		title = t;
		timeSlote = s;
		isDone = d;
	}
	void display() {
		cout << "*****************************" << endl;
		cout << "*                           *" << endl;
		cout << "*       Task                *" << endl;
		cout << "*                           *" << endl;
		cout << "*****************************" << endl;
		cout << "*       Title:" << title << "       *" << endl;
		cout << "*       Time slote:" << timeSlote << "       *" << endl;
		cout << "Status: " << (isDone ? "Done" : "Not Done") << endl;
		cout << "*                           *" << endl;
		cout << "****************************************************" << endl;
	}

};

