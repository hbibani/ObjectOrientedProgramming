#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	int z = 0;
	int g = 0;
	
	srand(time(0));
	g = rand()%15 + 1;
   
        
	while (x == 0 && y != 3)
	{
		
		cout << "Guess a number between 1 and 15 " << endl;
		cin >> z;


		if (z == g)
		{
			cout << "You guessed correctly : " << "The value is " << g;
			x = 1;
		}
		
		if ( z > g)
		{
			cout << "You guessed too high, the number is lower than that! " << endl;
		}
		
		if ( z < g)
		{
			cout << "You guessed too low, the number is higher than that! "<<endl;
		}
	
		y++;
	}

	if ((y == 3) && (z != g))
	{
		cout << "You guessed Incorrectly, the real value is : " << g;
	}

}


