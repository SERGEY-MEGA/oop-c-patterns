#include "adapter.h"
#include "template.h"
#include <stdio.h>
#include <stdlib.h>

#include "factory.h"
#include "singleton.h"
#include "stack.h"
#include "observer.h"

/* ===== Observer callback ===== */
void print_observer(int value) {
    printf("Observer notified, new value: %d\n", value);
}

int main() {
    /* ===== Figures (ООП + Factory) ===== */
    Figure* f1;
    Figure* f2;
    Figure* f3;
    Figure* figures[3];

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

    /* ===== Singleton ===== */
    Singleton* s1 = get_singleton();
    Singleton* s2 = get_singleton();

    s1->value = 42;

    printf("s1 value: %d\n", s1->value);
    printf("s2 value: %d\n", s2->value);

    /* ===== Stack ===== */
    Stack* stack = stack_create();

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    printf("\nStack pop:\n");
    while (!stack_is_empty(stack)) {
        printf("%d\n", stack_pop(stack));
    }

    /* ===== Observer ===== */
    Subject* subject = subject_create();
    Observer* obs1 = observer_create(print_observer);
    Observer* obs2 = observer_create(print_observer);

    subject_attach(subject, obs1);
    subject_attach(subject, obs2);

    printf("\nObserver demo:\n");
    subject_set_state(subject, 100);
    subject_set_state(subject, 200);
Template* t1 = template_a();
Template* t2 = template_b();

printf("\nTemplate Method demo:\n");
template_execute(t1);
template_execute(t2);
Figure* adapted = square_adapter_create(5);

printf("\nAdapter demo:\n");
printf(
    "Area: %.2f, Perimeter: %.2f\n",
    adapted->area(adapted),
    adapted->perimeter(adapted)
);

free(adapted);
    return 0;
}
