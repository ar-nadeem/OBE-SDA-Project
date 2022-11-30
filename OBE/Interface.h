#pragma once
#include "PUBLIC_HEADERS.h"
#include <stdlib.h>
#include <vector>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif





class Interface {
private:
	vector<User*> users;
	vector<Program*> programs;
	vector <PLO*> plos;
	vector <Course*> courses;
	vector <CLO*> clos;
	vector <Evaluation*> evaluations;
	vector <Question*> questions;

	User* current_user;



	// Clear Screen
	void cls() {
		system("CLS");
	}





	// Check for Username, Password in Users Vector
	User* handleLoginUser(string username, string password) {
		for (auto& i : users) {
			if ((i->getUsername() == username) && (i->getPassword() == password)) {
				return i;
			}
		}
		return nullptr;
	}


public:

	bool isEmptyCourses() {
		if (courses.size() == 0) {
			return true;
		}
		return false;
	}

	//bool isEmptyCourses() {
	//	if (courses.size() == 0) {
	//		return true;
	//	}
	//}

	//bool isEmptyCourses() {
	//	if (courses.size() == 0) {
	//		return true;
	//	}
	//}

	//bool isEmptyCourses() {
	//	if (courses.size() == 0) {
	//		return true;
	//	}
	//}

	//bool isEmptyCourses() {
	//	if (courses.size() == 0) {
	//		return true;
	//	}
	//}





	Interface() {
		this->current_user = nullptr;
	}

	// Public Functions
	void debug_start() {
		users.push_back(new AcademicOfficer("AbdulRahman Nadeem", "arnadeem", "123"));
		users.push_back(new Teacher("Usman Nadeem", "unadeem", "123"));

		programs.push_back(new Program("Computer Sciences", "Sciences", 1));
		programs.push_back(new Program("Maths", "Sciences", 2));
		plos.push_back(new PLO("Become Software Developer",1, "Able to Create Softwares"));
		this->addPLOtoProgrambyID(1);
		plos.push_back(new PLO("Become Math Proffessor", 2, "Teach at UNI"));
		this->addPLOtoProgrambyID(2);

		courses.push_back(new Course("Fundamental Programming", 3, "CS101"));
		this->addCourseToPLObyID(1);
		courses.push_back(new Course("Calculus I", 3, "M101"));
		this->addCourseToPLObyID(2);


		clos.push_back(new CLO("Introduction to Pointers",1 ,"Pointers"));
		this->addCLOToCourse("CS101");
		clos.push_back(new CLO("Introduction to Input", 5, "CIN"));
		this->addCLOToCourse("CS101");
		clos.push_back(new CLO("Introduction to Output", 6, "COUT"));
		this->addCLOToCourse("CS101");
		//this->addTopicCovered("Pointers");
		//this->addTopicCovered("CIN");
		//this->addTopicCovered("Cout");

		clos.push_back(new CLO("Graphs", 2, "How to draw Graphs"));
		this->addCLOToCourse("M101");
		clos.push_back(new CLO("Limit", 3, "How to calculate Limits"));
		this->addCLOToCourse("M101");

		//this->addTopicCovered("Graphs");
		//this->addTopicCovered("Limits");
		//this->addTopicCovered("Taylor Series");

		evaluations.push_back(new Evaluation("Quiz",10,10,"10-Dec-2022",1));
		questions.push_back(new Question(1,"What is Pointer ?"));
		this->addQuestionsToEvaluation(1);
		this->addCLOToQuestion(1);

		questions.push_back(new Question(2, "What is Cin ?"));
		this->addQuestionsToEvaluation(1);
		this->addCLOToQuestion(5);
		

		questions.push_back(new Question(3, "What is Cout ?"));
		this->addCLOToQuestion(6);
		this->addQuestionsToEvaluation(1);
		
		evaluations.push_back(new Evaluation("Quiz", 10, 10, "10-Nov-2023", 2));
		questions.push_back(new Question(1, "What is Limit ?"));
		this->addCLOToQuestion(2);
		this->addQuestionsToEvaluation(2);
		


	}


	void firstStart() {

		string n, u, p;
		int in;
		cls();
		cout << "Enter 1 to create account for Academic Officer\nEnter 2 to create account for Teacher\nPress 0 at anytime to exit\n";
		cin >> in;


		// Sign up
		// Validation Check
		if ((in == 1 || in == 2)) {
			cout << "Name: ";
			cin.ignore();
			getline(cin, n);
			cout << "Username: ";
			cin >> u;
			cout << "Password: ";
			cin >> p;
			if (in == 1) { // For AO
				users.push_back(new AcademicOfficer(n, u, p));
				cout << "Done !\n";
				
				cout << "\n-----------INFO---------------\n";
				users.back()->getInfo();
				cout << "-----------INFO---------------\n";

				

				system("Pause");
			}
			else { // For Teacher
				users.push_back(new Teacher(n, u, p));
				cout << "Done !\n";
				cout << "\n-----------INFO---------------\n";
				users.back()->getInfo();
				cout << "-----------INFO---------------\n";
				system("Pause");
			}
		}

		// Exit when pressed 0
		else if (in == 0) { cls(); return; }

		else {
			cout << "\n Invalid Option Selected \n";
			Sleep(300);
			firstStart();
		}

		// Exit the function
		

		firstStart();


	}

	bool handleLogin(string username, string password) {
	
		this->current_user = handleLoginUser(username, password);
		if (this->current_user == nullptr) { return false; }
		else { return true; }

	}

	void display_current_user() {
		cout << "\n-------------WELCOME------------\n";
		this->current_user->getInfo();
		cout << "---------------------------------\n";
	}

	string getTypeofUser() {
		return(this->current_user->getType());
	}
	User* getUser() {
		return (this->current_user);
	}

	// AO
	void createProgram(string n,string d, int id) {
		this->programs.push_back(this->current_user->createProgram(n,d,id));
	}
	void createPLO(string n, int c, string d) {
		this->plos.push_back(this->current_user->createPLO(n, c,d));
	}
	void createCourse(string CourseName, int CreditHour, string CourseCode) {
		this->courses.push_back(this->current_user->createCourse(CourseName, CreditHour, CourseCode));
	}


	bool addCourseToPLO() {
		if (this->plos.size() == 0) {
			return false;
		}
		this->plos.back()->addCourses(this->courses.back());
		return true;
	}	
	bool addCourseToPLObyID(int id) {
		for (auto& i : plos) {
			if (i->getID() == id) {
				i->addCourses(this->courses.back());
				return true;
			}
		}
		return false;
	}
	bool addPLOtoProgram() {
		if (this->programs.size() == 0) {
			return false;
		}
		this->programs.back()->addPLO(this->plos.back());
		return true;
	}
	bool addPLOtoProgrambyID(int id) {
		for (auto& i : programs) {
			if (i->getID() == id) {
				i->addPLO(this->plos.back());;
				return true;
			}
		}
		return false;
	}

	void getAllPrograms() {
		for (auto& i : programs) {
			
				i->display();
			
		}
	}

	void printPLOinProgram(int id) {
		for (auto& i : programs) {
			if (i->getID() == id) {
				i->listAllPLO();
			}
		}
	}

	void printCoursesinProgram(int id) {
		for (auto& i : programs) {
			if (i->getID() == id) {
				i->getAllCourses();
			}
		}
	}

	void printCoursesinPLO(int Programid,int pid) {
		for (auto& i : programs) {
			if (i->getID() == Programid) {
				i->getCoursesbyPLO(pid);
			}
		}
	}


	// Teacher

	void createCLO(string n, int c, string d) { 
		this->clos.push_back(this->current_user->createCLO(n, c, d)); 
	}

	void addTopicCovered(string s) {
		this->clos.back()->addTopicCovered(s);
	}


	void createEvaluation(string type, float marks, float weightage, string date, int id) {
		this->evaluations.push_back(this->current_user->createEvaluation(type, marks, weightage,date,id));
	}

	void createQuestion(int id, string name) {
		this->questions.push_back(this->current_user->createQuestion(id, name));
	}

	bool addQuestionsToEvaluation() {
		if (this->evaluations.size() == 0) {
			return false;
		}
		this->evaluations.back()->addQuestions(this->questions.back());
		return true;
	}
	

	bool addQuestionsToEvaluation(int id) {
		for (auto& i : evaluations) {
			if (i->getID() == id) {
				i->addQuestions(this->questions.back());;
				return true;
			}
		}
		return false;
	}

	void printCLObyCourseID(string cid) {
		for (auto& i : courses) {
			if (i->getID() == cid) {
				i->listAllCLO();
			}
		}
	}

	void printCLObyQID(int qid) {
		for (auto& i : questions) {
			if (i->getID() == qid) {
				i->printAllCLO();
			}
		}
	}

	void printCLObyEID(int eid) {
		for (auto& i : evaluations) {
			if (i->getID() == eid) {
				i->displayAllCLO();
			}
		}
	}

	void PrintAllCourses() {
		for (auto& i : courses) {
			i->display();
		}
	}


	bool addCLOToQuestion(int id) {
		for (auto& i : clos) {
			if (i->getID() == id) {
				questions.back()->addCLO(i);
				//i->addCLO(this->clos.back());
				return true;
			}
			
		}
		return false;
	}


	//bool addCLOToQuestion() {
	//	if (this->evaluations.size() == 0) {
	//		return false;
	//	}
	//	this->questions.back()->addCLO(this->clos.back());
	//	return true;
	//}


	bool addCLOToCourse(string id) {
		for (auto& i : courses) {
			if (i->getID() == id) {
				i->addCLO(this->clos.back());;
				return true;
			}
			
		}
		return false;
	}
	bool addCLOToCourse() {
		if (this->courses.size() == 0) {
			return false;
		}
		this->courses.back()->addCLO(this->clos.back());
		return true;
	}


	void getCLObyCourse(string id) {
		for (auto& i : courses) {
			if (i->getID() == id) {
				i->display();
			}
		}
	}

	void getEvaluation() {
		for (auto& i : evaluations) {
			i->display();
		}
	}

	void getEvaluation(int id) {
		for (auto& i : evaluations) {
			if (i->getID() == id)
			i->display();
		}
	}

	bool checkCLOTestbyQID(int e_id, int q_id, int clo_id) {
		for (auto& i : evaluations) {
			if (i->getID() == e_id) {
				return (i->checkCLOTestbyQID(q_id,clo_id));
			}
		}
		return false;
	}


	// Course(vector of CLO) -> Interface -> Evaluation(Check CLO) -> Interface True or False
	bool checkCLOTestbyCourseID(string cid, int e_id) {
		vector<CLO*> temp;
		for (auto& i : courses) {
			if (i->getID() == cid) {
				
				temp = i->getAllCLO();
				for (auto& z : temp) {
					if (this->checkCLOTestbyCLOID(e_id,z->getID()) == false) {
						return false;
					}
				}
			}
		}
		return true;
	}


	bool checkCLOTestbyCLOID(int e_id,int clo_ID) {
		for (auto& i : evaluations) {
			if (i->getID() == e_id) {
				return (i->checkCLOTestbyCLOID(clo_ID));
			}
		}
		return false;
	}


	~Interface() {
		users.clear();
		programs.clear();
		plos.clear();
		courses.clear();
		clos.clear();
		evaluations.clear();
		questions.clear();
	}
};
