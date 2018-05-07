#ifndef SORTS_H
#define SORTS_H
class Sort {
public:
	static void quicksort(int arr[], int low, int high);
	static void mergesort();
	static void bsearch();
private:
	static int partition(int arr[], int low, int high);
	static void swap(int arr[], int a, int b);
	static void msort(int arr);
};

#endif // !SORTS_H
