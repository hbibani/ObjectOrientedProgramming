#include <fstream>

class Simulator
{
	
friend ostream& operator<<(ostream &, const Simulator & );

private:
	Trader* buyer[10];
	Trader* seller[10];
	Bid buyerBid[10];
	Bid sellerBid[10];
	Auctioneer auct;
	vector<string> outFile1;
	string outFile2;
	
public:
	Simulator()
	{
		for (int i = 0; i < 10; i++) //10 pointer sellers
		{
			buyer[i] = new Buyer;
			seller[i] = new Seller;
		}
		
		for (int i = 0; i < 10; i++)
		{
			buyerBid[i] = buyer[i]->generateBid();  				//generate a Buyer Bid
			auct.addBid(buyerBid[i], buyerBid[i].bidType); 			//tell auctioneer about the bid
			sellerBid[i] = seller[i]->generateBid();  				//generate a seller bid
			auct.addBid(sellerBid[i], sellerBid[i].bidType); 		//tell auctioneer about sellerbid
		}
	}

	void passToAuctioneer()
	{
		auct.sortBid();    			//sort ascending seller, descending buyer
		auct.printBeforeMatch(); 	//print items before match
		auct.matchBids();        	//match the bids
		auct.printMatchedBid();  	//print the matches
		auct.printRemaining();   	//print the remaining bids
		//outFile1 = auct.returnFile();
		outFile2 = auct.returnFile();
	}
	
	~Simulator()
	{
	 	for (int i = 0; i < 10; i++)
    	{
        	delete buyer[i];
        	delete seller[i];
    	}
	}
};

ostream &operator<<(ostream &output, const Simulator &sim)
{
	
//	for (int i = 0; i < sim.outFile1.size(); i++)
//	{
//		output << sim.outFile[i];  //output file from overloaded operator
//	}
	
	output << sim.outFile2; 
	
	return output; // enables cascading
}

