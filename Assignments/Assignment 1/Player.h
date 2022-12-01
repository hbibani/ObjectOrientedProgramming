/*#include<iostream>
#include<string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
*/


class Player {
public:
	
char arrayCheck[4];

	Player()
	{
	
	}
	
	 virtual void inputPlayer(char playerColour, Board& x)
	{
		
	}

	//virtual void
};

class playerHuman : public Player
{
public:
	
	void inputPlayer(char playerColour, Board& board)
	{
		int test = 0;      			// variable to test correct input
		char decideMove = ' ';      //the decision of the move to make

		while (test == 0)
		{
			cout << "Player enter U,D,L,R" << endl;
			cin >> decideMove;

			if (!(decideMove == 'U' || decideMove == 'u' || decideMove == 'D' || decideMove == 'd' || decideMove == 'L' || decideMove == 'l' || decideMove == 'D' || decideMove == 'd' || decideMove == 'R' || decideMove == 'r'))
			{
				cout << "that was an invalid input, please enter something valid" << endl;
				test = 0;
			}
			else
			{
				test = 1;
			}
		}

		board.makeMove(decideMove, playerColour);
	}

};


class playerRandom : public Player
{
public:
	void inputPlayer(char playerColour, Board& board)
	{
		char nullChar = 'X'; 		 //null char value for array[4]
		int outOfOption = 1;  		// if all X's in array (no options); picks a generic option
		int randomNumber = 0;
		//randomnumber genrator
		srand(time(0));
		board.boardScan(playerColour, arrayCheck); //scan the board and inputs values into array 
		char LastOptions[4];

		for (int i = 0; i < 4; i++)
		{
			if (arrayCheck[i] != 'X')
			{
				break;                      //if array is filled with X's and No options [changes outofoption = 0]; and generic move will ensue [look line 109]
			}

			if (i == 3)
			{
				outOfOption = 0;
			}
		}

		if (outOfOption == 1)
		{
			while (nullChar == 'X')
			{
				randomNumber = rand() % 4;  //randomly picks a value from the array; if it is an X, it is discarded until a valid move is chosen randomly
				nullChar = arrayCheck[randomNumber];
			}
		}
		else if (outOfOption == 0)
		{

			LastOptions[0] = 'U';
			LastOptions[1] = 'D';
			LastOptions[2] = 'L';
			LastOptions[3] = 'R';

			randomNumber = rand() % 4;  //randomly picks a value from the array
			nullChar = LastOptions[randomNumber];

		}

		board.makeMove(nullChar, playerColour);
	}

};

class playerTank : public Player
{
public:
	void inputPlayer(char playerColour, Board& board)
	{


		char nullChar = 'X'; 		 //null char value for array[4]
		int outOfOption = 1;  		// if all X's in array (no options); picks a generic option
		int randomNumber = 0;    	//randomnumber genrator
		srand(time(0));
		board.boardScan(playerColour, arrayCheck); //scan the board and inputs values into array 
		int area[4];
		
		for (int i = 0; i < 4; i++)
		{
			area[i] = 0;
		}
		
		int highest =area[0];
		

		for (int i = 0; i < 4; i++)
		{
			if (arrayCheck[i] != 'X')
			{
				break;                      //if array is filled with X's and No options [changes outofoption = 0]; and generic move will ensue [look line 109]
			}

			if (i == 3)
			{
				outOfOption = 0;
			}
		}

		if (outOfOption == 1)
		{
			board.tankAreaCheck(playerColour, arrayCheck, area);
		}
		else if (outOfOption == 0)
		{
			nullChar = 'U';
		}
		
		for(int i = 0; i < 4; i++)
		   {
		   	  if(area[i] > highest)
		   	  {
		   	  	highest = area[i];	
			  }
		   }
		
	
	   int conditionCheck = 0;  //used to stop loop once a random position is found
	   srand(time(0));			//for more randomness seekchecker
		int positionFound = 0;
		
			while( conditionCheck == 0)
			{
			 	randomNumber = rand() % 4;  //randomly picks a value from the array; if it is an X, it is discarded until a valid move is chosen randomly
			 
				if( area[randomNumber] == highest)
				{
					positionFound = randomNumber;
					conditionCheck = 1;
				}	
		    }


	//find the highest value [store it]
	//find the index at which that value is on the array
	//then use that index to pick which corresponding letter it represents according the convention
	            
		if( positionFound == 0)
		{
			nullChar = 'U';
		}
	  	
	  	if(positionFound == 1)
	  	{
	  	  	nullChar  = 'D';	
		}
		
		if(positionFound == 2)
		{
			nullChar  = 'L';
		}
		
		if(positionFound == 3)
		{
			nullChar  =  'R';
		}


		board.makeMove(nullChar, playerColour);
		
		 //search for the highest, initialize highest to a[0]


		//find highest value in array
}

};
