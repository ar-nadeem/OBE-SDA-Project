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
	string type;
	
public:


	// Default constructor
	User() {
		name = "";
		username = "";
		password = "";
		type = "";
	}


	// Paramterized Constructor
	User(string n, string u, string p,string type) {
		name = n;
		username = u;
		password = p;
		this->type = type;
	}

	// Get Datastream to save into file
	string getData() {
		return(getName() + "," + getUsername() + "," + getPassword() + "\n");
	}



	// Virtual Functions
	// For AO
	virtual Program* createProgram(string n,string d, int id) { return nullptr; }
	virtual PLO* createPLO(string n, int c, string d) { return nullptr; }
	virtual Course* createCourse(string cc, int cr, string cn) { return nullptr; }
	// For Teacher
	virtual CLO* createCLO(string n, int c, string d) { return nullptr; }
	virtual Evaluation* createEvaluation(string type, float marks, float weightage, string date,int id) { return nullptr; }
	virtual Question* createQuestion(int id, string name) { return nullptr; }

	virtual void getInfo() {
		return;
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

	string getType() { return(this->type); }

	~User() {
	}

};

// Academic Officer subclass Inhertis from User
class AcademicOfficer :public User {
private:
	friend class DataHandle<AcademicOfficer>;
	DataHandle<AcademicOfficer> *d;


public:

	// Default Constructor
	AcademicOfficer():User() {
		d = new DataHandle<AcademicOfficer>("AcademicOfficer");
	}


	// Paramterized Constructor
	AcademicOfficer(string n, string u,string p):User(n,u,p,"AO") {
		d = new DataHandle<AcademicOfficer>("AcademicOfficer");
	
	}



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

	// ASOCIATION FUNCTIONS 
	// Create a Program
	Program* createProgram(string n, string d, int id) {
		Program* temp = new Program(n,d,id);
		return (temp);
	}
	// Create a PLO
	PLO* createPLO(string n, int c, string d) {
		PLO* temp = new PLO(n, c, d);
		return temp;
	}
	Course* createCourse(string cc, int cr, string cn) {
		Course* temp = new Course(cc, cr, cn);
		return temp;
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
class Teacher :public User {
private:
	friend class DataHandle<AcademicOfficer>;
	DataHandle<AcademicOfficer>* d;


public:

	// Default Constructor
	Teacher():User() {
		d = new DataHandle<AcademicOfficer>("Teacher");
	}


	// Paramterized Constructor
	Teacher(string n, string u, string p) :User(n, u, p,"T") {
		d = new DataHandle<AcademicOfficer>("Teacher");
	}



	// ASOCIATIONS FUNCTIONS
	CLO* createCLO(string n, int c, string d) { 
		CLO* temp = new CLO(n, c, d);
		return temp;
	}
	Evaluation* createEvaluation(string type, float marks, float weightage, string date,int id) {
		Evaluation* temp = new Evaluation(type, marks, weightage, date,id);
		return temp;
	}
	Question* createQuestion(int id, string name) { 
		Question* temp = new Question(id, name);
		return temp;
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


	// Display All info
	void getInfo() {
		cout << "Name: " << this->getName() << "\n";
		cout << "Username: " << this->getUsername() << "\n";
		cout << "Password: " << this->getPassword() << "\n";
		cout << "Type: Teacher\n";
	}


	~Teacher() {};
};