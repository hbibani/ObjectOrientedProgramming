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


void outputSumEven(int x, int y)
{
	int z = 0;
	int g = x;

	while (x <= y)
	{
		if (x % 2 == 0)
		{
			z = x + z;
		}
		
		x++
	}

	cout << "The sum of all the even numbers between " << g << " " << "and " << y << " " << " is " << z;
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
