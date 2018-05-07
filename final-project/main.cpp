// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
using std::cout;
using std::endl;

// Checks if the entire array is sorted
bool isSorted(int arr[], int size);
// Checks if a given range in the array is sorted
bool isSorted(int arr[], int low, int high);

int main()
{
	int tests[100][100] = { -1 };
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << tests[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

bool isSorted(const int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

bool isSorted(const int arr[], int low, int high) {
	for (int i = low; i < high - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}