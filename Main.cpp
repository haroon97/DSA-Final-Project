#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"
#include "Result.h"
using namespace std;

int main() {
	Result r;
	string cid, sid;
	cin >> cid;
	cin >> sid;

	r.readFromResultFile();

	r.addResult("123", "1", "1st", 54);
	r.addResult("455", "2", "2nd", 123);
	r.addResult("457", "4", "3rd", 143);
	r.deleteResultData("455");
	r.modifyResultData("123", "1", "8th", 100);
	r.listResult();

}
