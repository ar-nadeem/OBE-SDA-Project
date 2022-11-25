#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "PLO.h"
#include "Courses.h"

using namespace std;

class Program {
private:
	string name;
	string dept;
	// Vectors to pointers of object. Association
	PLO* plo; //Change to PLO type later

	vector<Course*> Courses; //Change to PLO type later
public:
	// Default Constructor
	Program(string n,string d) {
		this->name = n;
		this->dept = d;
	}
	// Add course to the list of courses.
	void addCourses(Course *obj) {
		Courses.push_back(obj);
	}
	// Add PLO to the list of PLOs
	void setPLO(PLO* obj) {
		plo = obj;
	}

	// Itereate through vector of courses and display all info for each | Will be called by PLO | Can be a private Function (TBD).
	void listAllCourses() {
		for (auto & obj : Courses) {
			obj->display();
			cout << endl;
		}
	}

	//void setDuration();
	//void setDetails();
	//void getDetails();
};