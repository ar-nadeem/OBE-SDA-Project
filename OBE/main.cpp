// This is test file for testing classes create by AbdulRahman Nadeem
#include <iostream>
#include "users.h"

using namespace std;


int main() {
	AcademicOfficer AOdata;
	Teacher Tdata;

	Teacher t1("Shahrukh Khan", "SRK", "786");
	Tdata.saveToFile(&t1);


	AcademicOfficer a1("AbdulRahman Nadeem", "arnadeem", "123");
	AcademicOfficer a2("Babik Ayaz", "babik", "334");
	AOdata.saveToFile(&a1);
	AOdata.saveToFile(&a2);



	AcademicOfficer a3;
	AcademicOfficer a4;
	AOdata.reConstruct(&a3);
	AOdata.reConstruct(&a4);
	a3.getInfo();
	a4.getInfo();

	Teacher t2;
	Tdata.reConstruct(&t2);
	t2.getInfo();


}