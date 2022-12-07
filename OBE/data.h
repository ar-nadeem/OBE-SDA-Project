#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// This class handles saving/deleting objects and reconstructing them on program start

template <class T>
class DataHandle {
private:
	fstream f;
	string file;
	int index;
public:

	// Set location of file to store data to, should be the class name
	DataHandle(string fileName) {
		// We will store it in data folder with extension txt
		file ="./data/"+ fileName + ".txt";
		index = 1;
	}

	// Write object to file.
	void DeleteData() {
		f.open(file, ios::out);
		if (!f) {
			cout << "FAILED TO CREATE/ACCESS FILE in function Savedata of data.h\n";
			return;
		}

		f << "";

		f.close();

	}
	void saveData(string s) {
		f.open(file, ios::app);
		if (!f) {
			cout << "FAILED TO CREATE/ACCESS FILE in function Savedata of data.h\n";
			return;
		}

		f << s;
		
		f.close();

	}

	// Rescontructs all objects in from array of pointers
	string* reConstruct() {
		string line;
		int temp = index;
		int token_index=0;
		string token;
		string* token_arr = new string[10];

		f.open(file, ios::in);
		if (!f) {
			cout << "FAILED TO READ/ACCESS FILE in function reConstruct of data.h\n";
		}
		else {
			for (int i = 0; i < temp; i++) {
				getline(f, line);
				index++;
			}



			if (line == "") {
				cout << "NO MORE OBJECTS REMEANING IN FILE \n";
				return nullptr;
			}
			std::istringstream iss(line);
			while (getline(iss, token, ',')) {
				//cout << token << endl;
				token_arr[token_index++] = token;
			}
		}
		

		f.close();
		return token_arr;

	}
};