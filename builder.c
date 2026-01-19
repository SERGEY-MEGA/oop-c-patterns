#include <stdio.h>
#include <stdlib.h>
#include "builder.h"

/* ConcreteBuilder implementation */

void build_part1_impl(Builder* b) {
    b->product->part1 = "Engine";
}

void build_part2_impl(Builder* b) {
    b->product->part2 = "Wheels";
}

void build_part3_impl(Builder* b) {
    b->product->part3 = "Doors";
}

Builder* concrete_builder_create(void) {
    Builder* b = malloc(sizeof(Builder));
    b->product = malloc(sizeof(Product));

    b->build_part1 = build_part1_impl;
    b->build_part2 = build_part2_impl;
    b->build_part3 = build_part3_impl;

    return b;
}

/* Director */

void director_construct(Director* d) {
    d->builder->build_part1(d->builder);
    d->builder->build_part2(d->builder);
    d->builder->build_part3(d->builder);
}

/* Result */

Product* builder_get_result(Builder* b) {
    return b->product;
}
