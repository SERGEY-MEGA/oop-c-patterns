#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

typedef struct Flyweight {
    const char* key;
    void (*operation)(struct Flyweight*, int extrinsic);
} Flyweight;

typedef struct {
    Flyweight* items[10];
    int count;
} FlyweightFactory;

FlyweightFactory* flyweight_factory_create(void);
Flyweight* flyweight_factory_get(FlyweightFactory* f, const char* key);

#endif
