#include <stdio.h>
#include <stdlib.h>
#include "state.h"

void state_a_handle(Context* ctx);
void state_b_handle(Context* ctx);

State* state_a_create(void) {
    State* s = malloc(sizeof(State));
    s->handle = state_a_handle;
    return s;
}

State* state_b_create(void) {
    State* s = malloc(sizeof(State));
    s->handle = state_b_handle;
    return s;
}

Context* context_create(State* initial) {
    Context* c = malloc(sizeof(Context));
    c->state = initial;
    return c;
}

void context_request(Context* ctx) {
    ctx->state->handle(ctx);
}

void state_a_handle(Context* ctx) {
    printf("State A: handling, switching to State B\n");
    ctx->state = state_b_create();
}

void state_b_handle(Context* ctx) {
    printf("State B: handling, switching to State A\n");
    ctx->state = state_a_create();
}
