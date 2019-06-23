#pragma once
#include "ResultNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
class Result
{
private:
	ResultNode* head;
	ResultNode* tail;

	void addIntoResultList(ResultNode*& head, ResultNode*& tail, string studentID, string courseID, string semester, int marks) {
		ResultNode *newNode = new ResultNode(studentID, courseID, semester, marks);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

public:
	Result() {
		head = NULL;
		tail = NULL;
	}

	void addResult(string studentID, string courseID, string semester, int marks) {
		ResultNode *newNode = new ResultNode(studentID, courseID, semester, marks);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		ofstream fout("result.txt", ios::app);
		fout << studentID << ", " << courseID << ", " << semester << ", " << marks << endl;
		fout.close();
	}

	void listResult() {
		if (head == NULL) {
			cout << "No record exists" << endl;
			return;
		}
		ResultNode* temp = head;
		while (temp != NULL) {
			cout << temp->studentId << ", " << temp->courseId << ", " << temp->semester << ", " << temp->marks << endl;
			temp = temp->next;
		}
	}

	void readFromResultFile() {
		ifstream fin("result.txt");
		if (!fin.is_open()) {
			cout << "File not found" << endl;
			return;
		}
		string courseID, studentID, semester, line, temp;
		int marks;
		while (getline(fin, line)) {
			stringstream ss(line);
			getline(ss, studentID, ',');
			getline(ss, courseID, ',');
			getline(ss, semester, ',');
			getline(ss, temp, ',');
			marks = stoi(temp);
			addIntoResultList(head, tail, studentID, courseID, semester, marks);
		}
	}

	bool isResultPresent(string courseID, string studentID) {
		if (head == NULL) {
			return false;
		}
		ResultNode *temp = head;
		while (temp != NULL) {
			if (temp->courseId == courseID && temp->studentId == studentID) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void modifyResultData(string studentID, string courseID, string semester, int marks) {
		ofstream fout("temp.txt");
		remove("result.txt");

		//std::ifstream src("student.txt", std::ios::binary);
		//std::ofstream dst("temp.txt", std::ios::binary);
		//dst << src.rdbuf();

		ResultNode* temp = head;
		while (temp != NULL) {
			if (temp->studentId == studentID) {
				break;
			}
			temp = temp->next;
		}
		temp->semester = semester;
		temp->marks = marks;

		temp = head;
		while (temp != NULL) {
			fout << temp->studentId << ", " << temp->courseId << ", " << temp->semester << ", " << temp->marks << endl;
			temp = temp->next;
		}
		fout.close();
		rename("temp.txt", "result.txt");
	}

	void deleteResultData(string studentID) {
		ofstream fout("temp.txt");
		remove("result.txt");

		ResultNode* temp = head;
		ResultNode *prev = NULL;

		while (temp != NULL) {
			if (temp->studentId == studentID) {
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
			fout << temp->studentId << ", " << temp->courseId << ", " << temp->semester << ", " << temp->marks << endl;
			temp = temp->next;
		}
		fout.close();
		rename("temp.txt", "result.txt");
	}

	//    GETTERS
	string getCourseID(string studentID, string semester) {
		ResultNode* temp = head;
		while (temp != NULL) {
			if (temp->studentId == studentID && temp->semester == semester) {
				return temp->courseId;
			}
			temp = temp->next;
		}
		return NULL;
	}

	int getMarks(string studentID, string semester) {
		ResultNode* temp = head;
		while (temp != NULL) {
			if (temp->studentId == studentID && temp->semester == semester) {
				return temp->marks;
			}
			temp = temp->next;
		}
		return NULL;
	}

	string gradeCalculator(int marks) {
		if (marks > 90) {
			return "A";
		}
		else if (marks > 85 && marks < 90) {
			return "A-";
		}
		else if (marks > 80 && marks < 85) {
			return "B+";
		}
		else if (marks > 75 && marks < 80) {
			return "B";
		}
		else if (marks > 70 && marks < 75)  {
			return "B-";
		}
		else if (marks > 60 && marks < 70) {
			return "C";
		}
		else if (marks > 50 && marks < 60) {
			return "D";
		}
		else {
			return "F";
		}
	}

	void getCourseReport(string courseID, string semester) {
		ResultNode* temp = head;
		int gradeA = 0, gradeAMinus = 0, gradeB = 0, gradeBPlus = 0, gradeBMinus = 0, gradeC = 0, gradeD = 0, gradeF = 0;
		while (temp != NULL) {
			if (temp->courseId == courseID && temp->semester == semester) {
				if (temp->marks > 90) {
					gradeA++;
				}
				else if (temp->marks > 85 && temp->marks < 90) {
					gradeAMinus++;
				}
				else if (temp->marks > 80 && temp->marks < 85) {
					gradeBPlus++;
				}
				else if (temp->marks > 75 && temp->marks < 80) {
					gradeB++;
				}
				else if (temp->marks > 70 && temp->marks < 75) {
					gradeBMinus++;
				}
				else if (temp->marks > 60 && temp->marks < 70) {
					gradeC++;
				}
				else if (temp->marks > 50 && temp->marks < 60) {
					gradeD++;
				}
				else {
					gradeF++;
				}
			}
			temp = temp->next;
		}
		cout << "Course ID: " << courseID << endl;
		cout << "Grade " << "Number Of Students" << endl;
		cout << "A " << gradeA << endl;
		cout << "A- " << gradeAMinus << endl;
		cout << "B+ " << gradeBPlus << endl;
		cout << "B " << gradeB << endl;
		cout << "B- " << gradeBMinus << endl;
		cout << "C " << gradeC << endl;
		cout << "D " << gradeD << endl;
		cout << "F " << gradeF << endl;
	}
};

