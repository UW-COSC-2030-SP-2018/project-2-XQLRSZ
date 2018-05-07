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

	int arr[100];
	int s1[1] = { 1 };
	int a[5] = { 1, 2, 3, 4, 5 };

	// Test isSorted
	tests.push_back(Test("isSorted size 1 array", isSorted(s1, 1)));
	tests.push_back(Test("isSorted on entire array", isSorted(a, 5)));
	a[0] = 10;
	a[4] = 0;
	tests.push_back(Test("isSorted on range", isSorted(a, 1, 3)));

	// Test quicksort
	Sort::quicksort(s1, 0, 1);
	tests.push_back(Test("Quicksort size 1 array", isSorted(s1, 1)));
	fillArr(arr, 100);
	Sort::quicksort(arr, 0, 100);
	tests.push_back(Test("Quicksort entire array", isSorted(arr, 100)));
	fillArr(arr, 100);
	Sort::quicksort(arr, 30, 70);
	tests.push_back(Test("Quicksort range", isSorted(arr, 30, 70)));

	// Test mergesort
	Sort::mergesort(s1, 0, 1);
	tests.push_back(Test("Mergesort size 1 array", isSorted(s1, 1)));
	fillArr(arr, 100);
	Sort::mergesort(arr, 0, 100);
	tests.push_back(Test("Mergesort entire array", isSorted(arr, 100)));
	fillArr(arr, 100);
	Sort::mergesort(arr, 30, 70);
	tests.push_back(Test("Mergesort range", isSorted(arr, 30, 70)));
	 
	// Test binary search
	// I'm aware that it doesn't check for a sorted list
	// Doing so would make it O(n + log(n)), which defeats the point of binary searching
	Sort::mergesort(s1, 0, 1);
	tests.push_back(Test("Bsearch size 1 array when element exists",
					    (Sort::bsearch(s1, 1) != -1) ? true : false));




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
