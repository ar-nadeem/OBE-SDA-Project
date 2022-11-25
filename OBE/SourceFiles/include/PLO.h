#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Program.h"

using namespace std;

class PLO {
private:
	string name;
	int code;
	// Program Pointer It is a two way assoication
	Program* program;
public:
	PLO(string n, int c) {
		this->name = n;
		this->code = c;
	}
	void getAllCourses() {
		program->listAllCourses();
	}
	// Set program
	void setProgram(Program* obj) {
		this->program = obj;
	}
	//void getCLO();
	//void setCourse();
};
