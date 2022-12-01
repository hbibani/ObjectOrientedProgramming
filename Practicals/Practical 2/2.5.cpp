#include <iostream>
#include <cstdlib>

using namespace std;


void sort(int& first, int& second, int& third)
{
	int temp = 0;
	if (first > second)
	{
		temp = first;
		first = second;
		second = temp;
	}
	if (first > third)
	{
		temp = first;
		first = third;
		third = temp;
	}
	if (third < second)
	{
		temp = third;
		third = second;
		second = temp;
	}

}

int main()
{
	int first = 0;
	int second = 0;
	int third = 0;
	
	cout << "Enter the first number " << endl;
	cin >> first;
	cout << "Enter the second number " << endl;
	cin >> second;
	cout << "Enter the third number " << endl;
	cin >> third;
	cout << endl;
	

	sort(first, second,third);

	cout << "first = " << first << endl << "second = " << second  << endl << "third = " << third; //We are expecting the values to be saved in the variables and therefore see changes

	return 0;
}
