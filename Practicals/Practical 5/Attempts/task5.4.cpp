#include <iostream>

using namespace std;

class Student {
	
	private:
		string studentName;
		int noOfUnits;
		string *unitNames; 
	public:
		Student(string name, int numberOfUnits) 
		{
			studentName = name;
			noOfUnits = numberOfUnits;
			unitNames = new string[noOfUnits];
		}
		
		void inputList()
		{
			for (int i = 0 ; i < noOfUnits; i++)
		    {
		    	cout << "Enter unit name " << endl;
		    	cin >> unitNames[i];
			}
		}
		
		void displayInfo()
		{
			cout << "Student Name = " << studentName << endl; 
			 
			for (int i = 0; i < noOfUnits; i++)
			{
				cout << "Unit " << i+1 << " is " << unitNames[i];
				cout << endl; 
			}
		}
		
		~Student()
		{
			delete[] unitNames;
		}
};


int main()
{
	string name;
	int unitAmount = 0;
	bool employmentStatus = true;

       cout << "Enter your Name" << endl;  
       cin >> name;
       cout << "Enter your number of Units" << endl;
       cin >> unitAmount; 
       
	Student heja(name, unitAmount);
	heja.inputList();
	heja.displayInfo();
}
