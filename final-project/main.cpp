// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "Test.h"
#include <vector>
#include <stdio.h> // printf, scanf, puts, NULL
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include "Sorts.h"
#include <iostream>

// Checks if the entire array is sorted
bool isSorted(int arr[], int size);
// Checks if a given range in the array is sorted
bool isSorted(int arr[], int low, int high);
// Fill array with random numbers
void fillArr(int arr[], int size);

int main()
{
	std::vector<Test> tests;

	// Test isSorted
	int a[5] = { 1, 2, 3, 4, 5 };
	tests.push_back(Test("isSorted on entire array", isSorted(a, 5)));
	a[0] = 10;
	a[4] = 0;
	tests.push_back(Test("isSorted on range", isSorted(a, 1, 3)));

	// Test quicksort
	int arr[100];
	fillArr(arr, 100);
	Sort::quicksort(arr, 0, 100);
	tests.push_back(Test("Quicksort entire array", isSorted(arr, 100)));
	fillArr(arr, 100);
	Sort::quicksort(arr, 30, 70);
	tests.push_back(Test("Quicksort range", isSorted(arr, 30, 70)));


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

void fillArr(int arr[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size - 1; i++) {
		arr[i] = rand() % 100;
	}
}
