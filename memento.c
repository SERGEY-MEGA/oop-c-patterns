#include <stdlib.h>
#include "memento.h"

void originator_set_state(Originator* o, int state) {
    o->state = state;
}

int originator_get_state(Originator* o) {
    return o->state;
}

Memento* originator_save(Originator* o) {
    Memento* m = malloc(sizeof(Memento));
    m->state = o->state;
    return m;
}

void originator_restore(Originator* o, Memento* m) {
    o->state = m->state;
}

Originator* originator_create(void) {
    Originator* o = malloc(sizeof(Originator));
    o->state = 0;
    o->set_state = originator_set_state;
    o->get_state = originator_get_state;
    o->save = originator_save;
    o->restore = originator_restore;
    return o;
}
