#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PLO.h"

using namespace std;

class Program {
private:
	string name;
	string dept;
	// Vectors to pointers of object. Association
	vector<PLO*> plo;

	
public:
	// Default Constructor
	Program(string n,string d) {
		this->name = n;
		this->dept = d;
	}

	// Add PLO to the list of PLOs
	void addPLO(PLO* obj) {
		plo.push_back(obj);
	}

	// List all PLOs
	void listAllPLO() {
		for (auto& obj : plo) {
			obj->display();
			cout << endl;
		}
	}

	// List Courses by PLO id
	void getCoursesbyPLO(int id) {
		for (auto& obj : plo) {
			if (obj->getID() == id) {
				obj->listAllCourses();
				cout << endl;
			}
		}
	}

	void getAllCourses() {
		for (auto& obj : plo) {
			obj->listAllCourses();
			cout << endl;
		}
	}


	//void setDuration();
	//void setDetails();
	//void getDetails();
};