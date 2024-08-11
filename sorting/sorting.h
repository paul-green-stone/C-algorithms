#ifndef C_ALGORITHMS_SORTING_H
#define C_ALGORITHMS_SORTING_H

/* ================================================================ */

extern int insertion_sort_int(int* data, int size);

extern int insertion_sort(void* data, int array_size, size_t element_size, int (*compare)(const void* data1, const void* data2));

/* ================================================================ */

#endif /* C_ALGORITHMS_SORTING_H */
