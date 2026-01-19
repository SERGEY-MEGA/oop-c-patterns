#include <stdio.h>
#include <stdlib.h>
#include "decorator.h"

/* Base operation */
int component_operation(Component* c) {
    (void)c;
    return 10;
}

Component* component_create(void) {
    Component* c = malloc(sizeof(Component));
    c->operation = component_operation;
    return c;
}

/* Decorator operation */
int decorator_operation(Component* c) {
    Decorator* d = (Decorator*)c;
    int result = d->wrappee->operation(d->wrappee);
    return result + 5;
}

Component* decorator_create(Component* wrappee) {
    Decorator* d = malloc(sizeof(Decorator));
    d->wrappee = wrappee;
    d->base.operation = decorator_operation;
    return (Component*)d;
}
