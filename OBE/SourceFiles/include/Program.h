#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class Program {
private:
	string name;
	string dept;
	vector<string> PLO; //Change to PLO type later
	vector<string> Courses; //Change to PLO type later
public:
	void addCourses();
	void addPLO();
	void setDuration();
	void setDetails();
	void getDetails();
};