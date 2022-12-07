#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Courses.h"

//class Program;

using namespace std;

class PLO {
private:
	string name;
	int code;
	string desc;
	vector<Course*> Courses;
public:

	PLO(string n, int c) {
		this->name = n;
		this->code = c;
		this->desc = "NO DESCRPTION SET";
	}
	PLO(string n, int c,string d) {
		this->name = n;
		this->code = c;
		this->desc = d;
	}
	// Getter for ID
	int getID() { return this->code; }

	// Display
	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Code: " << this->code << endl;
		cout << "Descrition: " << this->desc << endl;
	}

	string saveToFile() {
		return(this->name +"," +
		to_string(this->code) + "," +
		this->desc + "\n");
	}

	// Add course to the list of courses.
	void addCourses(Course* obj) {
		Courses.push_back(obj);
	}

	// Itereate through vector of courses and display all info for each | Will be called by PLO | Can be a private Function (TBD).
	void listAllCourses() {
		for (auto& obj : Courses) {
			obj->display();
			cout << endl;
		}
	}
};
