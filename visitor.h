#ifndef VISITOR_H
#define VISITOR_H

struct ConcreteElementA;
struct ConcreteElementB;

/* Visitor */
typedef struct Visitor {
    void (*visit_a)(struct Visitor*, struct ConcreteElementA*);
    void (*visit_b)(struct Visitor*, struct ConcreteElementB*);
} Visitor;

/* Element */
typedef struct Element {
    void (*accept)(struct Element*, Visitor*);
} Element;

/* Concrete Elements */
typedef struct ConcreteElementA {
    Element base;
    int value;
} ConcreteElementA;

typedef struct ConcreteElementB {
    Element base;
    int value;
} ConcreteElementB;

ConcreteElementA* element_a_create(int value);
ConcreteElementB* element_b_create(int value);

Visitor* visitor_create(void);

#endif
