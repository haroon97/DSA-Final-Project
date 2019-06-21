#pragma once
class ResultNode
{
public:
	string studentId;
	string courseId;
	string semester;
	int marks;
	ResultNode *next;

	ResultNode(string studentId, string courseId, string semester, int marks) {
		this->studentId = studentId;
		this->courseId = courseId;
		this->semester = semester;
		this->marks = marks;
		next = NULL;
	}
};

