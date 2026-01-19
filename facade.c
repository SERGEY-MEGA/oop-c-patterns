#include <stdio.h>
#include <stdlib.h>
#include "facade.h"

/* Подсистемы */
void subsystem_a_start(void) { printf("Subsystem A started\n"); }
void subsystem_a_stop(void)  { printf("Subsystem A stopped\n"); }

void subsystem_b_on(void)  { printf("Subsystem B on\n"); }
void subsystem_b_off(void) { printf("Subsystem B off\n"); }

SubsystemA* subsystem_a_create(void) {
    SubsystemA* a = malloc(sizeof(SubsystemA));
    a->start = subsystem_a_start;
    a->stop = subsystem_a_stop;
    return a;
}

SubsystemB* subsystem_b_create(void) {
    SubsystemB* b = malloc(sizeof(SubsystemB));
    b->on = subsystem_b_on;
    b->off = subsystem_b_off;
    return b;
}

/* Facade */
Facade* facade_create(void) {
    Facade* f = malloc(sizeof(Facade));
    f->a = subsystem_a_create();
    f->b = subsystem_b_create();
    return f;
}

void facade_start_system(Facade* f) {
    f->a->start();
    f->b->on();
}

void facade_stop_system(Facade* f) {
    f->b->off();
    f->a->stop();
}
