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
				MessageBoxA(NULL, "Profile Added Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR );

				system("cls");
				break;
			}
			break;
		case 2:
			system("cls");
			try {
				dailyStatus.input();
				dailyStatus.display();
				MessageBoxA(NULL, "Daily Status Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Daily Status Error", MB_OK | MB_ICONERROR);
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
				MessageBoxA(NULL, "Task Added Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
				system("cls");
				break;
			}
			break;
		case 4:
			system("cls");
			try {
				habit.input();
				habit.display();
				MessageBoxA(NULL, "Hapit Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
				system("cls");
				break;
			}
			break;
		case 5:
			system("cls");
			try {
				timeperiod.input();
				timeperiod.display();
				MessageBoxA(NULL, "Time period  Added Successfully", "Success", MB_OK | MB_ICONINFORMATION);

			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
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
				MessageBoxA(NULL, "Dicision making Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
				system("cls");
				break;
			}
			break;
		case 7:
			system("cls");
			try {
				decisionHistory.input();
				decisionHistory.display();
				MessageBoxA(NULL, "Decision History  Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
				system("cls");
				break;
			}
			break;
		case 8:
			system("cls");
			try {
				behviorAnalysis.input();
				behviorAnalysis.displayBehaviorAnalysis();
				MessageBoxA(NULL, "Behvior Analysis  Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
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
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
				system("cls");
				break;
			}
			break;
		case 10:
			system("cls");
			try {
				reward.input();
				reward.display();
				MessageBoxA(NULL, "Reward  Successfully", "Success", MB_OK | MB_ICONINFORMATION);
			}
			catch (const invalid_argument& e) {
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
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
				MessageBoxA(NULL, e.what(), "Input Error", MB_OK | MB_ICONERROR);
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
