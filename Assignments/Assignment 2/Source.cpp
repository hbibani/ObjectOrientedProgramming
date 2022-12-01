#include <ctime>
#include <vector>
#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const double minPrice = 50.0;
const double maxPrice = 150.0;	
const int maxQuantity = 50;
const int minQuantity = 1;

#include "Bid.h"
#include "matchedBids.h"
#include "Trader.h"
#include "Auctioneer.h"
#include "Simulator.h"

int main()
{
	srand(time(0));
	ofstream fout;
	fout.open("_out.txt");

	if (fout.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	Simulator* sim;
	sim = new Simulator();
	sim->passToAuctioneer();
	fout << *sim; //overloaded operator on fout scale
	
	return 0;
}
