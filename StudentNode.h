#pragma once
#include <iostream>
#include <string>
using namespace std;
class StudentNode
{
public:
	string studentId;
	string firstName;
	string lastName;
	string phoneNo;
	StudentNode *next;

	StudentNode(string stdId, string fName, string lName, string pNo) {
		this->studentId = stdId;
		this->firstName = fName;
		this->lastName = lName;
		this->phoneNo = pNo;
		next = NULL;
	}
};

