
#ifndef KATE_H_
#define KATE_H_

class Receiver {
	string message;
	
public:
	void receiveMessage(string ss) {message = ss;}
	void printMessage() {cout << "You said: " << message << endl;}
	void receiveVector(vector<string> dates);
};

void Receiver::receiveVector(vector<string> dates)
{
	for (int i = 0; i < dates.size(); i++)
	{
		cout << dates[i];
		
	}
	
}

#endif /* KATE_H_ */


