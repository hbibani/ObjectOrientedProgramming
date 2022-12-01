#include<iostream>
#include<string>
#include <iomanip>
#include <cstdlib>


class employee
{
	private:
		
	string firstName;
	string lastName;
	int age;
	static int objectCount;
		
	public:
		
	employee(string name, string lastName1, int age1)	
	{
		
		firstName = name;
		lastName  = lastName1;
		age = age1;
		objectCount++;
		
	}
	
	void viewCount()
	{
		
		cout << "The amount of times it's been called is " << objectCount << "." << endl;
		
	}
	
	~employee()
	{
		objectCount--;
	}
	
};

int employee::objectCount = 0;
