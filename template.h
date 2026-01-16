#ifndef TEMPLATE_H
#define TEMPLATE_H

typedef struct Template {
    void (*step1)(void);
    void (*step2)(void);
} Template;

void template_execute(Template* t);

Template* template_a(void);
Template* template_b(void);

#endif
