


#include<ctime>
#include<string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#ifndef JONE_H_
#define JONE_H_


class Sender {
	string message;

public:
	void setMessage();
	string getMessage() {return message;}
	vector<string> randomDates();
};

void Sender::setMessage() {
	string ss;
	cout << "Sender says:";
	getline(cin, ss);
	message = ss;
	
	
}

vector<string> Sender::randomDates()
{
	vector<string> dates;
	int leapyear = 0;
	srand(time(0));
	int day1 = 0;
	int month1 = 0;
	int year1 = 0;

	
	for (int i = 0; i < 100; i++){
		
	
		do{
			
			year1 = rand() % 4 + 2000;
			month1 = rand() % 12+1;
			
			if(year1%4 == 0)
			{
				leapyear = 1;
			}
						
			if(month1 == 2 && leapyear == 1)
			{
				day1 = rand() % 29 + 1;
			}
			else if(month1 == 2 && leapyear == 0)
			{
				day1 = rand() % 28 + 1; 
			}
			else if(month1 != 2)
			{
					if(month1 <= 7)
					{
						if ( month1 % 2 != 0)
						{
							day1 = rand()% 31 + 1;
						}
						else
						{
							day1 = rand()%30 + 1;
						}
					}
					
					if(month1 > 7)
					{
						if (month1 %2 == 0)
						{
								day1 = rand() % 31 + 1;
						}
						else
						{
							day1 = rand()%30 + 1;
						}
					}
			}
			
			leapyear = 0;	
		}	while ((year1 == 2003 && month1 == 4 && day1 > 28) || (year1 == 2003 && month1 > 4) ) ;


		stringstream date1;
		date1 << day1 << "/" << month1 << "/" << year1 << endl;
		string word = date1.str();
		

			dates.push_back(word);
	

	}
	
	return dates;
}
	

#endif /* JONE_H_ */
