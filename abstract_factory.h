#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

/* Abstract products */
typedef struct {
    void (*use)(void);
} ProductA;

typedef struct {
    void (*use)(void);
} ProductB;

/* Abstract factory */
typedef struct AbstractFactory {
    ProductA* (*create_product_a)(void);
    ProductB* (*create_product_b)(void);
} AbstractFactory;

/* Factories */
AbstractFactory* factory_a_create(void);
AbstractFactory* factory_b_create(void);

#endif
