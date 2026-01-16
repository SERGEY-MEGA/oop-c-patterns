#include <stdio.h>
#include <stdlib.h>
#include "template.h"

/* общий алгоритм */
void template_execute(Template* t) {
    printf("Start algorithm\n");
    t->step1();
    t->step2();
    printf("End algorithm\n");
}

/* варианты шагов */
void a_step1(void) { printf("A: step 1\n"); }
void a_step2(void) { printf("A: step 2\n"); }

void b_step1(void) { printf("B: step 1\n"); }
void b_step2(void) { printf("B: step 2\n"); }

Template* template_a(void) {
    Template* t = malloc(sizeof(Template));
    t->step1 = a_step1;
    t->step2 = a_step2;
    return t;
}

Template* template_b(void) {
    Template* t = malloc(sizeof(Template));
    t->step1 = b_step1;
    t->step2 = b_step2;
    return t;
}
