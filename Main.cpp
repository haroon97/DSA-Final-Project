#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

int main() {
	Student s1;
	s1.readFromFile();
	string id;

	cin >> id;
	if (!s1.isStudentPresent(id)) {
		s1.addStudent(id, "Haza", "ahmed", "123344");
	}
	else {
		cout << "Already present" << endl;
	}
	cin >> id;
	if (!s1.isStudentPresent(id)) {
		s1.addStudent(id, "hasan", "ashfaq", "56789");
	}
	else {
		cout << "Already Present" << endl;
	}
	cin >> id;
	if (!s1.isStudentPresent(id)) {
		s1.addStudent(id, "ahmed", "hasan", "6764");
	}
	else {
		cout << "Already present" << endl;
	}

	s1.deleteStudentData("1");

	
}
