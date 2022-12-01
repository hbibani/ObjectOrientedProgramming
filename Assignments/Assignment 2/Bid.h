

class Bid 
{
	
public:			//made these public without the need for making getters and setters [similar to struct]
	int bidID;
	char bidType;
	int traderID;
	double price;
	int quantity;
	static int objectCount; //for unique Identification
	bool operator>(Bid);
	bool operator<(Bid);
	
	Bid()
	{
		bidID = 0;
		bidType = 'X';
		traderID = 0;
		price = 0;
		quantity = 0;
	}

	Bid(int trID, char bType, double priceMoney, int quant)
	{
		objectCount++;
		bidID = objectCount;
		bidType = bType;
		price = priceMoney;
		quantity = quant;
		traderID = trID;
	}
};

bool Bid::operator>(Bid d)
{
	if (quantity > d.quantity)
	{
		return true;
	}
	else
	{
	  return false;
	}
}

bool Bid::operator<(Bid d)
{
	if(price < d.price)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Bid::objectCount = 0;



