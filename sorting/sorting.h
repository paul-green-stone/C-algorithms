#ifndef C_ALGORITHMS_SORTING_H
#define C_ALGORITHMS_SORTING_H

/* ================================================================ */

extern int insertion_sort_int(int* data, int size);

/* ================================ */

extern int insertion_sort(void* data, int size, size_t element_size, int (*compare)(const void* data1, const void* data2));

/* ================================ */

/*
 * Uses quicksort to sort the array of elements in `data` The number of elements in `data` is specified by `size`.
 * The size of each element is specified by `element_size`. The arguments `i` and `k` define the current partition
 * being sorted and initially should be 0 and `size - 1`, respectively. The function pointer `compare` specifies a user-defined
 * function to compare elements. When `quicksortz returns, `data` contains the sorted elements.
 *
 * @return 0 if sorting is succesfull, or -1 otherwise.
*/
extern int quicksort(void* data, int size, size_t element_size, int i, int k, int (*compare)(const void*, const void*));

/* ================================================================ */

#endif /* C_ALGORITHMS_SORTING_H */
