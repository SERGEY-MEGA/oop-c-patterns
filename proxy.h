#ifndef PROXY_H
#define PROXY_H

/* Subject for Proxy pattern */
typedef struct ProxySubject {
    void (*request)(void);
} ProxySubject;

/* RealSubject */
ProxySubject* real_subject_create(void);

/* Proxy */
ProxySubject* proxy_create(void);

#endif
