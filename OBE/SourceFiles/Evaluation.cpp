#include "include\Evaluation.h"

//Evaluation::Evaluation(string Type, float Marks, float Weight, char* Date) : type(Type), marks(Marks),
//weightage(Weight), date(Date){}


string Evaluation::getType() const {
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
