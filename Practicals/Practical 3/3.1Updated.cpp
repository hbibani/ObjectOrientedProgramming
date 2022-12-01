//Searches a partially filled array of nonnegative integers.
#include <iostream>

using namespace std;

const int DECLARED_SIZE = 10;


	void fillArray(int a[], int size, int& numberUsed) 
	{
		cout << "Enter up to " << size << " non-negative whole numbers.\n"
			<< "Mark the end of the list with a negative number.\n";

		int next, index = 0;
		cin >> next;
		while ((next >= 0) && (index < size))
		{
			a[index] = next;
			index++;
			if (index < 10)
			{
				cin >> next;
			}

		}

		numberUsed = index;
	}

	void search(const int a[], int numberUsed, int target)
	{
		int index = 0;
		int temp = 0;
		bool found = false;

		while ((index < numberUsed))
		{
			if (target == a[index])
				found = true;

			if (found)
			{
				cout << "It has been found at index " << index << endl
					<< " (Remember: The first position is 0.)\n";
				found = false;
				temp++;
			}

			index++;
		}

		if (temp == 0)
		{
			cout << target << " is not on the list.\n";
		}

	}


	void search1(const int a[], int numberUsed, int target)
	{
		int index = 0;
		bool found = false;
		bool arr[10];
		
		for(int i = 0; i < numberUsed; i ++)
		{
			arr[i] = false;
		}


		for (index = 0; index < numberUsed; index++)
		{
			if (target == a[index])
			{
				arr[index] = true;
				found = true;
			}
		}


		for (int i = 0; i < numberUsed; i++)
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

	int main()
	{
		int arr[DECLARED_SIZE], listSize, target;

		fillArray(arr, DECLARED_SIZE, listSize);

		char ans;
		int result;
		do
		{
			cout << "Enter a number to search for: ";
			cin >> target;
			search1(arr, listSize, target);
			cout << "Search again?(y/n followed by return): ";
			cin >> ans;
		} while ((ans != 'n') && (ans != 'N'));

		cout << "End of program.\n";
		return 0;
	}
