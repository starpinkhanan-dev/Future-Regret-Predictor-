#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <windows.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Person.h"
#include "BehaviorAnalysis.h"
#include "DailyStatus.h"
#include "DecisionMaking.h"
#include "DecisionHistory.h"
#include "Habit.h"
#include "Profile.h"
#include "Report.h"
#include "Reward.h"
#include "Timeperiod.h"

using namespace std;
void compareRewards(Reward r1, Reward r2) {
	cout << "==============================" << endl;
	cout << "*                            *" << endl;
	cout << "* Comparing Rewards:" << endl;
	cout << "* Reward 1 Points: " << r1.rewaredpoint << "       *" << endl;
	cout << "* Reward 2 Points: " << r2.rewaredpoint << "       *" << endl;
	cout << "*                            *" << endl;
	cout << "==============================" << endl;
	if (r1.rewaredpoint > r2.rewaredpoint) {
		cout << "Reward 1 has more points." << endl;
	}
	else if (r1.rewaredpoint < r2.rewaredpoint) {
		cout << "Reward 2 has more points." << endl;
	}
	else {
		cout << "Both rewards have the same points." << endl;
	}
}
int main() {
	cout << "                 =====================================                    " << endl;
	cout << "===================================================================================" << endl;
	cout << "= Welcome to the Personal Productivity and Decision Making Assistant              =" << endl;
	cout << "=                                                                                 =" << endl;
	cout << "= This system helps you track productivity, decisions, habits, etc.               =" << endl;
	cout << "=                                                                                 =" << endl;
	cout << "= It provides insights and suggestions to improve your daily life.                =" << endl;
	cout << "=                                                                                 =" << endl;
	cout << "= You can create a profile, log your daily status, and analyze your decisions.    =" << endl;
	cout << "=                                                                                 =" << endl;
	cout << "= The system also allows you to set tasks, habits, and rewards to stay motivated. =" << endl;
	cout << "=                                                                                 =" << endl;
	cout << "= It analyzes your daily status and provides feedback on your decisions.          =" << endl;
	cout << "=                                                                                 =" << endl;
	cout << "= You can input your daily tasks, habits, and rewards to stay motivated.          =" << endl;
	cout << "=                                                                                 =" << endl;
	cout << "= Please enter your daily information to get started!                             =" << endl;
	cout << "===================================================================================" << endl;
	cout << "                 =====================================                    " << endl;
	Sleep(10000);
	system("cls");
	Profile userProfile;
	DailyStatus dailyStatus;
	DecisionMaking decision;
	DecisionHistory decisionHistory;
	Task task;
	Habit habit;
	BehaviorAnalysis behviorAnalysis;
	Reward reward(0);
	Timeperiod timeperiod;
	Report report;
	int choice;
	do {
		cout << "==================================================" << endl;
		cout << "================ MENU ============================" << endl;
		cout << "1. Profile" << "                      =" << endl;
		cout << "2. Daily Status" << "                 =" << endl;
		cout << "3. Task" << "                         =" << endl;
		cout << "4. Habit" << "                        =" << endl;
		cout << "5. Time Period" << "                  =" << endl;
		cout << "6. Decision Making" << "              =" << endl;
		cout << "7. Decision History" << "             =" << endl;
		cout << "8. Behavior Analysis" << "            =" << endl;
		cout << "9. Report" << "                       =" << endl;
		cout << "10. Reward" << "                      =" << endl;
		cout << "0. Exit" << "                         =" << endl;
		cout << "==================================================" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore();
		cout << "==================================================" << endl;
		switch (choice) {
		case 1:
			system("cls");
			try {
				userProfile.input();
				userProfile.display();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 2:
			system("cls");
			try {
				dailyStatus.input();
				dailyStatus.display();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 3:
			system("cls");
			try {
				task.input();
				if (task.getIsdone()) {
					reward.addpoints(10, "Completed Task");
				}
				task.display();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 4:
			system("cls");
			try {
				habit.input();
				habit.display();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 5:
			system("cls");
			try {
				timeperiod.input();
				timeperiod.display();

			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 6:
			system("cls");
			try {
				decision.input();
				decision.analyzeDecision(dailyStatus);
				decision.display();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 7:
			system("cls");
			try {
				decisionHistory.input();
				decisionHistory.display();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 8:
			system("cls");
			try {
				behviorAnalysis.input();
				behviorAnalysis.displayBehaviorAnalysis();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 9:
			system("cls");
			try {
				report.generateReport(task, decision);
				report.displayReport();

				system("pause");
				system("cls");
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cin.ignore();
				cin.get();
				system("cls");
			}
			break;
		case 10:
			system("cls");
			try {
				reward.input();
				reward.display();
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			break;
		case 0:
			system("cls");
			try {
				compareRewards(Reward(50), Reward(30));

			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
				cout << "\nPress Enter to return to menu...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice\n";
			cout << "\nPress Enter to return to menu...";
			cin.ignore();
			cin.get();
			system("cls");
		}
	} while (choice != 0);
	return 0;
}