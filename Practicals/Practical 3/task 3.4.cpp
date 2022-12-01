#include <iostream>

using namespace std;

char board[8][4];

void initializeArray()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = '_';
		}
	}
}

void initializeFull()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = 'X';
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

bool isInvalid(char board[][4], int row, int col)
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

bool isNotFull(char board[][4])
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

int main()
{
	int row;
	int col;

	initializeArray();
	//initializeFull();

	if (isNotFull(board))
	{
		do {
			cout << "These are the seats which are available. " << endl;
			displayBoard();
			cout << "Enter a row number" << endl;
			cin >> row;
			cout << "Enter a column number" << endl;
			cin >> col;
			cout << endl;
			if (!isInvalid(board, row, col))
			{
				board[row - 1][col - 1] = 'X';
			}

		} while (isNotFull(board));

		displayBoard();
	}



	cout << "All seats are taken, please try another service.";
	

	return 0;
}
