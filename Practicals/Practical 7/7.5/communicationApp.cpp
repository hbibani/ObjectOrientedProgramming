
#include<ctime>
#include<iostream>
#include <fstream>
#include <cstdlib>
#include<vector>
#include <iomanip>
#include<string>
#include <vector>
using namespace std;

#include"sender.h"
#include"receiver.h"
#include"coordinator.h"


int main() {
	Coordinator c;
	c.run();
	return 0;
}
