// This is test file for testing classes create by AbdulRahman Nadeem
#include <iostream>
#include "users.h"
#include "SourceFiles/include/PUBLIC_HEADERS.h"
using namespace std;


int main() {
	AcademicOfficer a1("AbdulRahman Nadeem", "arnadeem", "123");

	Program program ("Computer Science", "Sciences");
	Course c1("CS101", 101, "Programming Fundamental");
	Course c2("CS202", 202, "Object Oreinted Programing");

	PLO plo("CS", 1);
	
	program.setPLO(&plo);
	plo.setProgram(&program);
	plo.getAllCourses();
	


}