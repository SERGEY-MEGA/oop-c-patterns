#include <stdlib.h>
#include "singleton.h"

static Singleton* instance = 0;

Singleton* get_singleton(void) {
    if (instance == 0) {
        instance = malloc(sizeof(Singleton));
        instance->value = 0;
    }
    return instance;
}
