
//Main program

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "TicTacToe.h"
int main()
{
	int size;
	cout << "Enter Size of Board" << endl;
	cin >> size;
	cout << endl << endl;
	ticTacToe game(size);

	game.play();

	return 0;
}
