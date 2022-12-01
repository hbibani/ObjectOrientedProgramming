//addressBookType.h 
 
#ifndef H_addressBookType
#define H_addressBookType
  
#include <string>
#include <fstream>
#include "extPersonType.h"

using namespace std;

class addressBookType
{
public:
    addressBookType();
    void print() const;
    void loadData();
    void saveData();
    ifstream infile;
    char filename[50];
private:
    extPersonType list[500];
    
    int length;
};

void addressBookType::print() const
{
    for (int i = 0; i < length; i++)
        list[i].printInfo();
}

addressBookType::addressBookType()
{
    length = 0;
}

void addressBookType::loadData() {
	
	
	ifstream infile;

	char filename[50];

	cout << "Enter file name: ";
	cin >> filename;
	cout << endl;

	infile.open(filename);
	if (!infile) {
		cout << "Input file does not exists. " << "Program terminates!!!"
				<< endl;
		return;
	}

	string first, last;
	int day,month,year;
    string street, city, state, zip, phone, pStatus;

	int i = 0;
	while (infile >> first) {
		infile >> last >> month >> day >> year;
		infile.ignore(100, '\n');
		getline(infile, street);
		infile >> city >> state >> zip >> phone >> pStatus;
		extPersonType temp(first, last, month, day, year, street, city, state, zip,
				phone, pStatus);

	    list[i] = temp;
		i++;
	}
	length = i;

	infile.close();
}

void addressBookType::saveData()
{
	ofstream outFile;
	outFile.open("dataOut.txt");
	infile.open(filename);
	
	string first, last;
	int month, day, year;
    string street, city, state, zip, phone, pStatus;
    string phoneNumber, personStatus;
    stringstream ss;
	

	for(int i = 0; i < length; i++)
	{
		list[i].address.getDetails(street, city, state, zip);
		
		ss << "Name: "<<list[i].getFirstName() << " " << list[i].getLastName() << endl << "Date Of Birth : " << list[i].dob.getMonth() << " "
		 << list[i].dob.getDay() << " " << list[i].dob.getYear() << endl << "Phone Number : "
	     << list[i].getPhoneNumber() << endl << "Person Type :" << list[i].getStatus() << endl << "Address :" << street << ", " <<  city << ", " << state << endl << zip << endl << endl;
			
//		first = list[i].getFirstName();
//		last  = list[i].getLastName();
//		month  = list[i].dob.getMonth();
//		day = list[i].dob.getDay();
//		year = list[i].dob.getYear();
//		list[i].address.getDetails(street, city, state, zip);
//		phoneNumber = list[i].getPhoneNumber();
//		personStatus = list[i].getStatus();
	//	outFile << "Name: " << first << " " << last << endl << "Date Of Birth : "<< month << " " << day << " " << year << endl  << "Phone Number : " << phoneNumber << endl << "Person Type: " << personStatus << endl << "Address: " << endl << street << ", "<< city << ", "<< state << endl << zip << endl << endl;
	}
	
	string sss;
	sss = ss.str();
	outFile << sss;
	
    infile.close();
    outFile.close();
}

#endif
