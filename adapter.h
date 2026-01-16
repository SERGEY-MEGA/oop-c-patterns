#ifndef ADAPTER_H
#define ADAPTER_H

#include "figure.h"

/* старый код */
typedef struct {
    double side;
} LegacySquare;

/* адаптер */
typedef struct {
    Figure base;          /* важно: ПЕРВЫМ */
    LegacySquare legacy;
} SquareAdapter;

Figure* square_adapter_create(double side);

#endif
