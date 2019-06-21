#pragma once
#include <iostream>
#include <string>
using namespace std;

class CourseNode {
public:
	string courseId;
	string courseName;
	CourseNode *next;

	CourseNode(string courseId, string cName) {
		this->courseId = courseId;
		this->courseName = cName;
		next = NULL;
	}
};
