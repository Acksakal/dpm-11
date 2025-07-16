#include <stdlib.h>

int randint(int lower, int higher) {
    return (rand() % (higher - lower)) + lower;
}
