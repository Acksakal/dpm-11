void print_array(int *, int);
void delete_number(int *, int *, int);
void insert_number(int *, int *, int, int);
void remove_duplicates(int *, int *);
void sort_ascending(int *, int, int);
int merge_sorted_arrays(int *, int *, int, int, int *);
int find_max(int *, int);
int find(int *, int, int);
void fill_and_sort(int *, int, int *, int);
int randint(int, int);
void take_user_input(int *arr, int *len, int initial_size);
int *malloc_int_variadic(int, ...);
typedef enum {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW
} Color;
void print_colored(Color color, char *format, ...);
void fprintf_colored(FILE *stream, Color color, char *format, ...);
