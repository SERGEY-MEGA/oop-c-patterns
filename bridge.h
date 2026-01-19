#ifndef BRIDGE_H
#define BRIDGE_H

/* Implementor */
typedef struct Implementor {
    void (*operation_impl)(void);
} Implementor;

/* Forward declaration */
struct Abstraction;

/* Abstraction */
typedef struct Abstraction {
    Implementor* impl;
    void (*operation)(struct Abstraction*);
} Abstraction;

/* Factories */
Implementor* implementor_a_create(void);
Implementor* implementor_b_create(void);

Abstraction* abstraction_create(Implementor* impl);

#endif
