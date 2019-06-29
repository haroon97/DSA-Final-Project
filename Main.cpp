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

	if (maxID == "") {
		cout << "Result Not Found Against Entered Record" << endl;
	}
	else {
		cout << "ID: " << maxID << endl;
		cout << "First Name: " << firstName << endl;
		cout << "Last Name: " << lastName << endl;
		cout << "Marks: " << marks << endl;
		cout << "Grade: " << grade << endl;
	}
}

void getStudentTranscript(string studentID, Result r, Course c) {
	vector<string> courseIds;
	vector<string> semester;
	vector<int> marks;
	r.getCourses(studentID, courseIds, marks, semester);
	cout << "Course Name" << " " << "Grade" << " " << "Semester" << endl;
	for (int i = 0; i < courseIds.size(); i++) {
		string courseName = c.getCourseName(courseIds[i]);
		string grade = r.gradeCalculator(marks[i]);
		cout << courseName << " " << grade << " " << semester[i] << endl;
	}
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
	cout << "10. Roll Back Data To Previous State" << endl << endl;
	cout << "-1. TO EXIT" << endl << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void addMenu() {
	cout << "1. Add In Student File" << endl;
	cout << "2. Add In Course File" << endl;
	cout << "3. Add In Result File" << endl << endl;
	cout << "-1. To Main Menu" << endl << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void listMenu() {
	cout << "1. List Student File" << endl;
	cout << "2. List Course File" << endl;
	cout << "3. List Result File" << endl << endl;
	cout << "-1. To Main Menu" << endl << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void modifyMenu() {
	cout << "1. Modify In Student File" << endl;
	cout << "2. Modify In Course File" << endl;
	cout << "3. Modify In Result File" << endl << endl;
	cout << "-1. To Main Menu" << endl << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void deleteMenu() {
	cout << "1. Delete In Student File" << endl;
	cout << "2. Delete In Course File" << endl;
	cout << "3. Delete In Result File" << endl << endl;
	cout << "-1. To Main Menu" << endl << endl;
	cout << "Please Enter The Serial Number Of The Operation You Want To Perform" << endl;
}

void logFile() {
	string s;
	ifstream fin("log.txt");
	while (!fin.eof()) {
		getline(fin, s);
		cout << s << endl;
	}
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
					system("cls");
					cout << "Enter Student ID" << endl;
					cin >> studentID;
					if (s.isStudentPresent(studentID)) {
						cout << "Student ID already exists" << endl;
					}
					else {
						cout << "Enter first name" << endl;
						cin >> firstName;
						cout << "Enter last name" << endl;
						cin >> lastName;
						cout << "Enter Phone Number" << endl;
						cin >> phoneNo;
						s.addStudent(studentID, firstName, lastName, phoneNo);
						cout << "Student Added" << endl;
					}
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "Enter Course ID" << endl;
					cin >> courseID;
					if (c.isCoursePresent(courseID)) {
						cout << "Course ID already exists" << endl;
					}
					else {
						cout << "Enter Course Name" << endl;
						cin >> courseName;
						c.addCourse(courseID, courseName);
						cout << "Course Added" << endl;
					}
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "Enter Student ID" << endl;
					cin >> studentID;
					cout << "Enter Course ID" << endl;
					cin >> courseID;
					if (!c.isCoursePresent(courseID) || !s.isStudentPresent(studentID)) {
						cout << "Student/Course Does'nt Exists" << endl;
					}
					else {
						cout << "Enter The Semester" << endl;
						cin >> semester;
						cout << "Enter Obtained Marks" << endl;
						cin >> marks;
						r.addResult(studentID, courseID, semester, marks);
						cout << "Result Added" << endl;
					}
					system("pause");
					break;
				default:
					break;
				}
			} while (operation2 != -1);
			system("cls");
			break;
		case 2:
			do {
				system("cls");
				listMenu();
				cin >> operation2;
				switch (operation2)
				{
				case 1:
					system("cls");
					s.listStudents();
					system("pause");
					break;
				case 2:
					system("cls");
					c.listCourses();
					system("pause");
					break;
				case 3:
					system("cls");
					r.listResult();
					system("pause");
					break;
				default:
					break;
				}
			} while (operation2 != -1);
			system("cls");
			break;
		case 3:
			do {
				system("cls");
				modifyMenu();
				cin >> operation2;
				switch (operation2)
				{
				case 1:
					system("cls");
					cout << "Enter Student ID Of The Student You Want To Modify" << endl;
					cin >> studentID;
					if (!s.isStudentPresent(studentID)) {
						cout << "ID Doesn'nt exists" << endl;
					}
					else {
						cout << "Enter First Name" << endl;
						cin >> firstName;
						cout << "Enter Last Name" << endl;
						cin >> lastName;
						cout << "Enter Phone Number" << endl;
						cin >> phoneNo;
						s.modifyStudentData(studentID, firstName, lastName, phoneNo);
						cout << "Student Record Modified Successfully" << endl;
					}
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "Enter The Course ID" << endl;
					cin >> courseID;
					if (!c.isCoursePresent(courseID)) {
						cout << "Course ID does'nt exists" << endl;
					}
					else {
						cout << "Enter Course Name" << endl;
						cin >> courseName;
						c.modifyCourseData(courseID, courseName);
						cout << "Course Data Modified Successfully" << endl;
					}
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "Enter The Student ID" << endl;
					cin >> studentID;
					cout << "Enter The Course ID" << endl;
					cin >> courseID;
					if (!c.isCoursePresent(courseID) || !s.isStudentPresent(studentID)) {
						cout << "Course/Student Doesnt exists" << endl;
					}
					else {
						cout << "Enter The Semester" << endl;
						cin >> semester;
						cout << "Enter The Marks" << endl;
						cin >> marks;
						r.modifyResultData(studentID, courseID, semester, marks);
						cout << "Result Data Modified Successfully" << endl;
					}
					system("pause");
					break;
				default:
					break;
				}
			} while (operation2 != -1);
			system("cls");
			break;
		case 4:
			do {
				system("cls");
				deleteMenu();
				cin >> operation2;
				switch (operation2)
				{
				case 1:
					system("cls");
					cout << "Enter Student ID" << endl;
					cin >> studentID;
					if (!s.isStudentPresent(studentID)) {
						cout << "Student Does'nt Exists" << endl;
					}
					else if (r.doesStudentExists(studentID)) {
						cout << "Record Of Student Exists in Results File, Delete From That First" << endl;
					}
					else {
						s.deleteStudentData(studentID);
						cout << "Student Deleted Successfully" << endl;
					}
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "Enter Course ID" << endl;
					cin >> courseID;
					if (!c.isCoursePresent(courseID)) {
						cout << "Course Does'nt Exists" << endl;
					}
					else if (r.doesCourseExists(courseID)) {
						cout << "Record Of Course Exists in Results File, Delete From That First" << endl;
					}
					else {
						c.deleteCourseData(courseID);
						cout << "Course Deleted Successfully" << endl;
					}
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "Enter Student ID" << endl;
					cin >> studentID;
					cout << "Enter Course ID" << endl;
					cin >> courseID;
					if (!s.isStudentPresent(studentID) || !c.isCoursePresent(courseID)) {
						cout << "Student/Course Does'nt Exists" << endl;
					}
					else {
						r.deleteResultData(studentID, courseID);
						cout << "Result Deleted Successfully" << endl;
					}
					system("pause");
					break;
				default:
					break;
				}
			} while (operation2 != -1);
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "Enter Student ID" << endl;
			cin >> studentID;
			if (r.doesStudentExists(studentID)) {
				cout << "Enter The Semester" << endl;
				cin >> semester;
				getStudentReport(studentID, semester, s, c, r);
			}
			else {
				cout << "Student Does'nt Exists" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "Enter Student ID" << endl;
			cin >> studentID;
			if (r.doesStudentExists(studentID)) {
				cout << "Student Transcript" << endl;
				getStudentTranscript(studentID, r, c);
			}
			else {
				cout << "Record Doesnt Exists" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "Enter Course ID" << endl;
			cin >> courseID;
			if (r.doesCourseExists(courseID)) {
				cout << "Enter the semester" << endl;
				cin >> semester;
				r.getCourseReport(courseID, semester);
			}
			else {
				cout << "Course Does'nt Exists" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			cout << "Enter Course ID" << endl;
			cin >> courseID;
			cout << "Enter the semester" << endl;
			cin >> semester;
			system("cls");
			getCourseTopper(courseID, semester, r, s);
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			logFile();
			system("pause");
			system("cls");
			break;
		case 10:
			cout << "Previous State" << endl;
			break;
		default:
			break;
		}
	} while (operation != -1);

}