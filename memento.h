#ifndef MEMENTO_H
#define MEMENTO_H

typedef struct Memento {
    int state;
} Memento;

typedef struct Originator {
    int state;
    void (*set_state)(struct Originator*, int);
    int (*get_state)(struct Originator*);
    Memento* (*save)(struct Originator*);
    void (*restore)(struct Originator*, Memento*);
} Originator;

Originator* originator_create(void);

#endif
