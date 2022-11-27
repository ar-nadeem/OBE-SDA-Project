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
	vector<Program*> programs;
	vector <PLO*> plos;
	vector <Course*> courses;
	vector <CLO*> clos;
	vector <Evaluation*> evaluations;
	vector <Question*> questions;

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

		string n, u, p;
		int in;
		cls();
		cout << "Enter 1 to create account for Academic Officer\nEnter 2 to create account for Teacher\nPress 0 at anytime to exit\n";
		cin >> in;

		// Validation Check
		if (in != 1 || in != 2 || in != 0) {
			cout << "\n Invalid Option Selected \n";
			Sleep(300);
			firstStart();
		}

		// Sign up
		if (in == 1 || in == 2) {

			cout << "Name: ";
			cin >> n;
			cout << "Username: ";
			cin >> u;
			cout << "Password: ";
			cin >> p;
			if (in == 1) { // For AO
				users.push_back(new AcademicOfficer(u, n, p));
				cout << "Done !\n";
			}
			else { // For Teacher
				users.push_back(new Teacher(u, n, p));
				cout << "Done !\n";
			}
		}

		// Exit the function
		if (in == 0) { return; }

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

	// AO
	void createProgram(string n,string d, int id) {
		this->programs.push_back(this->current_user->createProgram(n,d,id));
	}
	void createPLO(string n, int c, string d) {
		this->plos.push_back(this->current_user->createPLO(n, c,d));
	}
	void createCourse(string n, int c, string d) {
		this->courses.push_back(this->current_user->createCourse(n, c, d));
	}
	void addTopicCovered(string s) {
		this->clos.back()->addTopicCovered(s);
	}

	bool addCourseToPLO() {
		if (this->plos.size() == 0) {
			return false;
		}
		this->plos.back()->addCourses(this->courses.back());
		return true;
	}	
	bool addCourseToPLObyID(int id) {
		for (auto& i : plos) {
			if (i->getID() == id) {
				i->addCourses(this->courses.back());
				return true;
			}
			return false;
		}
		
	}
	bool addPLOtoProgram() {
		if (this->programs.size() == 0) {
			return false;
		}
		this->programs.back()->addPLO(this->plos.back());
		return true;
	}
	bool addPLOtoProgrambyID(int id) {
		for (auto& i : programs) {
			if (i->getID() == id) {
				i->addPLO(this->plos.back());;
				return true;
			}
			return false;
		}
		
	}

	void getAllPrograms() {
		for (auto& i : programs) {
			
				i->display();
			
		}
	}

	void printPLOinProgram(int id) {
		for (auto& i : programs) {
			if (i->getID() == id) {
				i->listAllPLO();
			}
		}
	}

	void printCoursesinProgram(int id) {
		for (auto& i : programs) {
			if (i->getID() == id) {
				i->getAllCourses();
			}
		}
	}

	void printCoursesinPLO(int Programid,int pid) {
		for (auto& i : programs) {
			if (i->getID() == Programid) {
				i->getCoursesbyPLO(pid);
			}
		}
	}


	// Teacher
	void createCLO(string n, int c, string d) { 
		this->clos.push_back(this->current_user->createCLO(n, c, d)); 
	}

	void createEvaluation(string type, float marks, float weightage, string date, int id) {
		this->evaluations.push_back(this->current_user->createEvaluation(type, marks, weightage,date,id));
	}

	void createQuestion(int id, string name) {
		this->questions.push_back(this->current_user->createQuestion(id, name));
	}

	bool addQuestionsToEvaluation() {
		if (this->evaluations.size() == 0) {
			return false;
		}
		this->evaluations.back()->addQuestions(this->questions.back());
		return true;
	}
	

	bool addQuestionsToEvaluation(int id) {
		for (auto& i : evaluations) {
			if (i->getID() == id) {
				i->addQuestions(this->questions.back());;
				return true;
			}
			return false;
		}

	}

	bool addCLOToQuestion(int id) {
		for (auto& i : questions) {
			if (i->getID() == id) {
				i->addCLO(this->clos.back());;
				return true;
			}
			return false;
		}

	}


	bool addCLOToQuestion() {
		if (this->evaluations.size() == 0) {
			return false;
		}
		this->questions.back()->addCLO(this->clos.back());
		return true;
	}


	bool addCLOToCourse(string id) {
		for (auto& i : courses) {
			if (i->getID() == id) {
				i->addCLO(this->clos.back());;
				return true;
			}
			return false;
		}

	}
	bool addCLOToCourse() {
		if (this->courses.size() == 0) {
			return false;
		}
		this->courses.back()->addCLO(this->clos.back());
		return true;
	}


	void getEvaluation() {
		for (auto& i : evaluations) {
			i->display();
		}
	}

	void getEvaluation(int id) {
		for (auto& i : evaluations) {
			if (i->getID() == id)
			i->display();
		}
	}

	bool checkCLOTestbyQID(int e_id, int q_id, int clo_id) {
		for (auto& i : evaluations) {
			if (i->getID() == e_id) {
				return (i->checkCLOTestbyQID(q_id,clo_id));
			}
		}
		return false;
	}

	bool checkCLOTestbyCLOID(int e_id,int clo_ID) {
		for (auto& i : evaluations) {
			if (i->getID() == e_id) {
				return (i->checkCLOTestbyCLOID(clo_ID));
			}
		}
		return false;
	}


	~Interface() {
		users.clear();
		programs.clear();
		plos.clear();
		courses.clear();
		clos.clear();
		evaluations.clear();
		questions.clear();
	}
};
