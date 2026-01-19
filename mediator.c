#include <stdio.h>
#include <stdlib.h>
#include "mediator.h"

#define MAX_COLLEAGUES 10

void colleague_send(Colleague* c, const char* msg);


typedef struct {
    Mediator base;
    Colleague* colleagues[MAX_COLLEAGUES];
    int count;
} ConcreteMediator;

void colleague_receive(Colleague* c, const char* msg) {
    printf("[%s] received: %s\n", c->name, msg);
}

void mediator_send(Mediator* m, const char* msg, Colleague* sender) {
    ConcreteMediator* cm = (ConcreteMediator*)m;
    for (int i = 0; i < cm->count; i++) {
        if (cm->colleagues[i] != sender) {
            cm->colleagues[i]->receive(cm->colleagues[i], msg);
        }
    }
}

Mediator* mediator_create(void) {
    ConcreteMediator* m = malloc(sizeof(ConcreteMediator));
    m->base.send = mediator_send;
    m->count = 0;
    return (Mediator*)m;
}

Colleague* colleague_create(const char* name, Mediator* mediator) {
    Colleague* c = malloc(sizeof(Colleague));
    c->name = name;
    c->mediator = mediator;
    c->send = colleague_send;
    c->receive = colleague_receive;

    ConcreteMediator* cm = (ConcreteMediator*)mediator;
    cm->colleagues[cm->count++] = c;

    return c;
}

/* send implementation */
void colleague_send(Colleague* c, const char* msg) {
    c->mediator->send(c->mediator, msg, c);
}
