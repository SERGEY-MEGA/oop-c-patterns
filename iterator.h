#ifndef ITERATOR_H
#define ITERATOR_H

typedef struct {
    int* items;
    int size;
} Aggregate;

typedef struct {
    Aggregate* aggregate;
    int index;
} Iterator;

Aggregate* aggregate_create(int* items, int size);
Iterator* iterator_create(Aggregate* aggregate);

int iterator_has_next(Iterator* it);
int iterator_next(Iterator* it);

#endif
