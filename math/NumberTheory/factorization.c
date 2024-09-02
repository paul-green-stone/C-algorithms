#include "../../Calgs.h"

/* ================================================================ */

Factors* proper_trial_d(long long int n) {

    Factors* factors = NULL;
    int* list = NULL;
    size_t size = 2;

    size_t i, j;

    /* ================ */

    if ((factors = calloc(1, sizeof(Factors))) == NULL) {
        return NULL;
    }

    factors->size = 0;
    factors->error = 0;

    if (n < 0) {
        factors->error = -1;

        return factors;
    }

    if ((factors->list = calloc(size, sizeof(int))) == NULL) {
        free(factors);
        factors = NULL;

        return NULL;
    }

    for (i = 1, j = 0; i < (size_t) sqrt(n) + 1; i++) {

        if ((n % i) == 0) {

            if (j >= size) {
                size *= 2;

                if ((list = realloc(factors->list, sizeof(int) * size)) == NULL) {
                    factors->error = errno;

                    return factors;
                }

                factors->list = list;
            }

            factors->list[j++] = i;
            factors->size++;

            if (i != (n / i)) {
                factors->list[j++] = n / i;
                factors->size++;
            }
        }
    }

    if ((list = realloc(factors->list, sizeof(int) * factors->size)) == NULL) {
        factors->error = errno;

        return factors;
    }

    factors->list = list;

    insertion_sort_int(factors->list, factors->size);

    /* ======== */

    return factors;
}

/* ================================================================ */
