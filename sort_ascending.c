#include <stdio.h>
#include <stdlib.h>

typedef void (*sort_fn)(int *arr, int len);
void bubble_sort(int *, int);
void selection_sort(int *, int);

sort_fn sort_algos[] = {
    bubble_sort,
    selection_sort
};

char *sort_names[] = {"bubble_sort", "selection_sort"};
int SORT_COUNT = sizeof(sort_algos) / sizeof(*sort_algos);

void sort_ascending(int *arr, int len, int is_called_from_main) {
    int idx = rand() % SORT_COUNT;
    if (is_called_from_main)
	printf("\nUsing %s...\n", sort_names[idx]);
    sort_algos[idx](arr, len);
}

void bubble_sort(int *arr, int len) {
    char swapped;
    int i;
    for (i = 0; i < len - 1; i++) {
	swapped = 0;
	int j;
	for (j = 0; j < len - 1 - i; j++) {
	    if (arr[j] > arr[j + 1]) {
		swapped = 1;
		int temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	    }
	}
	if (swapped = 0) break;
    }
}

void selection_sort(int *arr, int len) {
    int i;
    for (i = 0; i < len - 1; i++) {
	int min_pos = i;
	int j;
	for (j = i + 1; j < len; j++) {
	    if (arr[j] < arr[min_pos]) min_pos = j;
	}

	if (min_pos != i) {
	    int temp = arr[i];
	    arr[i] = arr[min_pos];
	    arr[min_pos] = temp;
	}
    }
}
