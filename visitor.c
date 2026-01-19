#include <stdio.h>
#include <stdlib.h>
#include "visitor.h"

/* ===== Elements ===== */

void element_a_accept(Element* e, Visitor* v) {
    v->visit_a(v, (ConcreteElementA*)e);
}

void element_b_accept(Element* e, Visitor* v) {
    v->visit_b(v, (ConcreteElementB*)e);
}

ConcreteElementA* element_a_create(int value) {
    ConcreteElementA* a = malloc(sizeof(ConcreteElementA));
    a->value = value;
    a->base.accept = element_a_accept;
    return a;
}

ConcreteElementB* element_b_create(int value) {
    ConcreteElementB* b = malloc(sizeof(ConcreteElementB));
    b->value = value;
    b->base.accept = element_b_accept;
    return b;
}

/* ===== Visitor ===== */

typedef struct {
    Visitor base;
} ConcreteVisitor;

void visit_a(Visitor* v, ConcreteElementA* a) {
    printf("Visiting ElementA, value = %d\n", a->value);
}

void visit_b(Visitor* v, ConcreteElementB* b) {
    printf("Visiting ElementB, value = %d\n", b->value);
}

Visitor* visitor_create(void) {
    ConcreteVisitor* v = malloc(sizeof(ConcreteVisitor));
    v->base.visit_a = visit_a;
    v->base.visit_b = visit_b;
    return (Visitor*)v;
}
