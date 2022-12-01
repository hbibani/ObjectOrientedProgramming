/*

#include <ctime>
#include<iostream>
#include<string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

*/

class Game{
private:
	int gameType;
public:
	int array[2];
	void displayOptions(int(&gameOption)[2]);
	void enterSizeOfBoard(int& x);
};

void Game::displayOptions(int(&gameOption)[2])
{
	//display option for Players

	for (int i = 0; i < 25; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "1" << "        " << "Human Vs Human" << endl;
	cout << "2" << "        " << "Human Vs Random" << endl;
	cout << "3" << "        " << "Human Vs Beast" << endl;
	cout << "4" << "        " << "Random Vs Random" << endl;
	cout << "5" << "        " << "Random Vs Beast" << endl;

	for (int i = 0; i < 25; i++)
	{
		cout << "#";
	}
	cout << endl << endl;
	cin >> gameType;


	switch (gameType)
	{
		case 1:
		{
			gameOption[0] = 0;
			gameOption[1] = 0;
		}
		break;

		case 2:
		{
			gameOption[0] = 0;
			gameOption[1] = 2;
		}
		break;

		case 3:
		{
			gameOption[0] = 0;
			gameOption[1] = 1;
		}
		break;
		case 4:
		{
			gameOption[0] = 2;
			gameOption[1] = 2;
		}
		case 5:
		{
			gameOption[0] = 2;
			gameOption[1] = 1;
		}
		break;

		default: 
		{
			gameOption[0] = 2;
			gameOption[1] = 2;
		}
	}
}

void Game::enterSizeOfBoard(int& r)
{  
	//Enter Size of board; if invalid, repeat question, until valid response
	  int x = 0;
	  int temp = 0;


	while (x == 0)
	{
			cout << "Enter the size of the board between 4-20: \n";
			cin >> r;
			cout<< endl;
			
			if(r < 4 || r > 20)
			{
				x = 0;
				r = temp;
				cout << "Please enter a valid number" << endl;
			}
			else
			{
			  x = 1;
			}
	}

}
