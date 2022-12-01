#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	string test;
	string fix;
	test = "1h2e3j4a";
	cout << test;
	cout << test.length();
	
	
	for (int i = 0; test.length(); i++)
	{
		if(!(isalpha(test[i]) )
		{
			int x = 0;
			test[i] = '\0';		
		}			
	}	
	
	cout << test;
	
	return 0;

}
