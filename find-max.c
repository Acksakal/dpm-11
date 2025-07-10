int find_max(int *arr, int len) {
    int max = -1;
    for (int i = 0; i < len; i++) {
	if (arr[i] > max) max = arr[i];
    }
    return max;
}
