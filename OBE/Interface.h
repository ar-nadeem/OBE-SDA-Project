#pragma once
#include "PUBLIC_HEADERS.h"
#include <stdlib.h>
#include <vector>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif





class Interface {
private:
	vector<AcademicOfficer*> officers;
	vector<Teacher*> teachers;

	User* current_user;



	// Clear Screen
	void cls() {
		system("CLS");
	}





	// Check for Username, Password in Academic Officers Vector
	AcademicOfficer* handleLoginAO(string username, string password) {
		for (auto& i : officers) {
			if (i->getUsername() == username) {
				if (i->getPassword() == password) {
					return i;
				}
			}
		}
		return nullptr;
	}

	// Check for Username, Password in Teacher Vector
	Teacher* handleLoginTeacher(string username, string password) {


		for (auto& i : teachers) {
			if (i->getUsername() == username) {
				if (i->getPassword() == password) {
					return i;
				}
			}
		}
		return nullptr;
	}

public:

	Interface() {
		this->current_user = nullptr;
	}

	// Public Functions

	void firstStart() {

		string in, n, u, p;
		cls();
		cout << "Enter 1 to create account for Academic Officer\n Enter 2 to create account for Teacher\nPress 0 at anytime to exit\n";
		cin >> in;

		// Validation Check
		if (in != "1" || in != "2" || in != "0") {
			cout << "\n Invalid Option Selected \n";
			Sleep(300);
			firstStart();
		}

		// Sign up
		if (in == "1" || in == "2") {

			cout << "Name: ";
			cin >> n;
			cout << "Username: ";
			cin >> u;
			cout << "Password: ";
			cin >> p;
			if (in == "1") { // For AO
				officers.push_back(new AcademicOfficer(u, n, p));
				cout << "Done !\n";
			}
			else { // For Teacher
				teachers.push_back(new Teacher(u, n, p));
				cout << "Done !\n";
			}
		}

		// Exit the function
		if (in == "0") { return; }

		firstStart();


	}

	bool handleLogin(string username, string password) {
		if (handleLoginAO(username, password) != nullptr) {
			this->current_user = handleLoginAO(username, password);
			return true;
		}
		else if (handleLoginTeacher(username, password) != nullptr) {
			this->current_user = handleLoginTeacher(username, password);
			return true;
		}
		else {
			this->current_user = nullptr;
			return false;
		}

	}



};
