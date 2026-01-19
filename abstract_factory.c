#include <stdio.h>
#include <stdlib.h>
#include "abstract_factory.h"

/* ===== Products A ===== */
void product_a1_use(void) { printf("Using ProductA1\n"); }
void product_a2_use(void) { printf("Using ProductA2\n"); }

ProductA* product_a1_create(void) {
    ProductA* p = malloc(sizeof(ProductA));
    p->use = product_a1_use;
    return p;
}

ProductA* product_a2_create(void) {
    ProductA* p = malloc(sizeof(ProductA));
    p->use = product_a2_use;
    return p;
}

/* ===== Products B ===== */
void product_b1_use(void) { printf("Using ProductB1\n"); }
void product_b2_use(void) { printf("Using ProductB2\n"); }

ProductB* product_b1_create(void) {
    ProductB* p = malloc(sizeof(ProductB));
    p->use = product_b1_use;
    return p;
}

ProductB* product_b2_create(void) {
    ProductB* p = malloc(sizeof(ProductB));
    p->use = product_b2_use;
    return p;
}

/* ===== Factories ===== */
AbstractFactory* factory_a_create(void) {
    AbstractFactory* f = malloc(sizeof(AbstractFactory));
    f->create_product_a = product_a1_create;
    f->create_product_b = product_b1_create;
    return f;
}

AbstractFactory* factory_b_create(void) {
    AbstractFactory* f = malloc(sizeof(AbstractFactory));
    f->create_product_a = product_a2_create;
    f->create_product_b = product_b2_create;
    return f;
}
