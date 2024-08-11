#include "../../Calgs.h"
#include <assert.h>

/* ================================================================ */

int compare(int* a, int* b) {
    return *a < *b;
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
    
    int array[] = {1, 4, 3, 6, 11, 0, -4};
    int sorted_array[] = {-4, 0, 1, 3, 4, 6, 11};
    
    assert(sizeof(array) / sizeof(array[0]) == sizeof(sorted_array) / sizeof(sorted_array[0]));
    
    insertion_sort(array, sizeof(array) / sizeof(array[0]), sizeof(int), (int (*)(const void*, const void*)) compare);
    
    print_array(array, sizeof(array) / sizeof(array[0]));
    print_array(sorted_array, sizeof(array) / sizeof(array[0]));
    
    assert(arrays_equal(array, sorted_array, sizeof(array) / sizeof(array[0]), sizeof(int), (int (*)(const void*, const void*)) compare) == 1);
    
    return EXIT_SUCCESS;
}

/* ================================================================ */
