#include <stdlib.h>
#include "interpreter.h"

/* Number */
typedef struct {
    Expression base;
    int value;
} NumberExpression;

int number_interpret(Expression* e) {
    NumberExpression* n = (NumberExpression*)e;
    return n->value;
}

Expression* number_expression_create(int value) {
    NumberExpression* n = malloc(sizeof(NumberExpression));
    n->value = value;
    n->base.interpret = number_interpret;
    return (Expression*)n;
}

/* Add */
typedef struct {
    Expression base;
    Expression* left;
    Expression* right;
} AddExpression;

int add_interpret(Expression* e) {
    AddExpression* a = (AddExpression*)e;
    return a->left->interpret(a->left) + a->right->interpret(a->right);
}

Expression* add_expression_create(Expression* left, Expression* right) {
    AddExpression* a = malloc(sizeof(AddExpression));
    a->left = left;
    a->right = right;
    a->base.interpret = add_interpret;
    return (Expression*)a;
}

/* Sub */
typedef struct {
    Expression base;
    Expression* left;
    Expression* right;
} SubExpression;

int sub_interpret(Expression* e) {
    SubExpression* s = (SubExpression*)e;
    return s->left->interpret(s->left) - s->right->interpret(s->right);
}

Expression* sub_expression_create(Expression* left, Expression* right) {
    SubExpression* s = malloc(sizeof(SubExpression));
    s->left = left;
    s->right = right;
    s->base.interpret = sub_interpret;
    return (Expression*)s;
}
