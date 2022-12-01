#include <iostream>

using namespace std;




class Board
{

private: 

char board[8][4];
int row;
int col;

public:
	
void initializeArray()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = '___';
		}
	}
}

void displayBoard()
{
	cout << "  " << "1 2 3 4" << endl;

	for (int j = 0; j < 8; j++)
	{
		cout << (j + 1);

		for (int i = 0; i < 4; i++)
		{
			cout << " " << board[j][i];
		}
		cout << endl;
	}
	cout << endl;
}

bool checkValid( int row, int col)
{
	if (row > 8 || row < 0 || col < 0 || col > 4)
	{
		cout << "That was an invalid choice, please enter a valid seat number." << endl << endl;
		return true;
	}

	if (board[row - 1][col - 1] == 'X')
	{
		cout << "Sorry, this seat is taken by another customer, please, enter a new seat number." << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}


bool checkFull()
{
	bool x = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 'X')
			{
				return true;
			}
		}
	}
	
	return false;
}


void queryBoard()
{

	if (checkFull())
	{
		do {
			cout << "These are the seats which are available. " << endl;
			displayBoard();
			cout << "Enter a row number" << endl;
			cin >> row;
			cout << "Enter a column number" << endl;
			cin >> col;
			cout << endl;
			if (!checkValid(row, col))
			{
				board[row - 1][col - 1] = 'X';
			}
	
		} while (checkFull());
	
		
		displayBoard();
		
	}
	
		if (!checkFull())
		{	
			cout << "All seats are taken, please try another service.";
		}
	

}
	

};





int main()
{
	
	Board tic;
	tic.initializeArray();
	tic.queryBoard();
	
	return 0;
}
