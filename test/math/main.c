#include "../../Calgs.h"
#include <assert.h>

/* ================================================================ */

int compare(int* a, int* b) {
    return *a - *b;
}

/* ================================ */

void print_array(int* array, int size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        
        if (i < size - 1) {
            printf(", ");
        }
    }
    
    printf("\n");
}

/* ================================ */

int arrays_equal(const void* data1, const void* data2, int size, size_t element_size, int (*compare)(const void*, const void*)) {
    
    const char* array1 = data1;
    const char* array2 = data2;
    
    int i = 0;
    
    for (; i < size; i++) {
        if (array1[i * element_size] != array2[i * element_size]) {
            return 0;
        }
    }
    
    return 1;
}

/* ================================ */

int main(int argc, char** argv) {

    Factors* factors = proper_trial_d(100);
    int test_array[] = {1, 2, 4, 5, 10, 20, 25, 50, 100};

    assert(sizeof(test_array) / sizeof(test_array[0]) == factors->size);
    assert(arrays_equal(factors->list, test_array, factors->size, sizeof(int), (int (*)(const void*, const void*)) compare) == 1);
    printf("proper_trial_d: \033[0;32mDONE\033[0;37m\n");

    free(factors->list);
    free(factors);
    
    return EXIT_SUCCESS;
}

/* ================================================================ */
