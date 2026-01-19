#include <stdio.h>
#include <stdlib.h>
#include "proxy.h"

/* Real subject logic */
void real_request(void) {
    printf("RealSubject: handling request\n");
}

ProxySubject* real_subject_create(void) {
    ProxySubject* s = malloc(sizeof(ProxySubject));
    s->request = real_request;
    return s;
}

/* Proxy logic */
typedef struct {
    ProxySubject base;
    ProxySubject* real;
} Proxy;

void proxy_request(void) {
    printf("Proxy: checking access\n");
    ProxySubject* real = real_subject_create();
    real->request();
}

ProxySubject* proxy_create(void) {
    Proxy* p = malloc(sizeof(Proxy));
    p->base.request = proxy_request;
    p->real = 0;
    return (ProxySubject*)p;
}
