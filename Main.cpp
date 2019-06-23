#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"
#include "Result.h"
using namespace std;

void getStudentReport(string studentID, string semester, Student s, Course c, Result r) {
	string firstName = s.getFirstName(studentID);
	string lastName = s.getLastName(studentID);
	string courseID = r.getCourseID(studentID);
	string courseName = c.getCourseName(courseID);
	int marks = r.getMarks(studentID);
	string grade = r.gradeCalculator(marks);

	cout << "STUDENT REPORT" << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "First Naeme: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Course Name: " << courseName << endl;
	cout << "Grade: " << grade << endl;
}

int main() {
	Result r;
	Student s;
	Course c;
	s.addStudent("1", "Haroon", "Ahmed", "12345");
	s.addStudent("2", "Haza", "Ahmed", "12345");
	s.addStudent("3", "Ahmed", "Ahmed", "12345");
	s.addStudent("4", "Hassan", "Ahmed", "12345");
	c.addCourse("123", "dld");
	c.addCourse("456", "Pf");
	c.addCourse("789", "OS");
	r.addResult("1", "123", "4th", 69);
	r.addResult("3", "456", "4th", 39);

	getStudentReport("1", "4th", s, c, r);
}
