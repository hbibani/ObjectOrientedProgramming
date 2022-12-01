

class Board {
private:
	int rows;
	int redRow;
	int redCol;
	int blueRow;
	int blueCol;
	char** board;

public:
	Board(int r) {

		//takes rows; and rows will act as column, since the board is square. 
		rows = r;
		board = new char* [rows];


		for (int i = 0; i < rows; i++)
			board[i] = new char[rows];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				board[i][j] = ' ';
			}
		}

		board[1][1] = 'R';
		board[rows - 2][rows - 2] = 'B';
		redRow = 1;
		redCol = 1;
		blueRow = rows - 2;
		blueCol = rows - 2;

	}

	void displayBoard()
	{
		for (int i = 0; i < rows; i++)
		{
			cout << " _____";
		}

		cout << endl;

		for (int row = 0; row < rows; row++)
		{
			cout << "|     ";
			for (int i = 0; i < rows; i++)
			{
				if (i != 0)
				{
					cout << "|     ";
				}
			}
			cout << "|" << endl;

			for (int i = 0; i < (rows); i++)
			{
				cout << "|  " << board[row][i] << "  ";
			}
			cout << "|";
			cout << endl;
			cout << "|";

			for (int col1 = 0; col1 < rows; col1++)
			{
				cout << "_____|";
			}
			cout << endl;

		}
		cout << endl;
	}

	int checkWinner(int gameStatus)
	{
		//checks winner; by calculating if red and blue are on board
		int red = 0;
		int blue = 0;
		int star = 0;

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < rows; col++)
			{
				if (board[row][col] == 'R')
				{
					red = 1;
				}
				if (board[row][col] == 'B')
				{
					blue = 1;
				}
				if (board[row][col] == '*')
				{
					star++;
				}
			}
		}

		if (star == 0)
		{
			return 1;
		}

		if (red == 1 && blue == 0 && star == 1)
		{
			cout << "Red Wins!";
			return  0;
		}

		if (red == 0 && blue == 1 && star == 1)
		{
			cout << "Blue Wins!";
			return 0;
		}

		if (red == 0 && blue == 0 && star == 2)
		{
			cout << "Draw! Sorry Guys you both suck!";
			return 0;
		}

		if (red == 0 && blue == 0 && star == 1)
		{
			cout << "Draw! Sorry Guys you both suck!";
			return  0;
		}
	}


	void colourCheck(char playerColour, int &row, int &col)
	{
		//determines which row and col to copy depending on the color given (player type)
		if (playerColour == 'R')
		{
			row = redRow;
			col = redCol;
		}
		else if (playerColour == 'B')
		{
			row = blueRow;
			col = blueCol;
		}
	}

	void makeMove(char playerMove, char colour)
	{
		//makes move from options player class has given it; and then modifies the board
		int check = 0;
		int row = 0;
		int col = 0;
	
	    
		colourCheck(colour, row, col); //checks which colour it is, to determine which values of the board to modify
		board[row][col] = 'O';         //places O on current spot
		check = checkValidMove(row, col, playerMove, colour); //checks if it is a valid move
	

		if (check == 0)
		{
			switch (playerMove)
			{
			case 'U':
			case 'u':
			{board[row - 1][col] = colour; row = row - 1; };
			break;
			case 'D':
			case 'd':
			{board[row + 1][col] = colour; row = row + 1; };
			break;
			case 'L':
			case 'l':
			{board[row][col - 1] = colour; col = col - 1; };
			break;
			case 'R':
			case 'r':
			{board[row][col + 1] = colour; col = col + 1; };
			break;
			default:board[row + 1][col];
				break;
			}
		}

		if (colour == 'R')
		{
			redRow = row;
			redCol = col;
		}
		else if (colour == 'B')
		{
			blueRow = row;
			blueCol = col;
		}


	}

	void boardScan(char colour, char(&a)[4])
	{
		int row;
		int col;


		//initialize array with 'X'; assuming that there is no option to begin with
		for (int i = 0; i < 4; i++)
		{
			a[i] = 'X';
		}

		//assign the correct row depending on colour [getting the values from privates]
		colourCheck(colour, row, col);

		//checks to see if there is any obstactle around it, if there is no obstacle, this is a valid move which will be put into the array; for the calling function to randomly decide 
		//which move to pick; or in the othercase, with the tank, to reduce the amount of options and decide which option (which are non obstacles) is the most wise to choose from(lower mistakes)

		if (!(row - 1 < 0 || col < 0 || row > rows - 1 || col > rows - 1 || board[row - 1][col] == 'R' || board[row - 1][col] == 'B' || board[row - 1][col] == 'O'))
		{
			a[0] = 'U';
		}

		if (!(row + 1 < 0 || col < 0 || row + 1 > rows - 1 || col > rows - 1 || board[row + 1][col] == 'R' || board[row + 1][col] == 'B' || board[row + 1][col] == 'O'))
		{
			a[1] = 'D';
		}

		if (!(row < 0 || col - 1 < 0 || row > rows - 1 || col  > rows - 1 || board[row][col - 1] == 'R' || board[row][col - 1] == 'B' || board[row][col - 1] == 'O'))
		{
			a[2] = 'L';
		}

		if (!(row < 0 || col + 1 < 0 || row > rows - 1 || col + 1 > rows - 1 || board[row][col + 1] == 'R' || board[row][col + 1] == 'B' || board[row][col + 1] == 'O'))
		{
			a[3] = 'R';
		}

	}

	void tankAreaCheck(char colour, char(&a)[4], int (&area)[4] )
	{
		/*
		Second filter, function "BoardScan" produces an array for valid inputs; boardscan eliminates options which will lead into a crash
		Whatever remaining in the array is passed to the tank area check, which uses the remaining values in the array;
		The best option in the remaining value is determined by the greatest amount of distance a particular move has over the other (using T directions [calculating the area infront + the area at the intersection]
		*/

		int row;
		int col;
		int rowNex;  //for simulating the board [and calculating area] without modifying actual values
		int colNex;  //for simulating the board [and calculating area] without modifying actual values



		colourCheck(colour, row, col);
		


		//get the values from the array that has been passed to it; if it is X assign that index as zero
		//note the array is positioned according my convention a[0] is up a[1] is down, a[2] is left a[3] right
		//The value which has the longest distance before it hits an obstacle has the the highest relative value
		//The highest value will be chosen as the direction, if two have the highest value, it will pick a decision randomly amongst the ones left
		for (int i = 0; i < 4; i++)
		{
			if (a[i] == 'X')
			{
				area[i] = 0;
			}

			if (a[i] == 'U')
			{
				for (int k = row - 1; k >= 0; k--)
				{

					if (board[k][col] == 'O' || board[k][col] == 'R' || board[k][col] == 'B')
					{
						break;
					}

					rowNex = k; 

					area[0] = area[0] + 1;
				}


				for (int j = col + 1; j < rows; j++)
				{
					if (board[rowNex][j] == 'O' || board[rowNex][j] == 'R' || board[rowNex][j] == 'B')
					{

						break;
					}

					area[0] = area[0] + 1;
				}

				for (int j = col - 1; j >= 0; j--)
				{
					if (board[rowNex][j] == 'O' || board[rowNex][j] == 'B' || board[rowNex][j] == 'R')
					{

						break;
					}
					area[0] = area[0] + 1;
				}
				
			}


			if (a[i] == 'D')
			{

				for (int j = row + 1; j < rows; j++)
				{
					if (board[j][col] == 'O' || board[j][col] == 'B' || board[j][col] == 'R')
					{

						break;
					}

					rowNex = j;

					area[1] = area[1] + 1;
				}

				for (int j = col + 1; j < rows; j++)
				{
					if (board[rowNex][j] == 'O' || board[rowNex][j] == 'R' || board[rowNex][j] == 'B')
					{

						break;
					}

					area[1] = area[1] + 1;
				}

				for (int j = col - 1; j >= 0; j--)
				{
					if (board[rowNex][j] == 'O' || board[rowNex][j] == 'B' || board[rowNex][j] == 'R')
					{

						break;
					}
					area[1] = area[1] + 1;
				}

			}


			if (a[i] == 'L')
			{
				for (int j = col - 1; j >= 0; j--)
				{
					if (board[row][j] == 'O' || board[row][j] == 'B' || board[row][j] == 'R')
					{
						break;
					}

					colNex = j;
					area[2] = area[2] + 1;
				}

				for (int k = row - 1; k >= 0; k--)
				{

					if (board[k][colNex] == 'O' || board[k][colNex] == 'R' || board[k][colNex] == 'B')
					{
						break;
					}

					area[2] = area[2] + 1;

				}

				for (int j = row + 1; j < rows; j++)
				{
					if (board[j][colNex] == 'O' || board[j][colNex] == 'B' || board[j][colNex] == 'R')
					{

						break;
					}

					area[2] = area[2] + 1;
				}
			}


			if (a[i] == 'R')
			{
				for (int j = col + 1; j < rows; j++)
				{
					if (board[row][j] == 'O' || board[row][j] == 'R' || board[row][j] == 'B')
					{

						break;
					}

					colNex = j;
					area[3] = area[3] + 1;
				}

				for (int k = row - 1; k >= 0; k--)
				{

					if (board[k][colNex] == 'O' || board[k][colNex] == 'R' || board[k][colNex] == 'B')
					{
						break;
					}

					area[3] = area[3] + 1;

				}

				for (int j = row + 1; j < rows; j++)
				{
					if (board[j][colNex] == 'O' || board[j][colNex] == 'B' || board[j][colNex] == 'R')
					{

						break;
					}

					area[3] = area[3] + 1;
				}
			}
		}
		
	}


	int checkValidMove(int row, int col, char playerMove, char colour)
	{
		//takes row and columnn of player
		//checks to see if the player has moved into an obstacle
		//if player moved into an obstacle, places a star in the position in which it has crashed in

		switch (playerMove)
		{
		case 'U':
		case 'u':
			if (row - 1 < 0 || board[row - 1][col] == '*' ||  board[row - 1][col] == 'R' || board[row - 1][col] == 'B' || board[row - 1][col] == 'O')
			{
				if (row - 1 < 0 )
				{
					board[row][col] = '*';
				}
				else
				{
					board[row - 1][col] = '*';
				}
				return 1;
			}
			break;
		case 'D':
		case 'd':
			if (row + 1 > rows - 1 || board[row + 1][col] == '*' ||  board[row + 1][col] == 'R' || board[row + 1][col] == 'B' || board[row + 1][col] == 'O')
			{
				if (row + 1 > rows - 1 )
				{
					board[row][col] = '*';
				}
				else
				{
					board[row + 1][col] = '*';
				}
				return 1;
			}
			break;
		case 'L':
		case 'l':
			if (col - 1 < 0 || board[row][col - 1] == '*' ||  board[row][col - 1] == 'R' || board[row][col - 1] == 'B' || board[row][col - 1] == 'O')
			{
				if (col - 1 < 0)
				{
					board[row][col] = '*';
				}
				else
				{
					board[row][col - 1] = '*';
				}

				return 1;
			}
			break;

		case 'R':
		case 'r':
			if ( col + 1 > rows - 1 || board[row][col + 1] == '*' || board[row][col + 1] == 'R' || board[row][col + 1] == 'B' || board[row][col + 1] == 'O')
			{
				if ( col + 1 > rows - 1 )
				{
					board[row][col] = '*';
				}
				else 
				{
					board[row][col + 1] = '*';
				}

				return 1;
			}
			break;
		default:board[row + 1][col];
			break;
		}
	
		
		return 0;
		
	}

	~Board() {
		for (int i = 0; i < rows; i++)
			delete[] board[i];
		delete[] board;
	}
};




