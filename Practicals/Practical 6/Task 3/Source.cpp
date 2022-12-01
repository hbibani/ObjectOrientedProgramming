//Program to demonstrate the CDAccount structure type.
#include<iostream>
#include<string>
#include <iomanip>
#include <cstdlib>

using namespace std;


#include "date.h"
#include "CDaccount.h"

int main( )
{
	double initialBalance;
	double interestRate;
	int term;
	

	    cout << "Enter account data on the day account was opened:\n";
	    cout << "Enter account initial balance: $";
	    cin >> initialBalance;
	    cout << "Enter account interest rate: ";
	    cin >> interestRate;
	    cout << "Enter the number of months until maturity: ";
	    cin >> term;
	  

    CDaccount account(initialBalance, interestRate, term);
    account.enterMaturity();
    account.printAccount();

    //cout.setf(ios::fixed);
   // cout.setf(ios::showpoint);
  //  cout.precision(2);
  
 /* 
    cout << "When the CD matured on " 
         << date.day
         << "-"<< date.month << "-"  
	 << date.year << endl
         << "it had a balance of $"; 
    account.showMaturity();  
    cout<< endl;
  */ 
    
    return 0;
}


