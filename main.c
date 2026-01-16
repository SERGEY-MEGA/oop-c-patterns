#include <stdio.h>
#include <stdlib.h>

#include "factory.h"
#include "singleton.h"
#include "stack.h"

int main() {
    Figure* f1;
    Figure* f2;
    Figure* f3;
    Figure* figures[3];

    Singleton* s1;
    Singleton* s2;

    Stack* stack;

    /* --- фигуры --- */
    f1 = figure_factory(FIGURE_SQUARE, 4, 0, 0);
    f2 = figure_factory(FIGURE_CIRCLE, 3, 0, 0);
    f3 = figure_factory(FIGURE_TRIANGLE, 3, 4, 5);

    figures[0] = f1;
    figures[1] = f2;
    figures[2] = f3;

    for (int i = 0; i < 3; i++) {
        printf(
            "Area: %.2f, Perimeter: %.2f\n",
            figures[i]->area(figures[i]),
            figures[i]->perimeter(figures[i])
        );
        free(figures[i]);
    }

    /* --- singleton --- */
    s1 = get_singleton();
    s2 = get_singleton();

    s1->value = 42;

    printf("s1 value: %d\n", s1->value);
    printf("s2 value: %d\n", s2->value);

    /* --- stack --- */
    stack = stack_create();

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    printf("\nStack pop:\n");
    while (!stack_is_empty(stack)) {
        printf("%d\n", stack_pop(stack));
    }

    return 0;
}
