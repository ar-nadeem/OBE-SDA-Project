#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class Evaluation {
private:
	string type;
	float marks;
	float weightage;
	char* date;
	vector<string> questions[];

public:

	Evaluation(string type, float marks, float weightage, char* date, string question) {
		this->type = type;
		this->marks = marks;
		this->weightage = weightage;
		this->date = date;
		this->questions->push_back(question);
	}

	string getType() const;
	void setType(string type);

	float getMarks() const;
	void setMarks(float marks);

	float getWeightage() const;
	void setWeightage(float weightage);

	void setDate();

	void addQuestions(string question);
	void removequestion(string question);


};