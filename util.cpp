#include "util.h"

void print_arr(void *data, size_t num_elem) {
    char *d = (char*) data;
    for (int i = 0; i < num_elem; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
}
