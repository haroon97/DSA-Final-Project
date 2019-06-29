#pragma once
#include "CourseNode.h"
#include <ctime>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996) 
using namespace std;
class Course
{
private:
	CourseNode* head;
	CourseNode* tail;

	void addIntoCourseList(CourseNode*& head, CourseNode*& tail, string courseID, string cName) {
		CourseNode *newNode = new CourseNode(courseID, cName);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	
public:    // PUBLIC FUNCIONS WHICH USERS HAVE ACCESS
	Course() {
		head = NULL;
		tail = NULL;
	}
	void addCourse(string courseID, string cName) {
		CourseNode* newNode = new CourseNode(courseID, cName);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		ofstream fout("course.txt", ios::app);
		fout << courseID << "," << cName << endl;
		fout.close();
		ofstream fout1("log.txt", ios::app);
		fout1 << "Date/Time: " << current_date() << " " << current_time() << endl;
		fout1 << "File Name: " << "course.txt" << endl;
		fout1 << "Date Added: " << courseID << " " << cName << endl;
		fout1.close();
	}

	void readFromCourseFile() {
		ifstream fin("course.txt");
		if (!fin.is_open()) {
			cout << "File not found" << endl;
			return;
		}
		string courseId, cName, line;
		while (getline(fin, line)) {
			stringstream ss(line);
			getline(ss, courseId, ',');
			getline(ss, cName, ',');
			addIntoCourseList(head, tail, courseId, cName);
		}
	}

	bool isCoursePresent(string courseId) {
		if (head == NULL) {
			return false;
		}
		CourseNode *temp = head;
		while (temp != NULL) {
			if (temp->courseId == courseId) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void listCourses() {
		if (head == NULL) {
			cout << "No record exists" << endl;
			return;
		}
		CourseNode* temp = head;
		while (temp != NULL) {
			cout << temp->courseId << "," << temp->courseName << endl;
			temp = temp->next;
		}
	}

	void modifyCourseData(string courseID, string cName) {
		ofstream fout("temp.txt");
		remove("course.txt");

		//std::ifstream src("student.txt", std::ios::binary);
		//std::ofstream dst("temp.txt", std::ios::binary);
		//dst << src.rdbuf();

		CourseNode* temp = head;
		while (temp != NULL) {
			if (temp->courseId == courseID) {
				break;
			}
			temp = temp->next;
		}
		string oldCourse = temp->courseName;
		temp->courseName = cName;

		temp = head;
		while (temp != NULL) {
			fout << temp->courseId << "," << temp->courseName << endl;
			temp = temp->next;
		}
		fout.close();
		rename("temp.txt", "course.txt");
		ofstream fout1("log.txt", ios::app);
		fout1 << "Date/Time " << current_date() << " " << current_time() << endl;
		fout1 << "File Name: " << "course.txt" << endl;
		fout1 << "Old Data: " << oldCourse << endl;
		fout1 << "New Data: " << cName << endl;
		fout1.close();
	}

	void deleteCourseData(string courseID) {
		string cName;
		ofstream fout("temp.txt");
		remove("course.txt");

		CourseNode* temp = head;
		CourseNode *prev = NULL;

		while (temp != NULL) {
			if (temp->courseId == courseID) {
				cName = temp->courseName;
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
			fout << temp->courseId << "," << temp->courseName << endl;
			temp = temp->next;
		}
		fout.close();
		rename("temp.txt", "course.txt");
		ofstream fout1("log.txt", ios::app);
		fout1 << "Date/Time: " << current_date() << " " << current_time() << endl;
		fout1 << "File Name: " << "course.txt" << endl;
		fout1 << "Data Deleted: " << courseID << " " << cName << endl;
		fout1.close();
	}
	
	//    GETTERRS

	string getCourseName(string courseID) {
		CourseNode* temp = head;
		while (temp != NULL) {
			if (temp->courseId == courseID) {
				return temp->courseName;
			}
			temp = temp->next;
		}
		return 0;
	}

	std::string current_date(){
		time_t now = time(NULL);
		struct tm tstruct;
		char buf[40];
		tstruct = *localtime(&now);
		//format: day DD-MM-YYYY
		strftime(buf, sizeof(buf), "%A %d/%m/%Y", &tstruct);
		return buf;
	}

	std::string current_time(){
		time_t now = time(NULL);
		struct tm tstruct;
		char buf[40];
		tstruct = *localtime(&now);
		//format: HH:mm:ss
		strftime(buf, sizeof(buf), "%X", &tstruct);
		return buf;
	}
};

