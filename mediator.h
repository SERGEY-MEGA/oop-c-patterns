#ifndef MEDIATOR_H
#define MEDIATOR_H

struct Colleague;

typedef struct Mediator {
    void (*send)(struct Mediator*, const char* msg, struct Colleague* sender);
} Mediator;

typedef struct Colleague {
    Mediator* mediator;
    const char* name;
    void (*send)(struct Colleague*, const char* msg);
    void (*receive)(struct Colleague*, const char* msg);
} Colleague;

Mediator* mediator_create(void);
Colleague* colleague_create(const char* name, Mediator* mediator);

#endif
