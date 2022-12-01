
class date
{
	public:
	int day;
	int month;
	int year;
	
	void getDate()
	{
    	cout << "Enter month: ";
    	cin >> month;
    	cout << "Enter day: ";
    	cin >> day;
    	cout << "Enter year: ";
    	cin >> year;
	}
	
	void showDate()
	{
		cout << "When the CD matured on " 
         << day
         << "-"<< month << "-"  
	 	<< year << endl;
	 

	}
};

