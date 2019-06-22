#pragma once
#include "StudentNode.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
class Student
{
private:
	StudentNode *head;
	StudentNode *tail;
public:
	Student() {
		head = NULL;
		tail = NULL;
	}

private:    // PRIVATE FUNCTIONS OF WHICH USERS DONT HAVE ACCESS
	void addStudentHelper(StudentNode*& head, StudentNode*& tail, string id, string fName, string lName, string pNo) {
		/*StudentNode *newNode = new StudentNode(id, fName, lName, pNo);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		ofstream fout("student.txt", ios::app);
		fout << id << ", " << fName << ", " << lName << ", " << pNo << endl;
		fout.close();*/
	}

	

	void listStudentsHelper(StudentNode* head) {
		/*if (head == NULL) {
			cout << "No record exists" << endl;
			return;
		}
		StudentNode* temp = head;
		while (temp != NULL) {
			cout << temp->studentId << ", " << temp->firstName << ", " << temp->lastName << ", " << temp->phoneNo << endl;
			temp = temp->next;
		}*/
	}

	void addIntoList(StudentNode*& head, StudentNode*& tail, string id, string fName, string lName, string pNo) {
		StudentNode *newNode = new StudentNode(id, fName, lName, pNo);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void modifyStudentDataHelper(StudentNode* head, string id, string fname, string lname, string pNo) {
		/*ofstream fout("temp.txt");
		remove("student.txt");

		//std::ifstream src("student.txt", std::ios::binary);
		//std::ofstream dst("temp.txt", std::ios::binary);
		//dst << src.rdbuf();

		StudentNode* temp = head;
		while (temp != NULL) {
			if (temp->studentId == id) {
				break;
			}
			temp = temp->next;
		}
		temp->firstName = fname;
		temp->lastName = lname;
		temp->phoneNo = pNo;

		temp = head;
		while (temp != NULL) {
			fout << temp->studentId << ", " << temp->firstName << ", " << temp->lastName << ", " << temp->phoneNo << endl;
			temp = temp->next;
		}
		fout.close();
		rename("temp.txt", "student.txt");*/
	}

public:    // PUBLIC FUNCTIONS WHICH USERS HAVE ACCESS
	void addStudent(string id, string fName, string lName, string pNo) {
		//addStudentHelper(head, tail, id, fName, lName, pNo);
		StudentNode *newNode = new StudentNode(id, fName, lName, pNo);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		ofstream fout("student.txt", ios::app);
		fout << id << ", " << fName << ", " << lName << ", " << pNo << endl;
		fout.close();
	}

	void listStudents() {
		// listStudentsHelper(head);
		if (head == NULL) {
			cout << "No record exists" << endl;
			return;
		}
		StudentNode* temp = head;
		while (temp != NULL) {
			cout << temp->studentId << ", " << temp->firstName << ", " << temp->lastName << ", " << temp->phoneNo << endl;
			temp = temp->next;
		}
	}

	void readFromFile() {
		ifstream fin("student.txt");
		if (!fin.is_open()) {
			cout << "File not found" << endl;
			return;
		}
		string id, fname, lname, pno, line;
		while (getline(fin, line)) {
			stringstream ss(line);
			getline(ss, id, ',');
			getline(ss, fname, ',');
			getline(ss, lname, ',');
			getline(ss, pno, ',');
			addIntoList(head, tail, id, fname, lname, pno);
		}
	}

	bool isStudentPresent(string id) {
		if (head == NULL) {
			return false;
		}
		StudentNode *temp = head;
		while (temp != NULL) {
			if (temp->studentId == id) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void modifyStudentData(string id, string fName, string lName, string pNo) {
		// modifyStudentDataHelper(head, id, fName, lName, pno);
		ofstream fout("temp.txt");
		remove("student.txt");

		//std::ifstream src("student.txt", std::ios::binary);
		//std::ofstream dst("temp.txt", std::ios::binary);
		//dst << src.rdbuf();

		StudentNode* temp = head;
		while (temp != NULL) {
			if (temp->studentId == id) {
				break;
			}
			temp = temp->next;
		}
		temp->firstName = fName;
		temp->lastName = lName;
		temp->phoneNo = pNo;

		temp = head;
		while (temp != NULL) {
			fout << temp->studentId << ", " << temp->firstName << ", " << temp->lastName << ", " << temp->phoneNo << endl;
			temp = temp->next;
		}
		fout.close();
		rename("temp.txt", "student.txt");
	}

	void deleteStudentData(string id) {
		ofstream fout("temp.txt");
		remove("student.txt");

		StudentNode* temp = head;
		StudentNode *prev = NULL;

		while (temp != NULL) {
			if (temp->studentId == id) {
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		if (prev == NULL) {
			head = temp->next;
			temp->next = NULL;
			delete temp;
		}
		else {
			prev->next = temp->next;
			temp->next = NULL;
			delete temp;
			
		}
		temp = head;
		while (temp != NULL) {
			fout << temp->studentId << ", " << temp->firstName << ", " << temp->lastName << ", " << temp->phoneNo << endl;
			temp = temp->next;
		}
		fout.close();
		rename("temp.txt", "student.txt");
	}

};

