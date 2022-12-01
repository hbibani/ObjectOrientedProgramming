#include <iostream>
#include <cstdlib>

using namespace std;


void testDefaultArg(int day = 1, string month = "Jan",
	int year = 2017) {
	cout << "Today is " << day << " "
		<< month << " " << year << endl;
}

int main()
{
	testDefaultArg();
	testDefaultArg(10);
	testDefaultArg("Jul");
	testDefaultArg(10, "Jul", 2018);

	//The testDefaulArg has default arguments; and therefore when you call it without any extra info, it will stick to the default stated
}




/* 
Today is 1 Jan 2017
Today is 10 Jan 2017
Today is 10 Jul 2017
Today is 10 Jul 2018 
*/
