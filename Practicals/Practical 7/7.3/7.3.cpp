#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	ifstream fin;
	ofstream fout;
	
	if (fin.fail())
	{
		cout << "Inpout file opening failed \n";
		exit(1);
	}
	
	fin.open("mathsheet.txt");
	fout.open("mathsheetanswers.txt");

	char next;
	char equals;
	int firstNumber;
	int secondNumber;
	int multiplication;
	int test = 0;
	
	while(!fin.eof())
	{
		fin >> firstNumber;
		fout << firstNumber;
		fin >> next;
		fout << next;
		fin >> secondNumber;
		fout << secondNumber;
		fin >> equals;
		fout << equals;
		fout << secondNumber*firstNumber;
		fout << endl;
	}
	
	fin.close();
	fout.close();	
}


