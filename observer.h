#ifndef OBSERVER_H
#define OBSERVER_H

typedef struct Observer {
    void (*update)(int value);
} Observer;

typedef struct {
    Observer* observers[10];
    int count;
    int state;
} Subject;

Subject* subject_create(void);
void subject_attach(Subject* subject, Observer* observer);
void subject_set_state(Subject* subject, int state);

Observer* observer_create(void (*update)(int));

#endif
