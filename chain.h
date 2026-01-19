#ifndef CHAIN_H
#define CHAIN_H

typedef struct Handler {
    void (*handle)(struct Handler*, int request);
    struct Handler* next;
    int limit;
} Handler;

Handler* handler_create(int limit);
void handler_set_next(Handler* h, Handler* next);
void handler_handle(Handler* h, int request);

#endif
