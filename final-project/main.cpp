#include "Test.h"
#include "Sorts.h"
#include <vector>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <iostream>
#include "BloomFilter.h"

// Check if the entire array is sorted
bool isSorted(const int arr[], int size);
// Check if a given range in the array is sorted
bool isSorted(const int arr[], int low, int high);
// Fill array with random numbers
void fillArr(int arr[], int size);

int main() {
	std::vector<Test> tests;

	int arr[100];
	int s1[1] = { 1 };
	int a[5] = { 1, 2, 3, 4, 5 };

	// Test isSorted
	tests.push_back(Test("isSorted size 1 array", isSorted(s1, 1), true));
	tests.push_back(Test("isSorted on entire array", isSorted(a, 5), true));
	a[0] = 10;
	a[4] = 0;
	tests.push_back(Test("isSorted on range", isSorted(a, 1, 3), true));
	fillArr(arr, 100);
	tests.push_back(Test("isSorted on (most likely) unsorted array", isSorted(arr, 100), false));

	// Test quicksort
	Sort::quicksort(s1, 0, 0);
	tests.push_back(Test("Quicksort size 1 array", isSorted(s1, 1), true));
	Sort::quicksort(arr, 0, 99);
	tests.push_back(Test("Quicksort entire array", isSorted(arr, 100), true));
	fillArr(arr, 100);
	Sort::quicksort(arr, 30, 70);
	tests.push_back(Test("Quicksort range", isSorted(arr, 30, 70), true));

	// Test mergesort
	Sort::mergesort(s1, 0, 0);
	tests.push_back(Test("Mergesort size 1 array", isSorted(s1, 1), true));
	fillArr(arr, 100);
	Sort::mergesort(arr, 0, 99);
	tests.push_back(Test("Mergesort entire array", isSorted(arr, 100), true));
	fillArr(arr, 100);
	Sort::mergesort(arr, 30, 70);
	tests.push_back(Test("Mergesort range", isSorted(arr, 30, 70), true));
	 
	// Test binary search
	// I'm aware that it doesn't check for a sorted list
	// Doing so would make it O(n + log(n)), which defeats the point of binary searching
	tests.push_back(Test("Bsearch on size 1 array when key exists",
					    (Sort::bsearch(s1, 1, 1) != -1) ? true : false, true));
	tests.push_back(Test("Bsearch on size 1 array when key doesn't exist",
						(Sort::bsearch(s1, 1, 0) != -1) ? true : false, false));
	Sort::quicksort(arr, 0, 99);
	tests.push_back(Test("Bsearch on array when key exists",
						(Sort::bsearch(arr, 100, arr[33]) != -1) ? true : false, true));
	tests.push_back(Test("Bsearch on array when key doesn't exist",
						(Sort::bsearch(arr, 100, 200) != -1) ? true : false, false));
	int oddArr[99];
	fillArr(oddArr, 99);
	Sort::quicksort(oddArr, 0, 98);
	tests.push_back(Test("Bsearch on odd-length array when key exists",
						(Sort::bsearch(oddArr, 99, arr[54]) != -1) ? true : false, true));
	tests.push_back(Test("Bsearch on odd-length array when key doesn't exist",
						(Sort::bsearch(oddArr, 99, 200) != -1) ? true : false, false));

	// Test Bloom filter
	BloomFilter<1000, 5> bloom;
	tests.push_back(Test("Searching empty Bloom filter", bloom.contains("asdf"), false));
	bloom.insert("kjlajkl");
	tests.push_back(Test("Searching Bloom filter when value exists",
					bloom.contains("kjlajkl"), true));
	tests.push_back(Test("Searching Bloom filter for several values that exist",
					true, true));
	string inserts[5] = { "asdf", "fdsa", "I sure hope this works", "Lorem Ipsum", "lorem ipsum" };
	for (string s : inserts) {
		bloom.insert(s);
	}
	for (string s : inserts) {
		if (!bloom.contains(s)) {
			tests.back().setResult(false);
			break;
		}
	}
	for (int i = 0; i < 100; i++) {
		bloom.insert(to_string(i));
	}
	tests.push_back(Test("Searching populated Bloom filter for value that doesn't exist",
					bloom.contains("Doesn't exist"), false));
	tests.push_back(Test("Searching populated Bloom filter for numerous values that don't exist",
					false, false));
	// i needs to stay below ~20. Collisions become a problem with such a small filter
	for (int i = -1; i > -10; i--) {
		if (bloom.contains(to_string(i))) {
			tests.back().setResult(true);
			break;
		}
	}

	// Print tests
	int testsFailed = 0;
	for (Test t : tests) {
		cout << t << endl;
		if (t.getResult() != t.getExpected()) {
			testsFailed++;
		}
	}
	if (testsFailed == 0) {
		cout << endl << "All tests passed" << endl;
	} else {
		cout << endl << testsFailed << ((testsFailed > 1) ? " tests" : " test") << " failed" << endl;
	}

    return 0;
}

bool isSorted(const int arr[], int size) {
	return isSorted(arr, 0, size - 1);
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