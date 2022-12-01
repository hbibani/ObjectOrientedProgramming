#include <iostream>
using namespace std;

void testOverloading(int numerator, int denominator) {
	int fraction = numerator / denominator;
	cout << "Fraction1 = " << fraction << endl;
}

void testOverloading(int numerator, double denominator) {
	double fraction = numerator / denominator;
	cout << "Fraction3 = " << fraction << endl;
}
//
//void testOverloading(double numerator, double denominatior)
//{
//	cout<< " Hail "
//}

int main()
{

	testOverloading(12, 24);
	testOverloading(12.0, 24.0);
	testOverloading(12, 24.0);
	
	//test some other value
	testOverloading(12.0,3);
	//does not execute if not within the same type of the parameters given
	return 0;


}
