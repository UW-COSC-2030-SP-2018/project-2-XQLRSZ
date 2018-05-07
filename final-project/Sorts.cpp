#include "sorts.h"


void sort::quicksort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

int sort::partition(int arr[], int low, int high) {
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

void sort::swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

static void mergesort();
static void bsearch();