#include <stdio.h>
#include <stdlib.h>
#include "chain.h"

void handler_handle_impl(Handler* h, int request) {
    if (request <= h->limit) {
        printf("Handler with limit %d handled request %d\n", h->limit, request);
    } else if (h->next != 0) {
        h->next->handle(h->next, request);
    } else {
        printf("No handler could handle request %d\n", request);
    }
}

Handler* handler_create(int limit) {
    Handler* h = malloc(sizeof(Handler));
    h->limit = limit;
    h->next = 0;
    h->handle = handler_handle_impl;
    return h;
}

void handler_set_next(Handler* h, Handler* next) {
    h->next = next;
}

void handler_handle(Handler* h, int request) {
    h->handle(h, request);
}
