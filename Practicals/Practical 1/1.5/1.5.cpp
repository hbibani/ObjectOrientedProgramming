#include <iostream> 
#include <cstdlib> 
#include<ctime>

using namespace std;

void inputRandom()
	{
		int x = 0;
		srand(time(0));
		
		int y; 
		while(x != 100)
	{
		
		x = rand() % 4;
		
		cout << x; 
		cin >> y;
	}
		char c;
		
		switch (x)
		{
		case 0: c = 'U'; 
			break;
		case 1: c = 'D';
			break;
		case 2: c = 'L';
			break;
		case 3: c = 'R';
			break;
		default:c =  'U';
		}
	}

int main() {
	
	
//	inputRandom();
		
	int month, day;     
	cout << "Welcome to your friendly weather program.\n" << "Enter today's date as two integers for the month and the day:\n";
	cin >> month;     
	cin >> day;
	srand(month * day);
	int prediction;     
	char ans;
	
	

	srand(time(0)); 
	
	cout << "Weather for today:\n";
	do {
		prediction = rand() % 3;         
		
		switch (prediction) {
		case 0:                 cout << "The day will be sunny!!\n";                 
		break;

		case 1:                 cout << "The day will be cloudy.\n";                
		break;

		case 2:                 cout << "The day will be stormy!.\n";                 
		break;

		default:                 cout << "Weather program is not functioning properly.\n";
		}
		cout << "Want the weather for the next day?(y/n): ";         cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	cout << "That's it from your 24 hour weather program.\n";     return 0;
}

