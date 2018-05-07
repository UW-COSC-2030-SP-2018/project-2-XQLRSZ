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
	for (int j = low; j < high - 1; j++) {
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
	if (high > low) {
		int mid = (low + high) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void Sort::merge(int arr[], int low, int mid, int high) {
	int size1 = mid - low + 1;
	int size2 = high - mid;
	int i = size1, j = size2, k = low;
	while (i < size1 && j < size2) {
		if (arr[i] <= arr[j]) {
			arr[k] = arr[i];
			i++;
		}
		else {
			arr[k] = arr[j];
			j++;
		}
		k++;
	}
}

int Sort::bsearch(int arr[], int size, int key) {
	bsearch(arr, 0, size - 1, key);
}

int Sort::bsearch(int arr[], int low, int high, int key) {
	int mid = (high + low) / 2;

	if (mid < key) {
		return bsearch(arr, low, mid, key);
	} else {
		return bsearch(arr, mid + 1, high, key);
	}

	if (mid == key) {
		return mid;
	} else if (mid == 0) {
		return -1;
	}
}