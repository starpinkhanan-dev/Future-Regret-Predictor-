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

class Profile : public Person {
private:
	string role;
	string goal;
	int age;
	string worktype;
	string studytype;
	string favoriteperiod;
public:
	Profile() {}
	Profile(string n, int userid, string r, string g, int a, string w, string s, string f) : Person(n, userid) {
		if (r.empty()) {
			throw invalid_argument("Role must be comblet");
		}
		if (g.empty()) {
			throw invalid_argument("Goal must be comblet");
		}
		if (a < 5) {
			throw invalid_argument(" Age must be greter than 5");
		}
		if (w.empty()) {
			throw invalid_argument("Work type must be comblet");
		}
		if (s.empty()) {
			throw invalid_argument("Study type must be comblet");
		}
		if (f.empty()) {
			throw invalid_argument("Favorite period must be comblet");
		}
		role = r;
		goal = g;
		age = a;
		worktype = w;
		studytype = s;
		favoriteperiod = f;
	}
	void setRole(string r) {
		if (r.empty()) {
			throw invalid_argument("Role must be comblet ");
		}
		role = r;
	}
	void setGoal(string g) {
		if (g.empty()) {
			throw invalid_argument("goal must be comblet");
		}

		goal = g;
	}

	void setAge(int a) {
		if (a < 5) {
			throw invalid_argument("Age must be greter than 5");
		}
		age = a;
	}
	string getRole() {
		return role;
	}
	string getGoal() {
		return goal;
	}
	int getAge() {
		return age;
	}
	void setColor(int color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}
	void input() {
		string r, g, w, s, f, n;
		int a, userid;
		setColor(10);
		cout << "**************************" << endl;
		cout << "*                        *" << endl;
		setColor(14);
		cout << "*        Provfile        *" << endl;
		setColor(10);
		cout << "*                        *" << endl;
		cout << "**************************" << endl;
		setColor(14);
		cout << "*      Please enter your profile information: " << "      " << endl;
		setColor(9);
		cout << "*      Enter your name: " << "      " << endl;
		getline(cin, n);
		setColor(13);
		cout << "*      Enter your ID: " << "       " << endl;
		cin >> userid;
		cin.ignore();
		setColor(12);
		cout << "*      Enter your role: " << "       " << endl;
		getline(cin, r);
		setColor(11);
		cout << "*      Enter your goal: " << "        " << endl;
		getline(cin, g);
		setColor(10);
		cout << "*      Enter your age: " << "          " << endl;
		cin >> a;
		cin.ignore();
		setColor(9);
		cout << "*      Enter your work type: " << "       " << endl;
		getline(cin, w);
		setColor(8);
		cout << "*      Enter your study type: " << "        " << endl;
		getline(cin, s);
		setColor(7);
		cout << "*      Enter your favorite period: " << "        " << endl;
		getline(cin, f);
		setColor(3);
		cout << "*                        *" << endl;
		cout << "**************************************************" << endl;
		name = n;
		id = userid;
		role = r;
		goal = g;
		age = a;
		worktype = w;
		studytype = s;
		favoriteperiod = f;

	}
	void display() override {
		cout << "**************************" << endl;
		cout << "*                        *" << endl;
		cout << "*        Provfile        *" << endl;
		cout << "*                        *" << endl;
		cout << "**************************" << endl;
		cout << "        Name: " << name << "          " << endl;
		cout << "        ID: " << id << "               " << endl;
		cout << "        Role: " << role << "           " << endl;
		cout << "        Goal: " << goal << "            " << endl;
		cout << "        Age: " << age << "          " << endl;
		cout << "        Work Type: " << worktype << "   " << endl;
		cout << "        Study Type: " << studytype << "   " << endl;
		cout << "        Favorite Period: " << favoriteperiod << "   " << endl;
		cout << "*****************************************************" << endl;
		cout << "****************************************************" << endl;
	}
};

