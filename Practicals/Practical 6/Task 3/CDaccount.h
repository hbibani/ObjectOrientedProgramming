
class CDaccount
{
	
	private:
		
	double initialBalance;
    double interestRate;
    int term;//months until maturity
    date* maturity; //date when CD matures
    double rateFraction;
    double interest;
		
	public:
		
	double balanceAtMaturity;
	CDaccount(double initial, double interest, int term1)
	{
		initialBalance = initial;
		interestRate = interest;
		term = term1;
		maturity = new date();
		
	}
	
	void enterMaturity()
	{
	    cout << "Enter the maturity date:\n";

	    maturity->getDate();
	    
	    rateFraction = interestRate/100.0;
	    interest = initialBalance*(rateFraction*(term/12.0));
	    balanceAtMaturity = initialBalance + interest;
	    
	}
	
	void showMaturity()
	{
		cout << balanceAtMaturity;
	}
	
	void printAccount()
	{
		maturity->showDate();
         cout << "it had a balance of $";
 		 showMaturity();  
  
    cout<< endl;
	}

	
};
