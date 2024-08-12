#include "../Calgs.h"

/* ================================================================ */
/* ============================ STATIC ============================ */
/* ================================================================ */

static int partition(void* data, int element_size, int i, int k, int (*compare)(const void*, const void*)) {
    
    char* array = data;
    
    void* partition_value = NULL;
    void* temp = NULL;
    
    int r[3];
    
    /* ================ */
    
    /* Allocate storage for the partition value and swapping */
    if ((partition_value = calloc(1, element_size)) == NULL) {
        return -1;
    }
    
    if ((temp = calloc(1, element_size)) == NULL) {
            
        free(partition_value);
        
        return -1;
    }
    
    /* Use the median-of-three method to find the partition value */
    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;
    
    insertion_sort_int(r, 3);
    
    memcpy(partition_value, &array[r[1] * element_size], element_size); 
    
    /* Create two partitions around the partition value */
    i--;
    k++;
    
    while (1) {
        
        /* Move left until an element is found in the wrong partition */
        do {
            k--;
        } while (compare(&array[k * element_size], partition_value) > 0);
        
        /* Move right until an element is found in the wrong partition */
        do {
            i++;
        } while (compare(&array[i * element_size], partition_value) < 0);
        
        if (i >= k) {
            /* Stop partitioning when the left and right counters cross */
            break ;
        }
        else {
            /* Swap the elements now under the left and right counters */
            memcpy(temp, &array[i * element_size], element_size);
            memcpy(&array[i * element_size], &array[k * element_size], element_size);
            memcpy(&array[k * element_size], temp, element_size);
        }
    }
    
    /* Free the storage allocated for partitioning */
    free(partition_value);
    free(temp);
    
    /* Return the position dividing the two partitions */
    return k;
}

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
        while ((j >= 0) && (compare(temporary, &array[j * element_size]) < 0)) {
            
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

int quicksort(void* data, int size, size_t element_size, int i, int k, int (*compare)(const void*, const void*)) {
    
    int j;
    
    /* Stop the recursion when it is not possible to partition further */
    while (i < k) {
        
        /* Determine where to partition the elements */
        if ((j = partition(data, element_size, i, k, compare)) < 0) {
            return -1;
        }
        
        /* Recursively sort the left partition */
        if (quicksort(data, size, element_size, i, j, compare) < 0) {
            return -1;
        }
        
        /* Iterate and sort the right partition */
        i = j + 1;
    }
    
    return 0;
}

/* ================================================================ */
