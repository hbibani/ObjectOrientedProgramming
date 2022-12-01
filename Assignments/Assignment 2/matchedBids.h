class matchedBids
{
public:
	double clearingPrice;   // These are all public to avoid making too many getters and setters [similar to struct format]
	int buyerName;			
	int sellerName;			
	int buyerBidID;			
	int sellerBidID;		
	double buyerPrice;		
	double sellerPrice;		
	int buyerQuantity;		
	int sellerQuantity;		
	int quant;				
	double totalCost;	
	int quantityTaken;	
	
	Bid buy;
	Bid sell;
	
	


	void match(Bid& Buyer, Bid& Seller)
	{
		buyerBidID = Buyer.bidID;           
		sellerBidID = Seller.bidID;          
		buyerName = Buyer.traderID;             
		sellerName = Seller.traderID;         
		buyerPrice = Buyer.price;             
		sellerPrice = Seller.price;           
		buyerQuantity = Buyer.quantity;        
		sellerQuantity = Seller.quantity;        
		clearingPrice = (Seller.price + Buyer.price) / 2.0;

		if (Buyer > Seller) //compares quantity [just in case you forget]
		{
			quantityTaken = Seller.quantity;
			quant = Buyer.quantity - Seller.quantity;
			Seller.quantity = 0;
			Buyer.quantity = quant;
			
		}
		else
		{
			quantityTaken = Buyer.quantity;
			Seller.quantity = Seller.quantity - Buyer.quantity;
			quant = Buyer.quantity;
			Buyer.quantity = 0;
			
		}

		totalCost = (double)quantityTaken * clearingPrice;
	}
};

