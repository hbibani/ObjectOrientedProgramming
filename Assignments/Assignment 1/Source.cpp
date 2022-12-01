#include<iostream>
#include<string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "Board.h"
#include "Game.h"
#include "Player.h"


int main()
{
	int rows = 0;
	int gameStatus = 1;
	int playerOptions[2];
	char red = 'R';
	char blue = 'B';

	Game startGame;
	startGame.enterSizeOfBoard(rows);
	Board board(rows);
	startGame.displayOptions(playerOptions);
	board.displayBoard();

//playoptions array that was sent to game object(start game) returns the types of player to play
	int player1 = playerOptions[0];
	int player2 = playerOptions[1];

//Three player pointer array
	Player* player[3];
	player[0] = new playerHuman;
	player[1] = new playerTank;
	player[2] = new playerRandom;

//game play
	while (gameStatus == 1)
	{ 
	
	//array with playeroptions in it determines which type of player and the input
		player[player1]->inputPlayer(red, board);
		player[player2]->inputPlayer(blue, board);
		board.displayBoard();
		gameStatus = board.checkWinner(gameStatus); //return winner to close gamestatus
	}

	
	return 0;
	

}

