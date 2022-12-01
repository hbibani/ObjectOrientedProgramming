//Searches a partially filled array of nonnegative integers.
#include <iostream>

using namespace std;

	const int DECLARED_SIZE = 10;

class OneDArray{
	
	private:
	
		
	public:
	int arr[DECLARED_SIZE];
    int listSize;
		
void fillArray() {
 
	  	cout << "Enter up to " << size << " non-negative whole numbers.\n"
			<< "Mark the end of the list with a negative number.\n";
			
		int next, index = 0;
		cin >> next;
		while ((next >= 0) && (index < size))
		{
			arr[index] = next;
			index++;
			if (index < 10)
			{
				cin >> next;
			}
		}
		
		listSize = index;
}
	
		
	int search(int target)
{
		int index = 0;
		bool found = false;
		bool arr[10];
		
		for(int i = 0; i < listSize; i ++)
		{
			arr[i] = false;
		}


		for (index = 0; index < listSize; index++)
		{
			if (target == a[index])
			{
				arr[index] = true;
				found = true;
			}
		}


		for (int i = 0; i < listSize; i++)
		{
			if (arr[i] == true)
			{
				cout << "It has been found at index " << i << endl
					<< " (Remember: The first position is 0.)\n";
			}
		}

		if (found == false)
		{
			cout << target << " is not on the list.\n";
		}

}
	
};



int main( )
{
    int target;
    char ans;
    int result;
    
    OneDArray arrayObject;
    arrayObject.fillArray();
    
    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;

        result = arrayObject.search(target);
        if (result == -1)
            cout << target << " is not on the list.\n";
        else
            cout << "(Remember: The first position is 0.)\n";

        cout << "Search again?(y/n followed by return): ";
        cin >> ans;
    } while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";
    return 0;
}
