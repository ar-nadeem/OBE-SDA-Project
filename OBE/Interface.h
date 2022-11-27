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
	vector<User*> users;

	User* current_user;



	// Clear Screen
	void cls() {
		system("CLS");
	}





	// Check for Username, Password in Users Vector
	User* handleLoginUser(string username, string password) {
		for (auto& i : users) {
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
				users.push_back(new AcademicOfficer(u, n, p));
				cout << "Done !\n";
			}
			else { // For Teacher
				users.push_back(new Teacher(u, n, p));
				cout << "Done !\n";
			}
		}

		// Exit the function
		if (in == "0") { return; }

		firstStart();


	}

	bool handleLogin(string username, string password) {
	
		this->current_user = handleLoginUser(username, password);
		if (this->current_user = nullptr) { return false; }
		else { return true; }

	}

	string getTypeofUser() {
		return(this->current_user->getType());
	}
	User* getUser() {
		return (this->current_user);
	}
};
