#include "Sorts.h"

void Sort::quicksort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

int Sort::partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, high);
	return i + 1;
}

void Sort::swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void Sort::mergesort(int arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void Sort::merge(int arr[], int low, int mid, int high) {
	// Length of left and right subarrays
	int n1 = mid - low + 1;
	int n2 = high - mid;

	// Temp arrays, allocated to avoid non-constant array lengths
	int* left = new int[n1];
	int* right = new int[n2];

	for (int i = 0; i < n1; i++) {
		left[i] = arr[low + i];
	}
	for (int j = 0; j < n2; j++) {
		right[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0;
	int k = low;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
	delete[] left;
	delete[] right;
}

int Sort::bsearch(int arr[], int size, int key) {
	return bsearch(arr, 0, size - 1, key);
}

int Sort::bsearch(int arr[], int low, int high, int key) {
	if (high >= low) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == key) {
			return mid;
		}

		if (arr[mid] > key) {
			return bsearch(arr, low, mid - 1, key);
		} else {
			return bsearch(arr, mid + 1, high, key);
		}
	}
	return -1;
}