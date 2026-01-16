#include <stdlib.h>
#include "stack.h"

Stack* stack_create(void) {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = 0;
    return stack;
}

void stack_push(Stack* stack, int value) {
    StackNode* node = malloc(sizeof(StackNode));
    node->value = value;
    node->next = stack->top;
    stack->top = node;
}

int stack_pop(Stack* stack) {
    if (stack->top == 0) {
        return -1;
    }

    StackNode* temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

int stack_is_empty(Stack* stack) {
    return stack->top == 0;
}
