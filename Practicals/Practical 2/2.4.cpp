#include <iostream>
#include <cstdlib>

using namespace std;


void twoDigits(int& quotient, int& remainder)
{
	int temp1 = quotient;
	int temp2 = remainder;
	quotient = temp1 / temp2;
	remainder = temp1 % temp2;

}

int main()
{
	int firstNumberandQuotient = 0;
	int secondNumberandRemainder = 0;


	cout << "Enter the first number " << endl;
	cin >> firstNumberandQuotient;
	cout << "Enter the second number " << endl;
	cin >> secondNumberandRemainder;


	twoDigits(firstNumberandQuotient, secondNumberandRemainder);

	cout << "The quotient = " << firstNumberandQuotient << endl;
	cout << "The Remainder = " << secondNumberandRemainder;

	return 0;
}
