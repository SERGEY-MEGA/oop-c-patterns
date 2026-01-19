#include <stdio.h>
#include <stdlib.h>
#include "bridge.h"

/* Implementors */
void impl_a(void) { printf("Implementor A operation\n"); }
void impl_b(void) { printf("Implementor B operation\n"); }

Implementor* implementor_a_create(void) {
    Implementor* i = malloc(sizeof(Implementor));
    i->operation_impl = impl_a;
    return i;
}

Implementor* implementor_b_create(void) {
    Implementor* i = malloc(sizeof(Implementor));
    i->operation_impl = impl_b;
    return i;
}

/* Abstraction */
void abstraction_operation(Abstraction* a) {
    a->impl->operation_impl();
}

Abstraction* abstraction_create(Implementor* impl) {
    Abstraction* a = malloc(sizeof(Abstraction));
    a->impl = impl;
    a->operation = abstraction_operation;
    return a;
}
