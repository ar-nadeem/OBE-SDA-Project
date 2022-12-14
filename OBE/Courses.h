#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "CLO.h"

using namespace std;

class Course {
private:
	string course_code;
	int credit_hours;
	//int semester;
	//string parent_course;
	string course_name;
	//int class_number;

	// Vector of pointers to CLO
	vector<CLO*> clo;

public:
	// Constructor
	Course(string CourseName, int CreditHour, string CourseCode) {
		this->course_code = CourseCode;
		this->credit_hours = CreditHour;
		this->course_name = CourseName;
	}


	// Display Information For Course
	void display() {
		cout << "Course Name: " << this->course_name << endl;
		cout << "Course Code: " << this->course_code << endl;
		cout << "Credit Hours: " << this->credit_hours << endl;
		

	}

	string saveToFile() {
		return(this->course_name + ","+
		this->course_code + ","+
		to_string(this->credit_hours) +"\n");


	}

	string getID() { return this->course_code; }


	// Add CLO to the list of CLOs.
	void addCLO(CLO* obj) {
		clo.push_back(obj);
	}

	// Itereate through vector of CLO and display all info for each | Will be called by Courses
	void listAllCLO() {
		for (auto& obj : clo) {
			obj->display();
			cout << endl;
		}
	}

	vector<CLO*> getAllCLO() { return clo; }

	// Getter for CLO from ID
	CLO* getCLObyID(int id) {
		for (auto& obj : clo) {
			if (obj->getID() == id) {
				return obj;
			}
		}
	}




	//template<typename temp>//helper function
	//temp* increase(temp* ptr, int Size) {
	//	temp* _newptr = new temp[Size + 1];
	//	for (int i = 0; i < Size; i++) {
	//		_newptr[i] = ptr[i];
	//	}
	//	delete[] ptr;
	//	return _newptr;
	//}

	//int check_course_code(string codeList[], string edit_course_code)
	//{
	//	bool value = 0;
	//	for (int x = 0; x < 100; x++)
	//	{
	//		if (codeList[x] == edit_course_code)
	//		{
	//			value = 1;
	//			break;
	//		}
	//	}
	//	return value;
	//}

	//bool isValidCreditHours(int credit_hours)
	//{
	//	bool var1 = false;
	//	if (credit_hours > 0 && credit_hours <= 3)
	//	{
	//		var1 = true;
	//	}
	//	return var1;
	//}

	//// this function checks whether semester is between 1 and 8 or not
	//bool isValidSemester(int semester)
	//{
	//	bool var = false;
	//	if (semester > 0 && semester <= 8)
	//	{
	//		var = true;
	//	}
	//	return var;
	//}

	//bool isValidCourseName(char course_name[])
	//{
	//	bool value = true;
	//	int x = 0;
	//	while (course_name[x] != '\0')
	//	{
	//		for (char y = '0'; y <= '9'; y++)
	//		{
	//			if (course_name[x] == y)
	//			{
	//				value = false;
	//			}
	//		}
	//		x++;
	//	}
	//	return value;
	//}

	//Course() {}
	////Setter's Getter's
	//void SetParentCourse(string parent_course) {
	//	this->parent_course = parent_course;
	//}
	//string GetParentCourse()const {
	//	return parent_course;
	//}
	//void SetCourseCode(string course_code) {
	//	this->course_code = course_code;
	//}
	//string GetCourseCode()const {
	//	return course_code;
	//}
	//void SetCourseName(string course_name) {
	//	this->course_name = course_name;
	//}
	//string GetCourseName()const {
	//	return course_name;
	//}
	//void SetClassNumber(int class_number) {
	//	this->class_number = class_number;
	//}
	//int GetClassNumber()const {
	//	return class_number;
	//}

	//Course* readCourse_forAssigning(Course* ptr, int& Size)
	//{
	//	std::fstream file;
	//	file.open("Course.txt", std::ios::in);

	//	Course obj;
	//	if (file.is_open()) {

	//		while (!file.eof()) {

	//			file >> obj.class_number;
	//			std::getline(file, obj.course_code, ',');
	//			std::getline(file, obj.parent_course, ',');
	//			std::getline(file, obj.course_name);
	//			ptr = increase(ptr, Size);
	//			ptr[Size] = obj;
	//			++Size;
	//			if (file.eof()) {
	//				break;
	//			}

	//		}
	//		return ptr;
	//	}
	//	else {
	//		std::cout << "Unable to Open file" << std::endl;
	//		return ptr;
	//	}
	//}

};
