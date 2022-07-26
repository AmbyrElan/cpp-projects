#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

/* Pseudocode */
/*
	A[i]
	i <= 25

	Create random digits
	Store inside A[i]

	Sort

	Display content of array after each pass
	Display # of swaps executed at the end
*/

string starter()
{
	return "|| ------Starting Array-------- ||\n";
}

string breaker()
{
	return "|| ---------------------------- ||\n";
}

string ender()
{
	return "|| --------Sorted Array-------- ||\n";
}

void startingArray(int arr[], int size)
{
	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (30 + 1);
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << "\n" << breaker();
}

int insertionSortAlgorithm(int arr[], int size_n)
{
	int count = 0;

	for (int i = 0; i < size_n; i++)
	{
		int arr_key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > arr_key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			count++;
		}
		arr[j + 1] = arr_key;
	}

	return count;
}

int main()
{
	/*
	generate a random digit
	store random digit into an array
	loop through 25 times
	return array
	*/
	int n = 25;
	int arr[25] = {};
	int numSwaps = 0;

	cout << starter();
	startingArray(arr, n);
	
	cout << breaker();
	numSwaps = insertionSortAlgorithm(arr, n);
	cout << "    Number of swaps >>> " << numSwaps << endl;
	cout << breaker();

	cout << ender();
	printArray(arr, n);

	return 0;
}
