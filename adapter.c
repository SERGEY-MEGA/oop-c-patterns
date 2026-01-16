#include <stdlib.h>
#include "adapter.h"

/* старые функции */
double legacy_area(LegacySquare* s) {
    return s->side * s->side;
}

double legacy_perimeter(LegacySquare* s) {
    return 4 * s->side;
}

/* методы адаптера */
double adapter_area(Figure* f) {
    SquareAdapter* a = (SquareAdapter*)f;
    return legacy_area(&a->legacy);
}

double adapter_perimeter(Figure* f) {
    SquareAdapter* a = (SquareAdapter*)f;
    return legacy_perimeter(&a->legacy);
}

/* создание адаптера */
Figure* square_adapter_create(double side) {
    SquareAdapter* a = malloc(sizeof(SquareAdapter));

    a->legacy.side = side;
    a->base.area = adapter_area;
    a->base.perimeter = adapter_perimeter;

    return (Figure*)a;
}
