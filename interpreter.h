#ifndef INTERPRETER_H
#define INTERPRETER_H

typedef struct Expression {
    int (*interpret)(struct Expression*);
} Expression;

Expression* number_expression_create(int value);
Expression* add_expression_create(Expression* left, Expression* right);
Expression* sub_expression_create(Expression* left, Expression* right);

#endif
