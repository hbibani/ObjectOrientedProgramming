#include <iostream>
#include <string>

using namespace std;

int main()
{

	string test;
	string fix;
	
	
	cout << "Enter String" << endl;
	cin >> test;
	
	//test = "1h2e3j4dfsf5dssfsdf6f";
	string placeHolder;
	
	//cout << test << endl;

	for (int i = 0; i <  test.length(); i++)
	{

		if (isalpha(test[i]))
		{
			placeHolder += test[i];
		}
	}

	int x = 1;

/*
	for (int i = 0; i < test.length(); i++)
		{

			if (i > 0 && isalpha(test[i]))
			{
				
				test[i - x] = test[i];
				test[i] = ' ';
				x++;
			}
		}

*/
	cout << placeHolder;
	
	return 0;

}
