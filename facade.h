#ifndef FACADE_H
#define FACADE_H

typedef struct {
    void (*start)(void);
    void (*stop)(void);
} SubsystemA;

typedef struct {
    void (*on)(void);
    void (*off)(void);
} SubsystemB;

typedef struct {
    SubsystemA* a;
    SubsystemB* b;
} Facade;

Facade* facade_create(void);
void facade_start_system(Facade* f);
void facade_stop_system(Facade* f);

#endif
