#include<iostream>
#include<string>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "employee.h"

int main()
{
	string fname;
	string lname; 
	fname = "heja";
	lname = "bibani";
	int age = 31;
	employee Heja(fname, lname, age);
	employee James(fname,lname,age);
	employee Justin(fname,lname,age);
	Heja.viewCount();
    Justin.viewCount();
	return 0;
}
