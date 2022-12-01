
//Tic-Tac-Toe Header file

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

enum status { WIN, DRAW, CONTINUE };

class ticTacToe
{
public:
	void play();
	//Function to start the play.

	void displayBoard() const;
	//Function to print the board.

	bool isValidMove(int x, int y) const;
	//Function to determine if a move is valid.

	bool getXOMove(char moveSymbol);
	//Function to get a move for a player

	int gameStatus(char playerSymbol);
	//Function to determine the current status of the game.

	void reStart();
	//Function to restart the game.


	ticTacToe(int r)
	{
		noOfMoves = 0;
		sizeOfBoard = r;
		board = new char* [sizeOfBoard];

		for (int i = 0; i < sizeOfBoard; i++)
			board[i] = new char[sizeOfBoard];

			for (int i = 0; i < sizeOfBoard; i++)
			{
				for (int j = 0; j < sizeOfBoard; j++)
				{
					board[i][j] = ' ';
				}
			}
	}

	~ticTacToe() {
		for (int i = 0; i < sizeOfBoard; i++)
			delete[] board[i];
		delete[] board;
	}


private:
	char** board;
	int noOfMoves;
	int sizeOfBoard;
};


void ticTacToe::play()
{
	bool done = false;
	char player = 'X';
    


	displayBoard();

	while (!done)
	{
		done = getXOMove(player);

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}
}

void ticTacToe::displayBoard() const
{
	
	for (int i = 0; i < sizeOfBoard; i++)
	{
		cout << "   " << i + 1 << "  ";
	}
	
	cout << endl << endl;

	for (int row = 0; row < sizeOfBoard; row++)
	{
		cout << row + 1;

		if (row == sizeOfBoard - 1)
		{
			cout << "";
		}

		{
			for (int col = 0; col < sizeOfBoard; col++)
			{
				cout << setw(3) << board[row][col];

				if (col != (sizeOfBoard - 1))
					cout << "  |";
			}
		}

		cout << endl;

		if (row != sizeOfBoard - 1)
			cout << " ";

			for (int i = 0; i < sizeOfBoard; i++)
			{
				if (row != sizeOfBoard - 1)
				{
					if (i == 0)
					{
						cout << "_____|";
					}
					else if (i != sizeOfBoard - 1)
						cout << "_____|";
					else if (row != sizeOfBoard - 1)
						cout << "_____";
				}
			}

			if (row == sizeOfBoard - 1)
			{
				cout << " ";
				for (int col = 0; col < sizeOfBoard -1 ; col++)
				{
					cout << "     |";
				}
			}
			cout << endl;
			
		
	}

	
}

bool ticTacToe::isValidMove(int row, int col) const
{
	if (row > sizeOfBoard - 1 || col > sizeOfBoard - 1 || row < 0 || col < 0 || (board[row][col] == 'X') || (board[row][col] == 'O'))
	{

		cout << "That was an invalid move, try again." << endl;

		return false;
	}
	else
	{
		return true;
	}
}

bool ticTacToe::getXOMove(char playerSymbol)
{
	int row, col;

	do
	{
		cout << "Player " << playerSymbol
			<< " enter move: ";
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(row - 1, col - 1));

	row--;
	col--;

	board[row][col] = playerSymbol;
	displayBoard();

	int gStatus = gameStatus(playerSymbol);

	if (gStatus == 1)
	{
		cout << "Player " << playerSymbol << " wins!" << endl;
		return true;
	}
	else if (gStatus == 3)
	{
		cout << "This game is a draw!" << endl;
		return true;
	}
	else
		return false;
}

int ticTacToe::gameStatus(char playerSymbol)
{
	bool checkGameStatus = false;
	int x;
	
	//check Rows
	for (int rows = 0; rows <= sizeOfBoard - 1; rows++)
	{
		for (int cols = 0; cols <= sizeOfBoard - 1; cols++)
		{
			if (board[rows][cols] != playerSymbol)
			{
				break;
			}
			if (cols == sizeOfBoard - 1)
			{
				return 1;
			}
		}
	}

	//check Cols
	for (int cols = 0; cols <= sizeOfBoard - 1; cols++)
	{
		for (int rows = 0; rows <= sizeOfBoard - 1; rows++)
		{
			if (board[rows][cols] != playerSymbol)
			{   
				break;
			}
			if (rows == sizeOfBoard - 1)
			{
				return 1;
			}
		}
	}


	//check diagnol

	for (int i = 0; i <= sizeOfBoard - 1; i++)
	{
		if (board[i][i] != playerSymbol)
		{
			break;
		}
		if (i == sizeOfBoard - 1)
		{
			return 1;
		}
	}

	

for (int rows = (sizeOfBoard - 1), cols = 0;  rows <= 0 && cols <= (sizeOfBoard -1); rows--, cols++)
	{
		if (board[rows][cols] != playerSymbol)
		{
			break;
		}
		if (cols == sizeOfBoard - 1)
		{
			return 1;
		}
	}


	for (int rows = 0; rows <= sizeOfBoard - 1; rows++)
	{
		for (int cols = 0; cols <= sizeOfBoard - 1; cols++)
		{
			if (board[rows][cols] == ' ')
			{
				break;
			}
			if (rows == sizeOfBoard - 1 && cols == sizeOfBoard - 1)
			{
				return 3;
			}
		}

	}


}

void ticTacToe::reStart()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

