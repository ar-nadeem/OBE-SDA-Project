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
	friend class DataHandle<AcademicOfficer>;
	DataHandle<AcademicOfficer> *d;

	//// Setter for Name
	//string setName(string n) { this->setPassword(n); }

	//// Setter for username
	//string setUsername(string u) { this->setUsername(u); }

	//// Setter for password
	//string setPassword(string p) { this->setPassword(p); }
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
	void saveToFile(AcademicOfficer * obj) {
		d->saveData(obj->getName()+
			"," + obj->getUsername()+
			"," + obj->getPassword()+
			"\n");
	}

	//// Reconstruct
	void reConstruct(AcademicOfficer* obj) {
		string* tokens;
		tokens = d->reConstruct();
		
		obj->setName(tokens[0]);
		obj->setUsername(tokens[1]);
		obj->setPassword(tokens[2]);


	}

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
	friend class DataHandle<AcademicOfficer>;
	DataHandle<AcademicOfficer>* d;
public:

	// Default Constructor
	Teacher():User() {
		d = new DataHandle<AcademicOfficer>("Teacher");
	}


	// Paramterized Constructor
	Teacher(string n, string u, string p) :User(n, u, p) {
		d = new DataHandle<AcademicOfficer>("Teacher");
	}

	//// Save to File
	void saveToFile(Teacher* obj) {
		d->saveData(obj->getName() +
			"," + obj->getUsername() +
			"," + obj->getPassword() +
			"\n");
	}

	//// Reconstruct
	void reConstruct(Teacher* obj) {
		string* tokens;
		tokens = d->reConstruct();

		obj->setName(tokens[0]);
		obj->setUsername(tokens[1]);
		obj->setPassword(tokens[2]);


	}

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