
class Auctioneer
{
private:

vector<matchedBids> matchedBids1;
vector<Bid> buyerBid;
vector<Bid> sellerBid;
int matchedNum;
int numberBid;
stringstream value;
string word;
vector<string> outFile;

public:
	
	Auctioneer()
	{
		matchedNum = 0;
		numberBid = 1;	
	}
	
	void addBid(Bid b, char type)	//add bids to auctioneers stack
	{
		if(type == 'B')
		{
			buyerBid.push_back(b);
		}
		else if(type == 'S')
		{
			sellerBid.push_back(b);
		}
	}
	
	void matchBids()
	{
			matchedBids B; //for vector push_back
			
			for (int i = 0; i < sellerBid.size(); i++)
			{
				for (int j = 0; j < buyerBid.size(); j++)
				{
					if ( (sellerBid[i] < buyerBid[j] ) && buyerBid[j].quantity != 0) //compare price
					{
						 if (sellerBid[i].quantity == 0)
					    {
					    	break;
						}
						
						matchedBids1.push_back(B);
					    matchedBids1[matchedNum].match(buyerBid[j],sellerBid[i]); //match them in other file
					    matchedNum++;
					}
				}
			}				
	}
	
	void printBeforeMatch()
	{
		value <<"------------------------------------------------------------------------------------" << endl << "Sorted bids: " 
		<< endl << "------------------------------------------------------------------------------------" << endl;
		word = value.str();
		value << "traderID bidType bidID   price   quantity " << endl;
		word = value.str();  
			
		for(int i = 0; i < buyerBid.size(); i++)
		{
			value << "(Buyer" << buyerBid[i].traderID << ",    " << buyerBid[i].bidType << ",    " << buyerBid[i].bidID << ",    $"
				      << buyerBid[i].price << ",   " << buyerBid[i].quantity << ")" << endl;
			word = value.str();		
		}
			
		value <<endl;
		word = value.str();
		
		for (int i = 0; i < sellerBid.size(); i++)
		{
			value << "(Seller" << sellerBid[i].traderID << ",    " << sellerBid[i].bidType << ",    " << sellerBid[i].bidID << ",    $"
			      << sellerBid[i].price << ",    " << sellerBid[i].quantity << ")" << endl;
			word = value.str();
		}
			
		value <<"------------------------------------------------------------------------------------" << endl << "Matches: " << endl
		<< "------------------------------------------------------------------------------------" << endl;
		word = value.str();
	}
	
	void printMatchedBid()
	{
			for (int i = 0; i < matchedBids1.size(); i++)
			{			
				value << "Matched Bid : "<< (numberBid)<< endl << endl << "BuyerID: " << matchedBids1[i].buyerName << endl << "Buyer Bid ID: " << matchedBids1[i].buyerBidID << endl
					<< "Buyer Price: $" << matchedBids1[i].buyerPrice << endl << "Buyer Quantity: " << matchedBids1[i].buyerQuantity << endl
					<< "SellerID: " << matchedBids1[i].sellerName << endl << "Seller Bid ID: " << matchedBids1[i].sellerBidID << endl << "Seller Price: $"
					<< matchedBids1[i].sellerPrice << endl << "Seller Quantity: " << matchedBids1[i].sellerQuantity << endl << endl
					<< "Quantity Taken: " << matchedBids1[i].quantityTaken << endl << "Clearing Price: $" << matchedBids1[i].clearingPrice << endl
					<< "Total Cost: $" << matchedBids1[i].totalCost << endl
					<< "------------------------------------------------------------------------------------" << endl;
					
				numberBid++;
				word = value.str();
			}
			
			value << "Remaining Bids:" << endl  <<  "------------------------------------------------------------------------------------" << endl;
			word = value.str();
			value << "traderID bidType bidID   price   quantity " << endl;
			word = value.str();  
	}
	

		void printRemaining()
		{
			for(int i = 0; i < 10; i++)
			{
				if(buyerBid[i].quantity > 0)
				{
					value << "(Buyer" << buyerBid[i].traderID << ",    " << buyerBid[i].bidType << ",    " << buyerBid[i].bidID << ",    $"
				      << buyerBid[i].price << ",   " << buyerBid[i].quantity << ")" << endl;
					word = value.str();		
				}
			}
			
			value << endl;
			word = value.str();
			
			for (int i = 0; i < 10; i++)
			{
				if(sellerBid[i].quantity > 0)
				{
						value << "(Seller" << sellerBid[i].traderID << ",    " << sellerBid[i].bidType << ",    " << sellerBid[i].bidID << ",    $"
				      << sellerBid[i].price << ",    " << sellerBid[i].quantity << ")" << endl;
						word = value.str();
				}
			}
			
			
			cout << "total: " << numberBid;
		}
		
//		vector<string> returnFile()
//		{
//			outFile.push_back(word);
//			return outFile; //return stuff to be printed
//		}
			
		string returnFile()
		{
			return word;
		}
		
		void sortBid()
		{
			Bid temp;
			int test = 0;
			
			do {
					test = 0;
					
					for (int i = 0; i < 10; i++)
					{	
						if(buyerBid[i] < buyerBid[i+1] && (i+1) != 10)
						{
							temp = buyerBid[i+1];
							buyerBid[i+1] = buyerBid[i];
							buyerBid[i] = temp;
							test++;
						}
					}
				
				} while (test > 0);
		
			do {
				
				test = 0;
				
				for( int i =0; i < 10; i++)
				{
					if(sellerBid[i] > sellerBid[i+1] && (i+1) != 10)
					{
						temp = sellerBid[i+1];
						sellerBid[i+1] = sellerBid[i];
						sellerBid[i] = temp;
						test++;
					}
				}
			} while (test > 0);
		}
	};






