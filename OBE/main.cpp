// This is test file for testing classes create by AbdulRahman Nadeem
#include <iostream>
#include "users.h"

using namespace std;


int main() {
	AcademicOfficer a1("AbdulRahman Nadeem", "arnadeem", "123");
	a1.saveToFile();

	AcademicOfficer* a2 = new AcademicOfficer;

	a2->reConstruct();

	a2->getInfo();



}