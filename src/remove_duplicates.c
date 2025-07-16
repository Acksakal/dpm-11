void delete_number(int *, int *, int);
void sort_ascending(int *, int, int);

void remove_duplicates(int *arr, int *len) {
    int i;
    for (i = 0; i < *len - 1; i++) {	
	int j;
	for (j = i + 1; j < *len; j++) {	 
	    if (arr[j] == arr[i]) {
		delete_number(arr, len, arr[j]);
	    }
	}
    }
    sort_ascending(arr, *len, 0); /* 0 means that the caller is not main */
}
