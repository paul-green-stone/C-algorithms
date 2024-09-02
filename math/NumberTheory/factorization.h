#ifndef C_ALGORITHMS_NUMBER_THEORY_H
#define C_ALGORITHMS_NUMBER_THEORY_H

#include "../../Calgs.h"

/* ================================================================ */

typedef struct {
    size_t size;
    int error;
    int* list;
} Factors;

/* ==================================== */

extern Factors* proper_trial_d(long long int n);

/* ================================================================ */

#endif /* C_ALGORITHMS_NUMBER_THEORY_H */
