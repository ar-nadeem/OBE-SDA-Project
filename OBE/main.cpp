#define _win32_winnt 0x0501
#define _win32_winnt 0x0500
#include <conio.h>
#include <process.h> //exit(0)
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <string>
#include "Interface.h"


void clear()
{
	system("cls");
}
void clearBuffer() {
	fflush(stdin);
	cin.clear();
	while (cin.get() != '\n')
	{
		continue;
	}
}
void PauseScreen() {
	system("Pause");
	clearBuffer();
	clear();
}


int createMenu(string* s, int size, Interface* main, int type);

int state = 0;
int firstLoop = 0;
int ID;

string test[10] = { "Login", "Done","Login", "Done","Login", "Done","Login", "Done","Login", "Done" };



string Init[3] = { "Login","Signup","Exit"};
string menu2[7] = { "Create Program", "Display Program","Create PLO","Display PLO","Create Course","Display Course","Logout"};
string menu3[10] = { "Create CLO","Create Evaluation","Add Questions to Evaluation","------","Display Evaluations","Display CLO","Check CLO on Question","Check CLO on Course","Display Courses","Logout"};


using namespace std;

//string strings[6] =
//{
//	"Login as Student",
//	"Login as Parent",
//	"Login as Teacher",
//	"Signup for a Student account",
//	"Signup for a Parent account",
//	"Signup for a Teacher account"
//};

//the gotoo function is used to change the position of the 
//cursor on the console screen at any moment in time
void gotoo(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//the show console cursor is used to disable the
//console and keep it from blinking or showing

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void FirstScreen(string String[], int size)
{
	int y = 8;
	int horBar = 6;//ascii value for a bar
	int verBar = 43;//ascii value for a bar
	char box = 219;//ascii value for a box
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	//above line basically changes the color of the text with whatever number you provide
	//its built in function
	for (int i = 43; i < 80; i++)
	{
		gotoo(i, horBar);
		cout << box;
		Sleep(10);
	}


	horBar = 19;
	for (int i = 43; i < 80; i++)
	{
		gotoo(i, horBar);
		cout << box;
		Sleep(10);
	}
	for (int i = 6; i < 20; i++)
	{
		gotoo(verBar, i);
		cout << box;
		Sleep(10);
	}
	verBar = 80;
	for (int i = 6; i < 20; i++)
	{
		gotoo(verBar, i);
		cout << box;
		Sleep(10);
	}
	//all above for loops are used for printing a box animation around the option menu


	//size_t n = (int)(sizeof(String) / sizeof(String[0]));
	for (int i = 0; i < size; i++, y++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoo(47, y);
		std::cout << String[i] << endl;
		//above lines are used to print the menu options for the user to interact with
	}
}


//below function is used to highlight which ever option in
//the menu is selected. Highlights in blue
void selectedChoice(bool flag, string array[])
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	//above line Highlights in blue
	gotoo(47, state + 8);
	std::cout << array[state];

	if (flag == true)
	{
		state++;
	}
	else
	{
		state--;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoo(47, state + 8);
	std::cout << array[state];
	Sleep(150);
	//a simple sleep function to animate (built-in)
}

void Refresh()
//this function is used whenever we have to reset the console blinkiing attribute after 
//selecting a choice
{
	clear();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	ShowConsoleCursor(true);
}

//the function below is the menu fully implemented and all options working and ready to be selected :)
int Menu(string* String, int size, int type, Interface* main)
{
	while (firstLoop < 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		gotoo(47, 8);
		std::cout << String[0] << endl;
		firstLoop++;
	}
	//the GetAsyncKeyState Determines whether 
	//a key is up or down at the time the function is called, and whether
	//the key was pressed after a previous call to GetAsyncKeyState.
	if (GetAsyncKeyState(VK_DOWN) && state < (size-1))
	{
		selectedChoice(true, String);
	}
	else if (GetAsyncKeyState(VK_DOWN) && state == (size - 1))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoo(47, state + 8);
		std::cout << String[state];

		state = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		gotoo(47, state + 8);
		std::cout << String[state];
		Sleep(150);
	}

	else if (GetAsyncKeyState(VK_UP) && state > 0)
	{
		selectedChoice(false, String);
	}

	else if (GetAsyncKeyState(VK_UP) && state == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoo(47, state + 8);
		std::cout << String[state];

		state = (size - 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		gotoo(47, state + 8);
		std::cout << String[state];
		Sleep(150);
	}
	//GetAsyncKeyState(VK_RETURN) is used to check whether the
	//'Enter' key has been pressed and then calls the function
	//on whatever option/choice is selected.

	else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{

		if (type == 0) {
			Sleep(150);
			if (state == 0) // Login AO
			{
				clearBuffer(); // Clear CIN it is a must other wise new lines in buffer messes with program
				clear();
				string u, p;
				cout << "Enter Username :";
				getline(cin, u);
				cout << "Enter Password :";
				getline(cin, p);
				//cout << "\n" << u << " " << p << " \n"; // For debug
				//system("Pause");

				if (main->handleLogin(u, p)) {
					clear();
					main->display_current_user();
					
					system("PAUSE");
					if (main->getTypeofUser() == "AO") {
						clear();
						return 1; // AO Menu
						//createMenu(menu2, 7, main,1); // Create Academic Officer Menu
					}
					else {
						clear();
						return 2; // Teacher Menu
						//createMenu(menu3, 9, main, 2); // Create Teacher Menu
					}

				}
				else {
					clear();
					cout << "FAILED LOGIN !\n";
					system("PAUSE");
					

					//return true;
					clear();
					return 0; // Init Menu
					//createMenu(Init, 2, main, 0); // restart Menu
				}

			
			}
			else if (state == 1) // Signup
			{
				clearBuffer(); // Clear CIN it is a must other wise new lines in buffer messes with program
				clear();

				main->firstStart();

				PauseScreen();
				return 0; // restart menu 0
			}
			else if (state == 2) // Done - Exit
			{
				clear();
				exit(0);
			}
			}

		//createMenu(menu2, 3, main, 1); // restart Menu
		if (type == 1) {
			Sleep(150);
			if (state == 0) // Create Program
			{	
				clear();
				clearBuffer();

				string n, d;
				int id;
				cout << "Enter Name: ";
				getline(cin, n);
				cout << "Enter Department: ";
				getline(cin, d);
				cout << "Enter ID: ";
				cin >> id;
				main->createProgram(n,d,id);

				//cout << "\n" << n << " " << d << " " << id << " \n"; // For debug
				
				PauseScreen();
				return 1;
				//createMenu(menu2, 7, main, 1); // restart Menu
			}

			else if (state == 1) // Display Program
			{
				clear(); // Clear Screen
				main->getAllPrograms();

				system("pause"); // Pause Screen
				clear();
				return 1;
				//createMenu(menu2, 7, main, 1); // restart Menu
			}

			else if (state == 2) // Create PLO
			{
				clear();
				clearBuffer();
			
				string n, d;
				int id,c;
				cout << "Enter Name: ";
				getline(cin, n);
				cout << "Enter Description: ";
				getline(cin, d);
				cout << "Enter Code: ";
				cin >> c;

				cout << "Enter Program ID: ";
				cin >> id;

				main->createPLO(n, c, d);
				main->addPLOtoProgrambyID(id);

				//cout << "\n" << n << " " << d << " " << id << " \n"; // For debug
				PauseScreen();
				return 1;
				//createMenu(menu2, 7, main, 1); // restart Menu
			}

			else if (state == 3)// Display - PLO
			{
				clear();
				clearBuffer();

				int id;
				cout << "Enter Program ID: ";
				cin >> id;
				
				//cout << "\n" << id;

				main->printPLOinProgram(id);

				PauseScreen();
				return 1;
				//createMenu(menu2, 7, main, 1); // restart Menu
			}

			else if (state == 4) // Create Course
			{
				clear();
				clearBuffer();

				string CourseName;
				int CreditHour;
				int id;
				string CourseCode;
				cout << "Enter Course Name: ";
				getline(cin, CourseName);
				cout << "Enter Credit Hours: ";
				cin >> CreditHour;
				cout << "Enter Course Code: ";
				getline(cin, CourseCode);

				cout << "Enter PLO ID: ";
				cin >> id;

				main->createCourse(CourseName, CreditHour, CourseCode);
				main->addCourseToPLObyID(id);


				PauseScreen();
				return 1;
				//createMenu(menu2, 7, main, 1); // restart Menu
			}

			else if (state == 5) // Display Course
			{
				clear();
				clearBuffer();

				int idPLO = -1;

				int idProgram;
				
				cout << "Enter Program ID: ";
				cin >> idProgram;
				cout << "Enter PLO ID (Enter -1 FOR ALL COURSES IN PROGRAM): ";
				cin >> idPLO;


				if (idPLO) {
					main->printCoursesinPLO(idProgram, idPLO);
				}
				else {
					main->printCoursesinProgram(idProgram);
				}
				
				

				PauseScreen();
				return 1;
				//createMenu(menu2, 7, main, 1); // restart Menu
			}
			else if (state == 6) //  Logout
			{
				clear();
				return 0;
				//createMenu(Init, 2, main, 1); // Get back to Login Menu
			}
			else if (state == 7){}
		}

		if (type == 2) {
			Sleep(150);
			if (state == 0) // Create CLO
			{
				clear();
				clearBuffer();
				if (main->isEmptyCourses()) {
					cout << "\nFirst Add Courses\n";

					PauseScreen();
					return 2;
				}

				string n, d;
				int c;
				cout << "Enter CLO Name: ";
				clearBuffer();
				getline(cin, n);
				cout << "Enter Description: ";
				getline(cin, d);
				cout << "Enter CLO ID: ";
				cin >> c;


				main->createCLO(n, c, d);

				string cid;

				cout << "Enter Course ID : ";
				clearBuffer();
				getline(cin, cid);

				main->addCLOToCourse(cid);

				string temp;
				cout << "Keep entring Topics covered in CLO ( -1 to STOP) : ";
				cin >> temp;
				while (temp != "-1") {
					main->addTopicCovered(temp);
					cin >> temp;
				}

				PauseScreen();
				return 2;
			}

			else if (state == 1) // Create Evaluation
			{
				clear();
				clearBuffer();

				string type;
				float marks;
				float weightage;
				string date; 
				int id;

				cout << "Enter Type (Quiz etc) : ";
				getline(cin, type);
				cout << "Enter Marks : ";
				cin >> marks;
				cout << "Enter Weightage : ";
				cin >> weightage;
				cout << "Enter Date : ";
				clearBuffer();
				getline(cin, date);
				cout << "Enter ID : ";
				cin >> id;

				main->createEvaluation(type, marks, weightage, date, id);

				main->getEvaluation();

				PauseScreen();
				return 2;
			}

			else if (state == 2) // Add Questions to Evaluation
			{
				clear();
				clearBuffer();

				int id;
				string name;
				int eid;
				cout << "Enter Question ID: ";
				cin >> id;
				cout << "Enter Question Name: ";
				clearBuffer();
				getline(cin, name);
				cout << "Enter Evaluation ID: ";
				cin >> eid;

				main->createQuestion(id,name);

				clearBuffer();
				int cloid = 1;
				cout << "Enter CLO ID to add to Question (-1 to stop) : ";
				while (true) {
					cin >> cloid;
					if (cloid == -1) { break; }
					main->addCLOToQuestion(id);
				}

				main->addQuestionsToEvaluation(eid);

				PauseScreen();
				return 2;
			}

			else if (state == 3) // Add CLO to Course
			{
				clear();
				clearBuffer();

				cout << "\n----- 20L-0935 - AbdulRahman Nadeem ----\n";
				cout << "----- Babik ----\n";

				PauseScreen();
				return 2;
			}

			else if (state == 4) // Display Evaluations
			{
				clear();
				clearBuffer();

				int eid;
				cout << "Enter Evaluation ID (-1 for all) : ";
				cin >> eid;

				if (eid == -1) {
					main->getEvaluation();
				}
				else{
					main->getEvaluation(eid);
				}

				PauseScreen();
				return 2;
			}

			else if (state == 5) // Display CLO
			{
				clear();
				clearBuffer();

				int idQid;

				string idCourse;
				int CLOID;
				int opt;
				int EID;
				cout << "1 - Course Code | 2 - Question ID | 3 - Evaluation : ";
				cin >> opt;
				if (opt == 1) {
					cout << "Enter Course Code: ";
					clearBuffer();
					getline(cin, idCourse);

					main->printCLObyCourseID(idCourse);

				}
				else if (opt == 2) {
					cout << "Enter Question ID: ";
					cin >> idQid;

					main->printCLObyQID(idQid);
				}
				else if (opt == 3) {
					cout << "Enter Evaluation ID: ";
					cin >> EID;

					main->printCLObyEID(EID);
				}



				PauseScreen();
				return 2;
			}
			else if (state == 6) // Check CLO on Question
			{
				clear();
				clearBuffer();

				int qid1,qid2, eid,cid;
				cout << "Enter Evaluation ID: ";
				cin >> eid;

				cout << "Enter CLO ID: ";
				cin >> cid;

				cout << "Enter Question ID (1): ";
				cin >> qid1;

				cout << "Enter Question ID (2): ";
				cin >> qid2;

				if (main->checkCLOTestbyQID(eid, qid1, cid)) {
					cout << "\nQuestion " << qid1 << " satisfies the given CLO\n";
				}
				else {
					cout << "\nQuestion " << qid1 << " DOES NOT satisfy the given CLO\n";
				}

				if (main->checkCLOTestbyQID(eid, qid2, cid)) {
					cout << "\nQuestion "<<qid2<<" satisfies the given CLO\n";
				}
				else {
					cout << "\nQuestion " << qid2 << " DOES NOT satisfy the given CLO\n";
				}

				PauseScreen();
				return 2;
			}
			else if (state == 7) // Check CLO by Course on  Evaluation
			{
				clear();
				clearBuffer();
				string cid;
				int eid;

				cout << "Enter Course ID: ";
				getline(cin, cid);
				cout << "Enter Evaluation ID: ";
				cin >> eid;

				if (main->checkCLOTestbyCourseID(cid, eid)) {
					cout << "\nALL ARE TESTED | SUCCESS\n";
				}
				else {
					cout << "\nNOT TESTED | FAILED\n";
				}

				PauseScreen();
				return 2;

			}
			else if (state == 8) // Display Courses
			{
				clear();
				clearBuffer();

				main->PrintAllCourses();

				PauseScreen();
				return 2;
			}
			else if (state == 9) // Logout
			{
				clear();
				return 0;
				//clear();
				//createMenu(Init, 2, main, 1); // Get back to Login Menu
			}
		}
		
	}

	return -1;
	/*return true;*/
}

int createMenu(string* s,int size,Interface *main,int type) {
	clear();
	state = 0;
	firstLoop = 0;
	
	
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLongA(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	FirstScreen(s, size);
	ShowConsoleCursor(false);

	//string strings2[3] = { "Add Academic Officer", "Add Teacher", "Done" };

	
	int val = -1;
	while (true)
	{
		
		val = Menu(s, size, type, main);
		if (val != -1) {
			return val;
		}

		

	}

}


int main() {



	Interface main;
	//main.firstStart();
	main.debug_start();
	main.Save();
	int val = 0;

	while (true) {
		if (val == 0) {
			
			val = createMenu(Init, 3, &main, 0); // Main Menu
			clearBuffer();
			main.Save();
		}
		else if (val == 1) {

			val = createMenu(menu2, 7, &main, 1); // AO Menu
			clearBuffer();
			main.Save();
		}
		else if (val == 2) {

			val = createMenu(menu3, 10, &main, 2); // Teacher Menu
			clearBuffer();
			main.Save();
		}
	}

	

	//clear();
	return 0;

}