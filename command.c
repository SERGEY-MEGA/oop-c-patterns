#include <stdio.h>
#include <stdlib.h>
#include "command.h"

/* Receiver logic */
void receiver_action(void) {
    printf("Receiver: action executed\n");
}

Receiver* receiver_create(void (*action)(void)) {
    Receiver* r = malloc(sizeof(Receiver));
    r->action = action;
    return r;
}

/* Command logic */
void command_execute(Command* c) {
    ConcreteCommand* cc = (ConcreteCommand*)c;
    cc->receiver->action();
}

Command* command_create(Receiver* receiver) {
    ConcreteCommand* cc = malloc(sizeof(ConcreteCommand));
    cc->receiver = receiver;
    cc->base.execute = command_execute;
    return (Command*)cc;
}

/* Invoker logic */
Invoker* invoker_create(Command* command) {
    Invoker* i = malloc(sizeof(Invoker));
    i->command = command;
    return i;
}

void invoker_invoke(Invoker* invoker) {
    invoker->command->execute(invoker->command);
}
