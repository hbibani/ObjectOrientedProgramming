//Functional implementation for basic Tic Tac Toe game (incomplete)

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayBoard(char board[][3]) {
	cout << "   1    2    3" << endl << endl;
	for (int row = 0; row < 3; row++) {
		cout << row + 1;
		for (int col = 0; col < 3; col++) {
			cout << setw(3) << board[row][col];
			if (col != 2)
				cout << " |";
		}
		cout << endl;
		if (row != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}
	cout << endl;
}

bool isValidMove(char board[][3], int row, int col) {
//Add conditions in the "if statement" to check if row and col are in the range between 0-2 and the cell is blank.
//Note that array index starts from 0


 if( row  > 2 || col > 2 ||  row  < 0 || col < 0 ||(board[row][col] == 'X') || ( board[row][col] == 'O')  )
 {
 	
	cout << "That was an invalid move, try again." << endl;
	
 	return false;
 }
 else
  {
  	return true;
  }

}

bool getXOMove(char board[][3], int noOfMoves, char playerSymbol) {
	int row, col;

	do {
		
		cout << "Player " << playerSymbol << " enter move: ";
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(board, row - 1, col - 1));

	row--;
	col--;

	noOfMoves++;

	board[row][col] = playerSymbol;
	displayBoard(board);

	if (noOfMoves >= 9) {
		return true;
	} else
		return false;
}

int main() {

	char board[3][3];
	int noOfMoves;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;

	bool done = false;
	char player = 'X';

	displayBoard(board);

	while (!done) {
		done = getXOMove(board, noOfMoves, player);

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}

	return 0;
}

