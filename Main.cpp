#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"
#include "Result.h"
using namespace std;

void getStudentReport(string studentID, string semester, Student s, Course c, Result r) {
	string firstName = s.getFirstName(studentID);
	string lastName = s.getLastName(studentID);
	string courseID = r.getCourseID(studentID, semester);
	string courseName = c.getCourseName(courseID);
	int marks = r.getMarks(studentID, semester);
	string grade = r.gradeCalculator(marks);

	cout << "STUDENT REPORT" << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Course Name: " << courseName << endl;
	cout << "Grade: " << grade << endl;
}

void getCourseReport(Result r, string studentID, string semester) {

}

int main() {
	Result r;
	Student s;
	Course c;
	
	r.addResult("1", "456", "4th", 69);
	r.addResult("3", "456", "4th", 39);
	r.addResult("5", "456", "4th", 79);
	r.addResult("6", "456", "4th", 59);
	r.addResult("7", "456", "4th", 89);
	r.addResult("8", "456", "4th", 99);
	r.addResult("9", "456", "4th", 79);
	r.addResult("2", "456", "4th", 100);
	r.addResult("10", "456", "4th", 19);

	r.getCourseReport("456", "4th");
}
