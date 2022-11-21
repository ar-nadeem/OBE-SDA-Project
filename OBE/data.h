#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

// This class handles saving/deleting objects and reconstructing them on program start

template <class T>
class DataHandle {
private:
	fstream f;
	string file;
public:

	// Set location of file to store data to, should be the class name
	DataHandle(string fileName) {
		// We will store it in data folder with extension txt
		file ="./data/"+ fileName + ".txt";
	}

	// Write object to file.
	void saveData(string s) {
		f.open(file, ios::app);
		if (!f) {
			cout << "FAILED TO CREATE/ACCESS FILE in function Savedata of data.h\n";
			return;
		}


		
		f.close();

	}

	// Rescontructs all objects in from array of pointers
	void reConstruct(T *obj) {
		T test;


		f.open(file, ios::in);
		if (!f) {
			cout << "FAILED TO READ/ACCESS FILE in function reConstruct of data.h\n";
		}
		else {
			f.seekg(0);
			f.read((char*)&test, sizeof(test));
		}

		

		obj->setName(test.getName());
		obj->setUsername(test.getUsername());
		obj->setPassword(test.getPassword());


		f.close();


		//return test;
	}
};