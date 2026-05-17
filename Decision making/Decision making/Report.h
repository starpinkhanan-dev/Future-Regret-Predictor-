#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <windows.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Task.h"
#include "DecisionMaking.h"
using namespace std;

class Report {
private:
	int totalTasks;
	int completedTasks;

	int goodDecisions;
	int badDecisions;

	int delayedTasks;

	double productivityScore;

public:
	Report() {
		totalTasks = 0;
		completedTasks = 0;
		goodDecisions = 0;
		badDecisions = 0;
		delayedTasks = 0;
		productivityScore = 0;
	}

	void generateReport(Task t, DecisionMaking d) {

		totalTasks = 1;

		completedTasks = (t.getIsdone() ? 1 : 0);

		if (d.getResults() == "Good Decision ")
			goodDecisions = 1;
		else
			goodDecisions = 0;

		badDecisions = (goodDecisions == 0 ? 1 : 0);

		delayedTasks = (d.getIsDelayed() ? 1 : 0);

		calculateProductivity();
	}

	void setTotalTasks(int tt) {
		if (tt < 0)
			throw invalid_argument("Total tasks cannot be negative.");
		totalTasks = tt;
	}

	void setCompletedTasks(int ct) {
		if (ct < 0)
			throw invalid_argument("Completed tasks cannot be negative.");
		completedTasks = ct;
	}

	void setGoodDecisions(int gd) {
		if (gd < 0)
			throw invalid_argument("Good decisions cannot be negative.");
		goodDecisions = gd;
	}

	void setBadDecisions(int bd) {
		if (bd < 0)
			throw invalid_argument("Bad decisions cannot be negative.");
		badDecisions = bd;
	}

	void setDelayedTasks(int dt) {
		if (dt < 0)
			throw invalid_argument("Delayed tasks cannot be negative.");
		delayedTasks = dt;
	}

	void calculateProductivity() {

		if (totalTasks == 0)
			productivityScore = 0;
		else
			productivityScore =
			(completedTasks * 100.0) / totalTasks;

		productivityScore += goodDecisions * 2;
		productivityScore -= badDecisions * 2;
		productivityScore -= delayedTasks * 1.5;

		productivityScore =
			max(0.0, min(100.0, productivityScore));
	}

	void displayReport() {

		cout << "******************************" << endl;
		cout << "*        DAILY REPORT       *" << endl;
		cout << "******************************" << endl;

		cout << "Total Tasks: " << totalTasks << endl;
		cout << "Completed Tasks: " << completedTasks << endl;
		cout << "Good Decisions: " << goodDecisions << endl;
		cout << "Bad Decisions: " << badDecisions << endl;
		cout << "Delayed Tasks: " << delayedTasks << endl;

		cout << "******************************" << endl;

		calculateProductivity();

		if (productivityScore >= 80) {
			cout << "Excellent Day" << endl;
		}
		else if (productivityScore >= 50) {
			cout << "Average Day" << endl;
		}
		else {
			cout << "Needs Improvement" << endl;
		}

		cout << "Productivity Score: "
			<< productivityScore << "%" << endl;
	}
};