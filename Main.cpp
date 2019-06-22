#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"
using namespace std;

int main() {
	Course c;
	string id;
	c.readFromCourseFile();
	cin >> id;
	if (c.isCoursePresent(id)) {
		cout << "Course already present" << endl;
	}
	else {
		c.addCourse(id, "ds");
	}
	c.addCourse("7", "PF");
	c.addCourse("9", "dld");
	c.modifyCourseData("1", "toa");
	c.listCourses();
	c.deleteCourseData("7");
	c.deleteCourseData("1");
	cout << "After deletion" << endl;
	c.listCourses();

}
