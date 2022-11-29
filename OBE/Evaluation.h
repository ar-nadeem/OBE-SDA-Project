#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include "questions.h"
using namespace std;

class Evaluation {
private:
	string type;
	float marks;
	float weightage;
	string date;
	vector<Question*> questions ;
	int id;

public:

	Evaluation(string type, float marks, float weightage, string date,int id) {
		this->type = type;
		this->marks = marks;
		this->weightage = weightage;
		this->date = date;
		this->id;
		
	}

	// Getter for id
	int getID() { return this->id; }

	void display() {
		cout << this->type << " " << this->marks << " " << this->weightage << "% " << this->date << endl;
		cout << "Questions\n";
		for (auto& i : questions) {
			i->display();
		}
	}

	// Add Questions
	void addQuestions(Question* obj) {
		questions.push_back(obj);
	}

	// Check for a specific CLO tested or not in specific Questions
	bool checkCLOTestbyQID(int questionID, int cloID) {
		bool ret = false;
		for (auto& obj : questions) {
			if (obj->getID() == questionID) {
				ret = obj->checkCLO(cloID); // Will be true if CLO is tested
			}
			

		}
		return ret;
	}
	void displayAllCLO() {
		for (auto& i : questions) {
			i->printAllCLO();
		}
	}




	// Check for a specific CLO tested or not in All Questions
	bool checkCLOTestbyCLOID(int cloID) {
		bool ret = false;
		for (auto& obj : questions) {
			ret = obj->checkCLO(cloID); // Will be true if CLO is tested
			if (ret == true) {
				return ret;
			}
		}
		return ret;
	}

};


/*string Evaluation::getType() const {
	return this->type;
}

void Evaluation::setType(string type) {
	this->type = type;
}

float Evaluation::getMarks() const {
	return this->marks;
}

void Evaluation::setMarks(float marks) {
	this->marks = marks;
}

float Evaluation::getWeightage() const {
	return this->weightage;
}

void Evaluation::setWeightage(float weightage) {
	this->weightage = weightage;
}

//void Evaluation::setDate() {
//	const time_t now = time(0);
//	this->date = ctime_s(&now);
//}

void Evaluation::addQuestions(string question) {
	this->questions.push_back(question);
}

void Evaluation::removequestion(string question) {
	this->questions.erase(remove(questions.begin(), questions.end(), question), questions.end());
		//.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}
*/