#ifndef SORTS_H
#define SORTS_H

// This should probably be a namespace but I don't know how to hide helper functions with them
class Sort {
public:
	static void quicksort(int arr[], int low, int high);
	static void mergesort(int arr[], int low, int high);
	static int bsearch(int arr[], int size, int key);
private:
	Sort() {} // Do not allow instances of this class
	static int partition(int arr[], int low, int high);
	static void swap(int arr[], int a, int b);
	static void merge(int arr[], int low, int mid, int high);
	static int bsearch(int arr[], int low, int high, int key);
};

#endif // !SORTS_H
