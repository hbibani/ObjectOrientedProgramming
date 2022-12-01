#include<iostream>
#include<iomanip>
#include<ctime>
#include <cstdlib>


using namespace std;

const int ROWS = 3;
const int COLS = 4;

void valueSearch(int table[][4])
{
	int row;
	int col;

	cout << "Enter the row :" << endl;
	cin >> row;
	row = row - 1;
	cout << endl;
	cout << "Enter the column :" << endl;
	cin >> col;
	col = col - 1;


	cout << "The value in that index is = " << table[row][col] << endl;

	if (row != 0)
	{
		cout << "The value in the neighbour above = " << table[row - 1][col] << endl;
	}

	if (row != 2)
	{
		cout << "The value neighbour below = " << table[row + 1][col] << endl;
	}

	if (col != 0)
	{
		cout << "The value neighbour to the left = " << table[row][col - 1] << endl;
	}

	if (col != 3)
	{
		cout << "The value of the neighbour to the right = " << table[row][col + 1];

	}


}

int main() {

	srand(time(0));

	int table[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			table[i][j] = rand() % 3 - 1;
		}
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			cout << setw(3) << table[i][j];

		cout << endl;
	}

	valueSearch(table);



	return 0;
}
