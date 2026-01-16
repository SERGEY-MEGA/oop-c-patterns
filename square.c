#include <stdlib.h>
#include "figure.h"

typedef struct {
    Figure base;
    double side;
} Square;

double square_area(Figure* f) {
    Square* s = (Square*)f;
    return s->side * s->side;
}

double square_perimeter(Figure* f) {
    Square* s = (Square*)f;
    return 4 * s->side;
}

Figure* square_create(double side) {
    Square* s = malloc(sizeof(Square));
    s->side = side;
    s->base.area = square_area;
    s->base.perimeter = square_perimeter;
    return (Figure*)s;
}
