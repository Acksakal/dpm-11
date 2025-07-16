void insert_number(int *arr, int *len, int num_to_ins, int pos) {
    int i;
    if (pos != 0) pos--;
    
    for (i = *len; i > pos; i--) {
	arr[i] = arr[i - 1];
    }

    arr[pos] = num_to_ins;
    (*len)++;
}
