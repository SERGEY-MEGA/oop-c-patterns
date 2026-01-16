#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

Stack* stack_create(void);
void stack_push(Stack* stack, int value);
int stack_pop(Stack* stack);
int stack_is_empty(Stack* stack);

#endif
