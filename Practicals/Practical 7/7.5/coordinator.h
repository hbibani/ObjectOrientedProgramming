
#ifndef COORDINATOR_H_
#define COORDINATOR_H_

class Coordinator {
	Sender sender;
	Receiver receiver;
	
public:
	void run();
	vector<string> dates;
};

void Coordinator::run() {
	//sender.setMessage(); // the sender set a message
	dates = sender.randomDates();
    receiver.receiveMessage(sender.getMessage()); // get message from the sender and pass it to the receiver
    receiver.receiveVector(dates);
    //receiver.printMessage();
}
#endif /* COORDINATOR_H_ */
