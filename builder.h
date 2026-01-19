#ifndef BUILDER_H
#define BUILDER_H

typedef struct {
    const char* part1;
    const char* part2;
    const char* part3;
} Product;

typedef struct Builder {
    void (*build_part1)(struct Builder*);
    void (*build_part2)(struct Builder*);
    void (*build_part3)(struct Builder*);
    Product* product;
} Builder;

typedef struct {
    Builder* builder;
} Director;

Builder* concrete_builder_create(void);
void director_construct(Director* d);

Product* builder_get_result(Builder* b);

#endif
