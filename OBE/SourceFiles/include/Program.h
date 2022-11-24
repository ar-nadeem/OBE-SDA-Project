#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Courses.h"
#include "PLO.h"

using namespace std;

class Program {
private:
	string name;
	string dept;
	vector<PLO> PLO; //Change to PLO type later
	vector<Course> Courses; //Change to PLO type later
public:
	void addCourses();
	void addPLO();
	void setDuration();
	void setDetails();
	void getDetails();
};