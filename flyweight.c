#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flyweight.h"

void flyweight_operation(Flyweight* f, int extrinsic) {
    printf("Flyweight [%s] with extrinsic state %d\n", f->key, extrinsic);
}

Flyweight* flyweight_create(const char* key) {
    Flyweight* f = malloc(sizeof(Flyweight));
    f->key = key;
    f->operation = flyweight_operation;
    return f;
}

FlyweightFactory* flyweight_factory_create(void) {
    FlyweightFactory* f = malloc(sizeof(FlyweightFactory));
    f->count = 0;
    return f;
}

Flyweight* flyweight_factory_get(FlyweightFactory* f, const char* key) {
    for (int i = 0; i < f->count; i++) {
        if (strcmp(f->items[i]->key, key) == 0) {
            return f->items[i];
        }
    }

    Flyweight* fw = flyweight_create(key);
    f->items[f->count++] = fw;
    return fw;
}
