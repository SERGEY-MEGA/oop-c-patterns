#ifndef COMPOSITE_H
#define COMPOSITE_H

/* Base interface */
typedef struct CompositeComponent {
    int (*operation)(struct CompositeComponent*);
} CompositeComponent;

/* Leaf */
typedef struct {
    CompositeComponent base;
    int value;
} Leaf;

CompositeComponent* leaf_create(int value);

/* Composite */
typedef struct {
    CompositeComponent base;
    CompositeComponent* children[10];
    int count;
} Composite;

CompositeComponent* composite_create(void);
void composite_add(Composite* c, CompositeComponent* child);

#endif
