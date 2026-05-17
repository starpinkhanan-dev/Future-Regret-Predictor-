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
#include "DailyStatus.h"
using namespace std;


class DecisionMaking : public Person {
private:
	string decision;
	int importanceLevel;
	int effortLevel;
	string results;
	string dependsOn;
	bool isDelayed;
	int penalty;

public:
	DecisionMaking() {}
	DecisionMaking(string n, int userid, string d, int il, int el, string dn, bool sd, int p) : Person(n, userid) {
		if (d.empty()) {
			throw invalid_argument("Decision cannot be empty.");
		}
		if (il < 1 || il > 10) {
			throw invalid_argument("Importance level must be between 1 and 10.");
		}
		if (el < 1 || el > 10) {
			throw invalid_argument("Effort level must be between 1 and 10.");
		}
		if (dn.empty()) {
			throw invalid_argument("Depends on cannot be empty.");
		}
		if (p < 0) {
			throw invalid_argument("Penalty cannot be negative.");
		}
		decision = d;
		importanceLevel = il;
		effortLevel = el;
		dependsOn = dn;
		isDelayed = sd;
		if (isDelayed && p == 0) {
			throw invalid_argument("Delayed decisions must have a penalty.");
		}
	}
	void setDecision(string d) {
		if (d.empty()) {
			throw invalid_argument("Decision cannot be empty.");
		}
		decision = d;
	}
	void setImportanceLevel(int il) {
		if (il < 1 || il > 10) {
			throw invalid_argument("Importance level must be between 1 and 10.");
		}
		importanceLevel = il;
	}
	void setEffortLevel(int el) {
		if (el < 1 || el > 10) {
			throw invalid_argument("Effort level must be between 1 and 10.");
		}
		effortLevel = el;
	}
	void setResults(string r) {
		if (r.empty()) {
			throw invalid_argument("Results cannot be empty.");
		}
		results = r;
	}
	void setDependsOn(string dn) {
		if (dn.empty()) {
			throw invalid_argument("Depends on cannot be empty.");
		}
		dependsOn = dn;
	}
	void setIsDelayed(bool sd) {
		isDelayed = sd;
	}
	void setPenalty(int p) {
		if (p < 0) {
			throw invalid_argument("Penalty cannot be negative.");
		}
		if (isDelayed && p == 0) {
			throw invalid_argument("Delayed decisions must have a penalty.");
		}
		penalty = p;
	}
	string getDecision() {
		return decision;
	}
	string getResults() {
		return results;
	}

	bool getIsDelayed() {
		return isDelayed;
	}

	int getImportanceLevel() {
		return importanceLevel;
	}

	int getEffortLevel() {
		return effortLevel;
	}
	void analyzeDecision(DailyStatus ds) {
		int score = 0;
		string mood = ds.getMood();
		for (char& c : mood) c = tolower(c);

		if (ds.getEnergyLevel() < 4) {
			score -= 2;
		}

		if (mood == "stressed")
			score -= 2;

		if (isDelayed)
			score -= penalty;

		if (dependsOn != "none")
			score -= 1;
		score += importanceLevel * 2;
		score -= effortLevel;

		if (score >= 6) {
			results = "Good Decision ";
		}
		else if (score >= 3) {
			results = "Warning. ";
		}
		else {
			results = "High Risk of Regret .";
		}
	}
	void delayDecision()
	{
		isDelayed = true;
		penalty += 2;
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string d, dn, n;
		int il, el, p, userid;
		bool sd;
		setColor(10);
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		setColor(14);
		cout << "*     DECISION ANALYSIS      *" << endl;
		setColor(10);
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		setColor(14);
		cout << "*      Please enter your decision information: " << "      " << endl;
		setColor(10);
		cout << "*        Enter your name: " << "     " << endl;
		getline(cin, n);
		setColor(13);
		cout << "*        Enter your ID: " << "     " << endl;
		cin >> userid;
		cin.ignore();
		setColor(15);
		cout << "*        Enter your decision: " << endl;
		getline(cin, d);
		setColor(9);
		cout << "*        Enter importance level (1-10): " << "     " << endl;
		cin >> il;
		cin.ignore();
		setColor(12);
		cout << "*        Enter effort level (1-10): " << "     " << endl;
		cin >> el;
		cin.ignore();
		setColor(11);
		setColor(10);
		cout << "*        Enter depends on (or 'none'): " << "     " << endl;
		getline(cin, dn);
		setColor(9);
		cout << "*        Is this decision delayed? (1 for yes, 0 for no): " << "     " << endl;
		cin >> sd;
		cin.ignore();
		setColor(12);
		name = n;
		id = userid;
		decision = d;
		importanceLevel = il;
		effortLevel = el;
		dependsOn = dn;
		isDelayed = sd;

		if (sd)
			setPenalty(2);
		else
			setPenalty(0);
		analyzeDecision(DailyStatus(n, userid, "neutral", "none", "none", 5, "none", "none", "none"));


	}
	void display() override {
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		cout << "*     DECISION ANALYSIS      *" << endl;
		cout << "*                            *" << endl;
		cout << "******************************" << endl;
		cout << "*                            *" << endl;
		cout << "*        Name:   " << name << "      " << endl;
		cout << "*        ID  :     " << id << "     " << endl;
		cout << "*        Decision:   " << decision << "      " << endl;
		cout << "*        Importance Level:  " << importanceLevel << "/10" << "         " << endl;
		cout << "*        Effort Level:    " << effortLevel << "/10" << "         " << endl;
		cout << "*        Analysis Result: " << results << "         " << endl;
		cout << "*        Depends On: " << dependsOn << "         " << endl;
		cout << "*        Is Delayed: " << (isDelayed ? "Yes" : "No") << "         " << endl;
		cout << "*        Penalty if Delayed: " << penalty << "         " << endl;
		cout << "*                            *" << endl;
		cout << "****************************************************" << endl;
	}

};

