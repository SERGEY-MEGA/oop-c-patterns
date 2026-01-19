#include <stdlib.h>
#include "iterator.h"

Aggregate* aggregate_create(int* items, int size) {
    Aggregate* a = malloc(sizeof(Aggregate));
    a->items = items;
    a->size = size;
    return a;
}

Iterator* iterator_create(Aggregate* aggregate) {
    Iterator* it = malloc(sizeof(Iterator));
    it->aggregate = aggregate;
    it->index = 0;
    return it;
}

int iterator_has_next(Iterator* it) {
    return it->index < it->aggregate->size;
}

int iterator_next(Iterator* it) {
    return it->aggregate->items[it->index++];
}
