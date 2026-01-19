#ifndef DECORATOR_H
#define DECORATOR_H

/* Component */
typedef struct Component {
    int (*operation)(struct Component*);
} Component;

/* ConcreteComponent */
Component* component_create(void);

/* Decorator */
typedef struct {
    Component base;
    Component* wrappee;
} Decorator;

Component* decorator_create(Component* wrappee);

#endif
