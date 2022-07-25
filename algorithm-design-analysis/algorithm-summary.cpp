#include <iostream>
#include <string>

using namespace std;

// Student Array
void studentArray()
{
	string usr;
	int asciiChar;

	cout << "Enter student array: " << endl;
	getline(cin, usr);

	cout << usr << endl;

	for (int i = 0; i < usr.length(); i++)
	{
		asciiChar = usr[i];
		cout << asciiChar << " ";
	}
	cout << endl;
}

// A binary search based function
// to find the position
// where item should be inserted
// in a[low..high]
int binarySearch(int a[], int item,
	int low, int high)
{
	if (high <= low)
		return (item > a[low]) ?
		(low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item,
			mid + 1, high);
	return binarySearch(a, item, low,
		mid - 1);
}
// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		// find location where selected should be inseretd
		loc = binarySearch(a, selected, 0, j);

		// Move all elements after location to create space
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

// Lomuto Algorithm
int lomutoPartition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return(i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = lomutoPartition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);	
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


// Russian Peasant Algorithm
int russianPeasantMultiplication(int a, int b)
{
	int result = 0;
	
	while (b > 0)
	{
		if (b == 1)
		{
			result = result + a;
		}
		a += a;
		b /= 2;
	}
	return result;
}

int main()
{
	studentArray();

	int a[] = { 108, 97, 110, 116 };
	int arr[] = { 108, 97, 110, 116, 105, 103, 117 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(a, n);

	cout << "Sorted BRGC Array: \n";
	for (int i = 0; i < n; i++)
		cout << " " << a[i];

	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);

	cout << russianPeasantMultiplication(18, 1) << endl;
	cout << russianPeasantMultiplication(16, 13) << endl;
	cout << russianPeasantMultiplication(20, 12) << endl;
	return 0;
}
