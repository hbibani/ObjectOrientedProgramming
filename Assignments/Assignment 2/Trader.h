


class Trader
{
protected:

char traderType;
int quantity;
public:
	Trader()
	{
		traderType = 'X';
		quantity = 0;
	}

	virtual Bid generateBid() = 0;
};

class Buyer : public Trader
{
private:
	double priceAsk;
	int buyerID;
	static int objectCountBuyer; //for unique identification
	
public:
	Buyer()
	{
		objectCountBuyer++;
		buyerID = objectCountBuyer;
		traderType = 'B';
	}

	Bid generateBid()
	{
		
		quantity = rand() % maxQuantity + minQuantity;
		priceAsk = ((double)rand() / RAND_MAX) * (maxPrice - minPrice) + minPrice;
		Bid bidBuyer(buyerID, traderType, priceAsk, quantity);
		return bidBuyer;
	}
};

class Seller : public Trader
{
private:
	double priceSell;
	int sellerID;
	static int objectCountSeller; //for unique identification

public:
	Seller()
	{
		objectCountSeller++;
		traderType = 'S';
		sellerID = objectCountSeller;
	}

	Bid generateBid()
	{
		quantity = rand() % maxQuantity + minQuantity;
		priceSell = ((double)rand() / RAND_MAX) * (maxPrice - minPrice) + minPrice;
		Bid bidSeller(sellerID, traderType, priceSell, quantity);
		return bidSeller;
	}
};

int Seller::objectCountSeller = 0;
int Buyer::objectCountBuyer = 0;
