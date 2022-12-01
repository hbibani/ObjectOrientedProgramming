//Reads data and displays a bar graph showing productivity for each plant.
#include <iostream>

using namespace std;

//Prints n asterisks to the screen.

class graph{
	private:
	int* production;
	int NUMBER_OF_PLANTS;
	int	amount;
	
	public:
	graph(int numberofPlants)
	{
		NUMBER_OF_PLANTS = numberofPlants;
		production = new int[NUMBER_OF_PLANTS];
		
		for (int i  = 0; i < NUMBER_OF_PLANTS; i++)
		{
			production[i] = 0;
		}
	}
	
	void inputData()
	{
		  for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
		    {
		        cout << endl
		             << "Enter production data for plant number "
		             << i << endl;
		        getTotal(i - 1);
		    }
	}
	
	void getTotal(int index)
	{
	    cout << "Enter a positive integer of units produced by each department, ranging from 1-20.\n" << endl;
	    cin >> amount;
	    
	    while (amount < 0)
	    {
	    	    cout<<"input again" << endl;
	        	cin >> amount;
	    }
	    production[index] = amount;
	    
	    
	}
	
	void graph1()
	{
	    cout << "\nUnits produced in units:\n";
	    for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
	    {
	        cout << "Plant #" << i << " ";
	        printAsterisks( production[i - 1] );
	        cout << endl;
	    }
	}	
	
	void printAsterisks(int n)
	{
	    for (int count = 1; count <=n; count++)
	        cout << "*";
	}

	~graph() {
		
		delete[] production;
	}
	
	
	
};

int main( )
{
	
/*
void inputData(int a[]);

void graph(const int a[]);

void getTotal(int&);
//Reads nonnegative integers from the keyboard
*/


    cout << "This program displays a graph showing\n"
         << "production for each plant in the company.\n";
         
   
    graph school(4);
    school.inputData();
    school.graph1();
    

    return 0;
}


