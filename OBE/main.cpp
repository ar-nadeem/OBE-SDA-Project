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

int state = 0;
int firstLoop = 0;
int ID;

using namespace std;

string strings[6] =
{
	"Login as Student",
	"Login as Parent",
	"Login as Teacher",
	"Signup for a Student account",
	"Signup for a Parent account",
	"Signup for a Teacher account"
};

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
	horBar = 15;
	for (int i = 43; i < 80; i++)
	{
		gotoo(i, horBar);
		cout << box;
		Sleep(10);
	}
	for (int i = 6; i < 16; i++)
	{
		gotoo(verBar, i);
		cout << box;
		Sleep(10);
	}
	verBar = 80;
	for (int i = 6; i < 16; i++)
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

void clear()
{
	system("cls");
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
void Menu(string String[6])
{
	while (firstLoop < 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		gotoo(47, 8);
		std::cout << strings[0] << endl;
		firstLoop++;
	}
	//the GetAsyncKeyState Determines whether 
	//a key is up or down at the time the function is called, and whether
	//the key was pressed after a previous call to GetAsyncKeyState.
	if (GetAsyncKeyState(VK_DOWN) && state < 5)
	{
		selectedChoice(true, String);
	}
	else if (GetAsyncKeyState(VK_DOWN) && state == 5)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoo(47, state + 8);
		std::cout << strings[state];

		state = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		gotoo(47, state + 8);
		std::cout << strings[state];
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
		std::cout << strings[state];

		state = 5;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		gotoo(47, state + 8);
		std::cout << strings[state];
		Sleep(150);
	}
	//GetAsyncKeyState(VK_RETURN) is used to check whether the
	//'Enter' key has been pressed and then calls the function
	//on whatever option/choice is selected.

	else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		Sleep(150);
		if (state == 0)
		{

		}

		else if (state == 1)
		{

		}

		else if (state == 2)
		{

		}

		else if (state == 3)
		{

		}

		else if (state == 4)
		{

		}

		else if (state == 5)
		{
		}
	}
}




int main() {

	Interface main;
	main.firstStart();


	HWND consoleWindow = GetConsoleWindow();
	SetWindowLongA(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	FirstScreen(strings, 6);
	ShowConsoleCursor(false);

	string strings2[3] = { "Add Academic Officer", "Add Teacher", "Done" };

	while (1)
	{
		Menu(strings2);
	}





	cout << "\n\n\n\n\n\n";
	return 0;

}