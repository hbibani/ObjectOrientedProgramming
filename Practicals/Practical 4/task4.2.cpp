#include <iostream>

using namespace std;

class Student {
	
	private:
		long studentID;
		string studentName;
		int courseNo;
		bool employmentStatus;
	public:
		Student(long x, string y, int z, bool g)
		{
			/*
			string x;
			
			cout << " Enter StudentID " << endl;
			cin << studentID;
			cout << "Enter Student Name" << endl;
			cin studentName;
			cout << "Enter Course Number << endl;
			cin courseNo;
			cout << "Employment Status, Yes or No " << endl;
			cin << string;
			
			if (string == 'Yes')
			{
			  employmenStatus = true;
		    }
		    else
		    {
		       employmentStatus = false;
		     }
		
			*/
			
			studentID = x;
			studentName = y;
			courseNo = z;
			employmentStatus = g;
			
		}
		
		void displayInfo()
		{
			cout << "Student Number = " << studentID << endl
			<< "Student Name = " << studentName << endl
			<< "Course Number = " << courseNo << endl;
			
			if (employmentStatus == true)
			{
				cout << "Employment Status = Yes";
			}
			else
			{
				cout << "EmploymentStatus = No";
			}
			
			
		}
		
	
};


int main()
{
	
	long  studentID = 16301173;
	string name = "Heja";
	int courseNo = 21;
	bool employmentStatus = true;
	
	
	Student heja(studentID, name, courseNo, employmentStatus);
	heja.displayInfo();
	
}
