#include <iostream>

using namespace std;

int main()
{
	int mult = 1;

	for (int i = 1; i <= 10; i++)
	{

		for(int j = 1; j <= 10; j++)
		{
			mult = i * j;
			cout << mult << " ";
		}

		cout << endl;
	}
	
}


