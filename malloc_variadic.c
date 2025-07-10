#include <stdarg.h>
#include <stdlib.h>

int *alloc_int_array(int count, ...) {
    int total_size = 0;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int size = va_arg(args, int);
        total_size += size;
    }

    va_end(args);

    int *merged = malloc(total_size * sizeof(int));
    return merged;
}
