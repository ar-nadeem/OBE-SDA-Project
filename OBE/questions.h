#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include "CLO.h"

using namespace std;

class Question {
private:
	string name;
	vector<CLO*> clo;
	int id;

public:

	// Default Constructor
	Question(int id, string name) {
		this->name = name;
		this->id = id;
	}
	
	void display() {
		cout << "Question " << this->id << ":" << this->name << endl;
		
		if (clo.size() > 0) {
			cout << "\nCLO for this Question\n";
			this->DisplayAllCLO();
		}
		else {
			cout << "NO CLO FOR THIS QUESTION !\n";
		}
		cout << endl;
	}

	// Add CLO that are tested
	void addCLO(CLO* obj) {
		clo.push_back(obj);
	}

	// Test for CLO Tested
	bool checkCLO(int id) {
		for (auto& obj : clo) {
			if (obj->getID() == id) { return true; }
		}
		return false;
	}

	void DisplayAllCLO() {
		for (auto& obj : clo) {
			obj->display();
		}
	}

	// Get all CLOs | returns the vector of clo
	vector<CLO*> getAllCLO() { return clo; }
	void printAllCLO() {
		for (auto& obj : clo) {
			obj->display();
		}
	}
		
	// Getter for ID
	int getID() { return this->id; }
};