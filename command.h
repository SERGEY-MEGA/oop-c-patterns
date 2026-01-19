#ifndef COMMAND_H
#define COMMAND_H

/* Receiver */
typedef struct {
    void (*action)(void);
} Receiver;

/* Command */
typedef struct Command {
    void (*execute)(struct Command*);
} Command;

/* ConcreteCommand */
typedef struct {
    Command base;
    Receiver* receiver;
} ConcreteCommand;

/* Invoker */
typedef struct {
    Command* command;
} Invoker;

Receiver* receiver_create(void (*action)(void));
Command* command_create(Receiver* receiver);
Invoker* invoker_create(Command* command);

void invoker_invoke(Invoker* invoker);

/* ← ВОТ ЭТА СТРОКА */
void receiver_action(void);

#endif
