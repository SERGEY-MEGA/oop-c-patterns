#ifndef SINGLETON_H
#define SINGLETON_H

typedef struct {
    int value;
} Singleton;

Singleton* get_singleton(void);

#endif
