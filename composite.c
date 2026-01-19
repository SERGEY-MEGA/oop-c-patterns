#include <stdlib.h>
#include "composite.h"

/* Leaf */
int leaf_operation(CompositeComponent* c) {
    Leaf* l = (Leaf*)c;
    return l->value;
}

CompositeComponent* leaf_create(int value) {
    Leaf* l = malloc(sizeof(Leaf));
    l->value = value;
    l->base.operation = leaf_operation;
    return (CompositeComponent*)l;
}

/* Composite */
int composite_operation(CompositeComponent* c) {
    Composite* comp = (Composite*)c;
    int sum = 0;
    for (int i = 0; i < comp->count; i++) {
        sum += comp->children[i]->operation(comp->children[i]);
    }
    return sum;
}

CompositeComponent* composite_create(void) {
    Composite* c = malloc(sizeof(Composite));
    c->count = 0;
    c->base.operation = composite_operation;
    return (CompositeComponent*)c;
}

void composite_add(Composite* c, CompositeComponent* child) {
    c->children[c->count++] = child;
}
