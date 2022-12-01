#include<ctime>
#include<iostream>
#include <fstream>
#include <cstdlib>
#include<vector>
#include <iomanip>
#include<string>
#include <vector>

#include "Date(2).h"

using namespace std;

int main() {

	ifstream fin;

	//Read a date from the file
	fin.open("date_in.txt");
	if (fin.fail()) 
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	char deliminator;
	int day = 0;
	int month = 0;
	int year = 0;
	int leapyear = 0;
	
	
	ofstream fout;
	fout.open("date_out.txt");
	Date* d;
	Date* y;
	

	if (fout.fail()) 
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}
	
			int number = 1;
			y = new Date(day, month, year);
			(*y).randomGenerator();
			fout << *y;
	

	


	//output the date to a file


	/*
			fin >> day;
			fin.get(deliminator);
			fin >> month;
			fin.get(deliminator);
			fin >> year;
			fin.get(deliminator);
			*/

	return 0;
}
