#include "factory.h"

Figure* square_create(double side);
Figure* circle_create(double radius);
Figure* triangle_create(double a, double b, double c);

Figure* figure_factory(FigureType type, double a, double b, double c) {
    switch (type) {
        case FIGURE_SQUARE:
            return square_create(a);
        case FIGURE_CIRCLE:
            return circle_create(a);
        case FIGURE_TRIANGLE:
            return triangle_create(a, b, c);
        default:
            return 0;
    }
}
