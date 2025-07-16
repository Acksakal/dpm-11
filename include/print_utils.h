#define PRINT_ARRAY(arr, length)                                           \
    do {                                                                   \
        size_t __i;                                                        \
        printf("The first array => %s: [", #arr);                          \
        for (__i = 0; __i < (length); __i++) {                             \
            printf("%d%s", (arr)[__i], __i < (length) - 1 ? ", " : "]");   \
        }                                                                  \
        printf("\n");                                                      \
    } while (0)

#define PRINT_SECOND_ARRAY(arr, length)                                    \
    do {                                                                   \
        size_t __j;                                                        \
        printf("The other array => %s: [", #arr);                          \
        for (__j = 0; __j < (length); __j++) {                             \
            printf("%d%s", (arr)[__j], __j < (length) - 1 ? ", " : "]");   \
        }                                                                  \
        printf("\n");                                                      \
    } while (0)

#define PRINT_MERGED_ARRAY(arr, length)                                    \
    do {                                                                   \
        size_t __k;                                                        \
        printf("The merged array => %s: [", #arr);                         \
        for (__k = 0; __k < (length); __k++) {                             \
            printf("%d%s", (arr)[__k], __k < (length) - 1 ? ", " : "]");   \
        }                                                                  \
        printf("\n");                                                      \
    } while (0)

#define PRINT_RANDOM_ARRAY(arr, length)                                    \
    do {                                                                   \
        size_t __n;                                                        \
        printf("The random array => %s: [", #arr);                         \
        for (__n = 0; __n < (length); __n++) {                             \
            printf("%d%s", (arr)[__n], __n < (length) - 1 ? ", " : "]");   \
        }                                                                  \
        printf("\n");                                                      \
    } while (0)
