#include "../Calgs.h"

/* ================================================================ */

int insertion_sort_int(int* data, int size) {
    
    int* array = data;
    int key;
    int i, j;
    
    array = data;
    
    /* ================ */
    
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        
        while ((j >= 0) && (array[j] > key)) {
            array[j + 1] = array[j];
            
            j--;
        }
        
        array[j + 1] = key;
    }
    
    /* ======== */
    
    return 0;
}

/* ================================================================ */

int insertion_sort(void* data, int array_size, size_t element_size, int (*compare)(const void* data1, const void* data2)) {
    
    char* temporary = NULL;
    char* array = data;
    int i, j;
    
    /* ================ */
    
    /* Allocate space for the temporary variable */
    if ((temporary = (char*) calloc(1, element_size)) == NULL) {
        return EXIT_FAILURE;
    }
    
    /* Repeatedly insert a temporary element among the sorted elements */
    for (i = 1; i < array_size; i++) {
        
        /* Copy the current element from the unsorted portion of the array into a temporary variable */
        memcpy(temporary, &array[i * element_size], element_size);
        
        j = i - 1;
        
        /* Determine the position at which to insert the temporary element */
        while ((j >= 0) && (compare(temporary, &array[j * element_size]) > 0)) {
            
            memcpy(&array[(j + 1) * element_size], &array[j * element_size], element_size);
            
            j--;
        }
        
        memcpy(&array[(j + 1) * element_size], temporary, element_size);
    }
    
    /* Free the memory occupied by the temporary variable */
    free(temporary);
    
    /* ======== */
    
    return EXIT_SUCCESS;
}

/* ================================================================ */
