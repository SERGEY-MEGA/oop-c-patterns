#include <stdlib.h>
#include "figure.h"

typedef struct {
    Figure base;
    double radius;
} Circle;

double circle_area(Figure* f) {
    Circle* c = (Circle*)f;
    return 3.14159 * c->radius * c->radius;
}

double circle_perimeter(Figure* f) {
    Circle* c = (Circle*)f;
    return 2 * 3.14159 * c->radius;
}

Figure* circle_create(double radius) {
    Circle* c = malloc(sizeof(Circle));
    c->radius = radius;
    c->base.area = circle_area;
    c->base.perimeter = circle_perimeter;
    return (Figure*)c;
}
