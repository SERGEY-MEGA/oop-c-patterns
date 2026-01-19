#ifndef STATE_H
#define STATE_H

struct State;

typedef struct {
    struct State* state;
} Context;

typedef struct State {
    void (*handle)(Context*);
} State;

Context* context_create(State* initial);
void context_request(Context* ctx);

State* state_a_create(void);
State* state_b_create(void);

#endif
