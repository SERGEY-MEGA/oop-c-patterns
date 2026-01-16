#include <stdlib.h>
#include <math.h>
#include "figure.h"

typedef struct {
    Figure base;
    double a, b, c;
} Triangle;

double triangle_perimeter(Figure* f) {
    Triangle* t = (Triangle*)f;
    return t->a + t->b + t->c;
}

double triangle_area(Figure* f) {
    Triangle* t = (Triangle*)f;
    double p = triangle_perimeter(f) / 2;
    return sqrt(p * (p - t->a) * (p - t->b) * (p - t->c));
}

Figure* triangle_create(double a, double b, double c) {
    Triangle* t = malloc(sizeof(Triangle));
    t->a = a;
    t->b = b;
    t->c = c;
    t->base.area = triangle_area;
    t->base.perimeter = triangle_perimeter;
    return (Figure*)t;
}
