#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <windows.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Person.h"	
using namespace std;



class DailyStatus : public Person {
private:
	string mood;
	string completedTasks;
	string delayedTasks;
	int energyLevel;
	string positiveEvents;
	string negativeEvents;
	string internalDesires;
public:
	DailyStatus() {}
	DailyStatus(string n, int userid, string m, string ct, string d, int el, string pe, string ne, string nd) : Person(n, userid) {
		if (m.empty()) {
			throw invalid_argument("Mood cannot be empty.");
		}
		if (ct.empty()) {
			throw invalid_argument("Completed tasks cannot be empty.");
		}
		if (d.empty()) {
			throw invalid_argument("Delayed tasks cannot be empty.");
		}
		if (el < 1 || el > 10) {
			throw invalid_argument("Energy level must be between 1 and 10.");
		}
		if (pe.empty()) {
			throw invalid_argument("Positive events	 cannot be empty.");
		}
		mood = m;
		completedTasks = ct;
		delayedTasks = d;
		energyLevel = el;
		positiveEvents = pe;
		negativeEvents = ne;
		internalDesires = nd;
	}
	void setCompletedTasks(string ct) {
		if (ct.empty()) {
			throw invalid_argument("Completed tasks cannot be empty.");
		}
		completedTasks = ct;
	}
	void setDelayedTasks(string dt) {
		if (dt.empty()) {
			throw invalid_argument("Delayed tasks cannot be empty.");
		}
		delayedTasks = dt;
	}
	void setEnergyLevel(int el) {
		if (el < 1 || el > 10) {
			throw invalid_argument("Energy level must be between 1 and 10.");
		}
		energyLevel = el;
	}
	void setPositiveEvents(string pe) {
		if (pe.empty()) {
			throw invalid_argument("Positive events cannot be empty.");
		}
		positiveEvents = pe;
	}
	void setNegativeEvents(string ne) {
		if (ne.empty()) {
			throw invalid_argument("Negative events cannot be empty.");
		}
		negativeEvents = ne;
	}
	void setInternalDesires(string nd) {
		if (nd.empty()) {
			throw invalid_argument("Internal desires cannot be empty.");
		}
		internalDesires = nd;
	}
	string getMood() {
		return mood;
	}
	string getCompletedTasks() {
		return completedTasks;
	}
	string getDelayedTasks() {
		return delayedTasks;
	}
	int getEnergyLevel() {
		return energyLevel;
	}
	string getPositiveEvents() {
		return positiveEvents;
	}
	string getNegativeEvents() {
		return negativeEvents;
	}
	string getInternalDesires() {
		return internalDesires;
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string m, ct, dt, pe, ne, nd;
		int el;
		setColor(10);
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		setColor(14);
		cout << "*      DAILY STATUS INFO     *" << endl;
		setColor(10);
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		setColor(15);
		cout << "*        Enter your mood: " << "    " << endl;
		getline(cin, m);
		setColor(9);
		cout << "*        Enter completed tasks: " << "       " << endl;
		getline(cin, ct);
		setColor(3);
		cout << "*        Enter delayed tasks: " << "       " << endl;
		getline(cin, dt);
		setColor(12);
		cout << "*        Enter energy level (1-10): " << "       " << endl;
		cin >> el;
		cin.ignore();
		cout << "*        Enter positive events: " << "       " << endl;
		getline(cin, pe);
		setColor(13);
		cout << "*        Enter negative events: " << "       " << endl;
		getline(cin, ne);
		setColor(10);
		cout << "*        Enter internal desires: " << "       " << endl;
		getline(cin, nd);
		setColor(10);
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		mood = m;
		completedTasks = ct;
		delayedTasks = dt;
		energyLevel = el;
		positiveEvents = pe;
		negativeEvents = ne;
		internalDesires = nd;

	}
	void display() override {
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		cout << "*      DAILY STATUS INFO     *" << endl;
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		cout << "*        Mood: " << mood << "     " << endl;
		cout << "*        Completed Tasks: " << completedTasks << "       " << endl;
		cout << "*        Delayed Tasks: " << delayedTasks << "       " << endl;
		cout << "*        Energy Level: " << energyLevel << "/10" << endl;
		cout << "*        Positive Events: " << positiveEvents << "       " << endl;
		cout << "*        Negative Events: " << negativeEvents << "       " << endl;
		cout << "*        Internal Desires: " << internalDesires << "       " << endl;
		cout << "*                            *" << endl;
		cout << "****************************************************" << endl;
	}

};

