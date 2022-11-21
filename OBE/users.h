#pragma once
#include <iostream>
#include <fstream>
#include "data.h"
using namespace std;


// Superclass User
class User {
private:
	string name;
	string username;
	string password;
	
public:


	// Default constructor
	User() {
		name = "";
		username = "";
		password = "";
	}


	// Paramterized Constructor
	User(string n, string u, string p) {
		name = n;
		username = u;
		password = p;
	}

	// Get Datastream to save into file
	string getData() {
		return(getName() + "," + getUsername() + "," + getPassword() + "\n");
	}


	// Getter & Setter for Name
	string getName() { return this->name; }
	void setName(string n) { this->name = n; }

	// Getter & Setter for username
	string getUsername() { return this->username; }
	void setUsername(string u) { this->username = u; }

	// Getter & Setter for password
	string getPassword() { return this->password; }
	void setPassword(string p) { this->password = p; }



	~User() {
	}

};

// Academic Officer subclass Inhertis from User
class AcademicOfficer :private User {
private:
	DataHandle<AcademicOfficer> *d;
public:

	// Default Constructor
	AcademicOfficer():User() {
		d = new DataHandle<AcademicOfficer>("AcademicOfficer");
	}


	// Paramterized Constructor
	AcademicOfficer(string n, string u,string p):User(n,u,p){
		d = new DataHandle<AcademicOfficer>("AcademicOfficer");
	
	}

	// Getter for type of user
	string getType() { return("AO"); }

	//// Save to File
	//void saveToFile() {
	//	d->saveData(this->getName()+
	//		"," + this->getUsername()+ 
	//		"," + this->getPassword()+
	//		"\n");
	//}

	//// Reconstruct
	//void reConstruct() {
	//	d->reConstruct(this);

	//}

	// Display All info
	void getInfo() {
		cout << "Name: " << this->getName() << "\n";
		cout << "Username: " << this->getUsername() << "\n";
		cout << "Password: " << this->getPassword() << "\n";
		cout << "Type: Academic Officer\n";
	}


	~AcademicOfficer() {};
};

// Teacher subclass Inhertis from User
class Teacher :private User {
private:
public:

	// Default Constructor
	//Teacher():User() {

	//}


	// Paramterized Constructor
	Teacher(string n, string u, string p) :User(n, u, p) {}

	// SaveToFile


	// Getter for type of user
	string getType() { return("T"); }


	// Display All info
	void getInfo() {
		cout << "Name: " << this->getName() << "\n";
		cout << "Username: " << this->getUsername() << "\n";
		cout << "Password: " << this->getPassword() << "\n";
		cout << "Type: Teacher\n";
	}


	~Teacher() {};
};