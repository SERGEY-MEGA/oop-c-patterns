#include <stdio.h>
#include <stdlib.h>
#include "observer.h"

Subject* subject_create(void) {
    Subject* s = malloc(sizeof(Subject));
    s->count = 0;
    s->state = 0;
    return s;
}

void subject_attach(Subject* subject, Observer* observer) {
    subject->observers[subject->count++] = observer;
}

void subject_set_state(Subject* subject, int state) {
    subject->state = state;
    for (int i = 0; i < subject->count; i++) {
        subject->observers[i]->update(state);
    }
}

Observer* observer_create(void (*update)(int)) {
    Observer* o = malloc(sizeof(Observer));
    o->update = update;
    return o;
}
