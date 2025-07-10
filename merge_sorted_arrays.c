int merge_sorted_arrays(int *arr1, int *arr2, int arr1_len, int arr2_len, int *merged) {
    int i = 0, j = 0, k = 0;
    while (i < arr1_len && j < arr2_len) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < arr1_len) merged[k++] = arr1[i++];
    while (j < arr2_len) merged[k++] = arr2[j++];

    return k;
}
