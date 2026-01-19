#include <stdio.h>
#include <stdlib.h>
#include "mediator.h"
#include "memento.h"
#include "interpreter.h"
#include "visitor.h"

#include "factory.h"
#include "singleton.h"
#include "stack.h"
#include "observer.h"
#include "adapter.h"
#include "command.h"
#include "chain.h"
#include "iterator.h"
#include "state.h"
#include "facade.h"
#include "builder.h"
#include "abstract_factory.h"
#include "bridge.h"
#include "decorator.h"
#include "composite.h"
#include "proxy.h"
#include "flyweight.h"

/* ===== Observer callback ===== */
void print_observer(int value) {
    printf("Observer notified, new value: %d\n", value);
}

int main() {

    /* ===== Figures (ООП + Factory) ===== */
    Figure* fig1 = figure_factory(FIGURE_SQUARE, 4, 0, 0);
    Figure* fig2 = figure_factory(FIGURE_CIRCLE, 3, 0, 0);
    Figure* fig3 = figure_factory(FIGURE_TRIANGLE, 3, 4, 5);

    Figure* figures[] = { fig1, fig2, fig3 };

    for (int i = 0; i < 3; i++) {
        printf("Area: %.2f, Perimeter: %.2f\n",
               figures[i]->area(figures[i]),
               figures[i]->perimeter(figures[i]));
        free(figures[i]);
    }

    /* ===== Singleton ===== */
    Singleton* s1 = get_singleton();
    Singleton* s2 = get_singleton();

    s1->value = 42;

    printf("s1 value: %d\n", s1->value);
    printf("s2 value: %d\n", s2->value);

    /* ===== Stack ===== */
    Stack* stack = stack_create();

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    printf("\nStack pop:\n");
    while (!stack_is_empty(stack)) {
        printf("%d\n", stack_pop(stack));
    }

    /* ===== Observer ===== */
    Subject* subject = subject_create();
    Observer* obs1 = observer_create(print_observer);
    Observer* obs2 = observer_create(print_observer);

    subject_attach(subject, obs1);
    subject_attach(subject, obs2);

    printf("\nObserver demo:\n");
    subject_set_state(subject, 100);
    subject_set_state(subject, 200);

    /* ===== Adapter (ТВОЯ ВЕРСИЯ) ===== */
    Figure* adapted = square_adapter_create(5);

    printf("\nAdapter demo:\n");
    printf("Area: %.2f, Perimeter: %.2f\n",
           adapted->area(adapted),
           adapted->perimeter(adapted));

    /* ===== Command ===== */
    Receiver* r = receiver_create(receiver_action);
    Command* cmd = command_create(r);
    Invoker* inv = invoker_create(cmd);

    printf("\nCommand demo:\n");
    invoker_invoke(inv);

    /* ===== Chain of Responsibility ===== */
    Handler* h1 = handler_create(10);
    Handler* h2 = handler_create(20);
    Handler* h3 = handler_create(30);

    handler_set_next(h1, h2);
    handler_set_next(h2, h3);

    printf("\nChain of Responsibility demo:\n");
    handler_handle(h1, 5);
    handler_handle(h1, 15);
    handler_handle(h1, 25);
    handler_handle(h1, 100);

    /* ===== Iterator ===== */
    int data[] = { 1, 2, 3, 4, 5 };
    Aggregate* agg = aggregate_create(data, 5);
    Iterator* it = iterator_create(agg);

    printf("\nIterator demo:\n");
    while (iterator_has_next(it)) {
        printf("%d\n", iterator_next(it));
    }

    /* ===== State ===== */
    Context* ctx = context_create(state_a_create());

    printf("\nState demo:\n");
    context_request(ctx);
    context_request(ctx);
    context_request(ctx);

    /* ===== Facade ===== */
    Facade* facade = facade_create();

    printf("\nFacade demo:\n");
    facade_start_system(facade);
    facade_stop_system(facade);

    /* ===== Builder ===== */
    Builder* builder = concrete_builder_create();
    Director d;
    d.builder = builder;

    printf("\nBuilder demo:\n");
    director_construct(&d);

    Product* product = builder_get_result(builder);
    printf("Product parts: %s, %s, %s\n",
           product->part1,
           product->part2,
           product->part3);

    /* ===== Abstract Factory ===== */
    AbstractFactory* fa = factory_a_create();
    AbstractFactory* fb = factory_b_create();

    printf("\nAbstract Factory demo:\n");

    ProductA* pa1 = fa->create_product_a();
    ProductB* pb1 = fa->create_product_b();
    pa1->use();
    pb1->use();

    ProductA* pa2 = fb->create_product_a();
    ProductB* pb2 = fb->create_product_b();
    pa2->use();
    pb2->use();

    /* ===== Bridge ===== */
    Implementor* ia = implementor_a_create();
    Implementor* ib = implementor_b_create();

    Abstraction* ab1 = abstraction_create(ia);
    Abstraction* ab2 = abstraction_create(ib);

    printf("\nBridge demo:\n");
    ab1->operation(ab1);
    ab2->operation(ab2);

    /* ===== Decorator ===== */
    Component* base = component_create();
    Component* deco = decorator_create(base);

    printf("\nDecorator demo:\n");
    printf("Base result: %d\n", base->operation(base));
    printf("Decorated result: %d\n", deco->operation(deco));

    /* ===== Composite ===== */
    CompositeComponent* l1 = leaf_create(5);
    CompositeComponent* l2 = leaf_create(10);

    Composite* group = (Composite*)composite_create();
    composite_add(group, l1);
    composite_add(group, l2);

    printf("\nComposite demo:\n");
    printf("Result: %d\n",
           group->base.operation((CompositeComponent*)group));

    /* ===== Proxy ===== */
    ProxySubject* proxy = proxy_create();

    printf("\nProxy demo:\n");
    proxy->request();

    /* ===== Flyweight ===== */
    FlyweightFactory* fw_factory = flyweight_factory_create();

    Flyweight* fw1 = flyweight_factory_get(fw_factory, "A");
    Flyweight* fw2 = flyweight_factory_get(fw_factory, "A");
    Flyweight* fw3 = flyweight_factory_get(fw_factory, "B");

    printf("\nFlyweight demo:\n");
    fw1->operation(fw1, 1);
    fw2->operation(fw2, 2);
    fw3->operation(fw3, 3);

/* ===== Mediator ===== */
Mediator* med = mediator_create();

Colleague* c1 = colleague_create("Alice", med);
Colleague* c2 = colleague_create("Bob", med);
Colleague* c3 = colleague_create("Charlie", med);

printf("\nMediator demo:\n");
c1->send(c1, "Hello everyone!");
c2->send(c2, "Hi Alice!");
c3->send(c3, "Good day!");
/* ===== Memento ===== */
Originator* o = originator_create();

printf("\nMemento demo:\n");

o->set_state(o, 10);
Memento* m1 = o->save(o);

o->set_state(o, 20);
Memento* m2 = o->save(o);

o->set_state(o, 30);
printf("Current state: %d\n", o->get_state(o));

o->restore(o, m1);
printf("Restored to state: %d\n", o->get_state(o));

o->restore(o, m2);
printf("Restored to state: %d\n", o->get_state(o));
/* ===== Interpreter ===== */
Expression* five = number_expression_create(5);
Expression* three = number_expression_create(3);
Expression* two = number_expression_create(2);

Expression* add = add_expression_create(five, three);
Expression* expr = sub_expression_create(add, two);

printf("\nInterpreter demo:\n");
printf("Result: %d\n", expr->interpret(expr));

/* ===== Visitor ===== */
ConcreteElementA* va = element_a_create(10);
ConcreteElementB* vb = element_b_create(20);

Visitor* visitor = visitor_create();

printf("\nVisitor demo:\n");
va->base.accept((Element*)va, visitor);
vb->base.accept((Element*)vb, visitor);

    return 0;
}
