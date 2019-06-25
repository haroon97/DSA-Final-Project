#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"
#include <vector>
#include "Result.h"
using namespace std;

void getStudentReport(string studentID, string semester, Student s, Course c, Result r) {
	vector<string> courseIdArray;
	vector<string> courseName;
	vector<int> marks;
	vector<string> grades;
	r.getCourseID(studentID, semester, courseIdArray);
	for (int i = 0; i < courseIdArray.size(); i++) {
		courseName.push_back(c.getCourseName(courseIdArray[i]));
		marks.push_back(r.getMarks(studentID, courseIdArray[i]));
		grades.push_back(r.gradeCalculator(marks[i]));
	}

	string firstName = s.getFirstName(studentID);
	string lastName = s.getLastName(studentID);
   

	cout << "STUDENT REPORT" << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Course Name " << "Grade" << endl;
	for (int i = 0; i < courseIdArray.size(); i++) {
		cout << courseName[i] << " " << grades[i] << endl;
	}

}

void getCourseTopper(string courseID, string semester, Result r, Student s) {
	string maxID = r.getMaxId(courseID, semester);
	int marks = r.getMarks(maxID, courseID);
	string firstName = s.getFirstName(maxID);
	string lastName = s.getLastName(maxID);
	string grade = r.gradeCalculator(marks);

	cout << "ID: " << maxID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Marks: " << marks << endl;
	cout << "Grade: " << grade << endl;

}

void menu() {
	cout << "1. Add Record" << endl;
	cout << "2. List Record" << endl;
	cout << "3. Modify Record" << endl;
	cout << "4. Delete Record" << endl;
	cout << "5. Get Student Report" << endl;
	cout << "6. Get Student Transcipt" << endl;
	cout << "7. Get Course Report" << endl;
	cout << "8. Get Course Topper" << endl;
	cout << "9. Maintain Log File" << endl;
	cout << "10. Roll Back Data To Previous State" << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void addMenu() {
	cout << "1. Add In Student File" << endl;
	cout << "2. Add In Course File" << endl;
	cout << "3. Add In Result File" << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void listMenu() {
	cout << "1. List Student File" << endl;
	cout << "2. List Course File" << endl;
	cout << "3. List Result File" << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void modifyMenu() {
	cout << "1. Modify In Student File" << endl;
	cout << "2. Modify In Course File" << endl;
	cout << "3. Modify In Result File" << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void deleteMenu() {
	cout << "1. Delete In Student File" << endl;
	cout << "2. Delete In Course File" << endl;
	cout << "3. Delete In Result File" << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}



int main() {
	Result r;
	Student s;
	Course c;

	s.readFromFile();
	c.readFromCourseFile();
	r.readFromResultFile();
	string studentID, firstName, lastName, phoneNo, courseID, courseName, semester;
	int operation, operation2, marks;
	//ifstream fin1("student.txt"), fin2("course.txt"), fin3("result.txt");
	bool a = true;
	
	if (!a) {
		cout << "Files not opened correctly" << endl;
	}
	else {
		do {
			menu();
			cin >> operation;
			switch (operation)
			{
			case 1:
				do {
					system("cls");
					addMenu();
					cin >> operation2;
					switch (operation2)
					{
					case 1:
						cout << "Enter Student ID" << endl;
						cin >> studentID;
						while (s.isStudentPresent(studentID)) {
							cout << "ID Already Exists" << endl;
							cout << "Enter Student ID" << endl;
							cin >> studentID;
						}
						cout << "Enter first name" << endl;
						cin >> firstName;
						cout << "Enter last name" << endl;
						cin >> lastName;
						cout << "Enter Phone Number" << endl;
						cin >> phoneNo;
						s.addStudent(studentID, firstName, lastName, phoneNo);
						break;
					case 2:
						cout << "Enter Course ID" << endl;
						cin >> courseID;
						while (c.isCoursePresent(courseID)) {
							cout << "ID already exists" << endl;
							cout << "Enter Course ID" << endl;
							cin >> courseID;
						}
						cout << "Enter Course Name" << endl;
						cin >> courseName;
						c.addCourse(courseID, courseName);
						break;
					case 3:
						cout << "Enter Student ID" << endl;
						cin >> studentID;
						cout << "Enter Course ID" << endl;
						cin >> courseID;
						while (!c.isCoursePresent(courseID) || !s.isStudentPresent(studentID)) {
							cout << "Student/Course Does'nt Exists" << endl;
							cout << "Enter Student ID" << endl;
							cin >> studentID;
							cout << "Enter Course ID" << endl;
							cin >> courseID;
						}
						cout << "Enter The Semester" << endl;
						cin >> semester;
						cout << "Enter Obtained Marks" << endl;
						cin >> marks;
						r.addResult(studentID, courseID, semester, marks);
						break;
					default:
						break;
					}
				} while (operation2 != -1);
				system("cls");
				break;
			case 2:
				do {
					listMenu();
					cin >> operation2;
					system("cls");
					switch (operation2)
					{
					case 1:
						s.listStudents();
						break;
					case 2:
						c.listCourses();
						break;
					case 3:
						r.listResult();
						break;
					default:
						break;
					}
				} while (operation2 != -1);
			case 3:
				do {
					system("cls");
					modifyMenu();
					cin >> operation2;
					switch (operation2)
					{
					case 1:
						cout << "Enter Student ID Of The Student You Want To Modify" << endl;
						cin >> studentID;
						while (!s.isStudentPresent(studentID)) {
							cout << "ID Doesn'nt exists" << endl;
							cout << "Enter Student ID" << endl;
							cin >> studentID;
						}
						cout << "Enter First Name" << endl;
						cin >> firstName;
						cout << "Enter Last Name" << endl;
						cin >> lastName;
						cout << "Enter Phone Number" << endl;
						cin >> phoneNo;
						s.modifyStudentData(studentID, firstName, lastName, phoneNo);
						break;
					case 2:
						cout << "Enter The Course ID" << endl;
						cin >> courseID;
						while (!c.isCoursePresent(courseID)) {
							cout << "Course ID does'nt exists" << endl;
							cout << "Enter The Course ID" << endl;
							cin >> courseID;
						}
						cout << "Enter Course Name" << endl;
						cin >> courseName;
						c.modifyCourseData(courseID, courseName);
						break;
					case 3:
						cout << "Enter The Student ID" << endl;
						cin >> studentID;
						cout << "Enter The Course ID" << endl;
						cin >> courseID;
						while (!c.isCoursePresent(courseID) || !s.isStudentPresent(studentID)) {
							cout << "Student/Course does'nt exists" << endl;
							cout << "Enter The Student ID" << endl;
							cin >> studentID;
							cout << "Enter The Course ID" << endl;
							cin >> courseID;
						}
						cout << "Enter The Semester" << endl;
						cin >> semester;
						cout << "Enter The Marks" << endl;
						cin >> marks;
						r.modifyResultData(studentID, courseID, semester, marks);
						break;
					default:
						break;
					}
				} while (operation2 != -1);
			case 4:
				do {
					//system("cls");
					deleteMenu();
					cin >> operation2;
					switch (operation2)
					{
					case 1:
						cout << "Enter Student ID" << endl;
						cin >> studentID;
						while (!s.isStudentPresent(studentID)) {
							cout << "Student Does'nt Exists" << endl;
							cout << "Enter Student ID" << endl;
							cin >> studentID;
						}
						if (r.doesStudentExists(studentID)) {
							cout << "Record Of Student Exists in Results File, Delete From That First" << endl;
						}
						else {
							s.deleteStudentData(studentID);
						}
						
						break;
					case 2:
						cout << "Enter Course ID" << endl;
						cin >> courseID;
						while (!c.isCoursePresent(courseID)) {
							cout << "Course Does'nt Exists" << endl;
							cout << "Enter Course ID" << endl;
							cin >> courseID;
						}
						if (r.doesCourseExists(courseID)) {
							cout << "Record Of Course Exists in Results File, Delete From That First" << endl;
						}
						else {
							c.deleteCourseData(courseID);
						}
						break;
					case 3:
						cout << "Enter Student ID" << endl;
						cin >> studentID;
						cout << "Enter Course ID" << endl;
						cin >> courseID;
						while (!s.isStudentPresent(studentID) || !c.isCoursePresent(courseID)) {
							cout << "Student/Course Does'nt Exists" << endl;
							cout << "Enter Student ID" << endl;
							cin >> studentID;
							cout << "Enter Course ID" << endl;
							cin >> courseID;
						}
						r.deleteResultData(studentID, courseID);
						break;
					default:
						break;
					}
				} while (operation2 != -1);
			case 5:
				cout << "Enter Student ID" << endl;
				cin >> studentID;
				cout << "Enter The Semester" << endl;
				cin >> semester;
				getStudentReport(studentID, semester, s, c, r);
				break;
			case 6:
				cout << "Enter Course Name" << endl;
				cin >> courseName;
				cout << "Student Transcript" << endl;
				break;
			case 7:
				cout << "Enter Course ID" << endl;
				cin >> courseID;
				cout << "Enter the semester" << endl;
				cin >> semester;
				r.getCourseReport(courseID, semester);
				break;
			case 8:
				cout << "Enter Course ID" << endl;
				cin >> courseID;
				cout << "Enter the semester" << endl;
				cin >> semester;
				getCourseTopper(courseID, semester, r, s);
				break;
			case 9:
				
				break;
			case 10:
				cout << "Previous State" << endl;
				break;
			default:
				break;
			}
		} while (operation != -1);
	}

}
