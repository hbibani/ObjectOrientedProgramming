#include <iostream>

using namespace std;


void outputOdd(int a, int b)
{
	while (a <= b)
	{
		if (a % 2 != 0)
		{
			cout << "Odd Number = " << a << endl;
		}

		a++;
	}
}


void outputSumEven(int firstNum, int secondNum)
{
	int sum = 0;
	int first = firstNum;
	

	while (firstNum <= secondNum)
	{
		if (firstNum % 2 == 0)
		{
			sum = firstNum + sum;
		}
		
		firstNum++;
	}

	cout << "The sum of all the even numbers between " << first << " " << "and " << secondNum << " " << " is " << sum;
}


int main()
{
	int firstNum = 0;
	int secondNum = 0;

	while (firstNum >= secondNum)
	{
		cout << "Give me the first Number : " << endl;
		cin >> firstNum;

		cout << "Give me the second Number: " << endl;
		cin >> secondNum;
	}

	outputOdd(firstNum, secondNum);
	outputSumEven(firstNum, secondNum);
}


