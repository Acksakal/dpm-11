#include <stdlib.h>

void sort_ascending(int *, int, int);

void fill_and_sort(int *arr1, int len1, int *arr2, int len2) {
    for (int i = 0; i < len1; i++) {
	arr1[i] = rand() % 255;
    }
    sort_ascending(arr1, len1, 0);

    for (int j = 0; j < len2; j++) {
	arr2[j] = rand() % 255;
    }
    sort_ascending(arr2, len2, 0);
}
