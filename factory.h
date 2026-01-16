#ifndef FACTORY_H
#define FACTORY_H

#include "figure.h"

typedef enum {
    FIGURE_SQUARE,
    FIGURE_CIRCLE,
    FIGURE_TRIANGLE
} FigureType;

Figure* figure_factory(FigureType type, double a, double b, double c);

#endif
