#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class CLO {
private:
	string name;
	int code;
	string desc;
	vector<string> topic_covered;
public:
	// Paremterised Constructor
	CLO(string n, int c, string d) {
		this->name = n;
		this->code = c;
		this->desc = d;
	}
	CLO(string n, int c) {
		this->name = n;
		this->code = c;
		this->desc = "NO DESCRPTION SET";
	}


	// Display
	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Code: " << this->code << endl;
		cout << "Descrition: " << this->desc << endl;

		
		if (topic_covered.size() > 0) {
			cout << "Topic Covered: ";
			for (auto& element : topic_covered) {
				cout << element << ", ";
			}
		}

		cout << endl;
	}

	string saveToFile() {
		return(this->name +","+
		to_string(this->code) + ","+
		this->desc +"\n");
	}

	void addTopicCovered(string s) {
		topic_covered.push_back(s);
	}

	// Getter for ID
	int getID() { return this->code; }


	//void addEvaluation();
	//void removeEvaluation();
	//void addTopic();

};
