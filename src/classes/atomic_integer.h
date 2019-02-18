#ifndef PHT_ATOMIC_INTEGER_CLASS_H
#define PHT_ATOMIC_INTEGER_CLASS_H

#include <main/php.h>
#include <stdint.h>
#include <pthread.h>

typedef struct _atomic_integer_obj_internal_t {
    zend_long value;
    pthread_mutex_t lock;
    uint32_t refcount;
} atomic_integer_obj_internal_t;

typedef struct _atomic_integer_obj_t {
    atomic_integer_obj_internal_t *aioi;
    zend_object obj;
} atomic_integer_obj_t;

extern zend_class_entry *AtomicInteger_ce;

void aioi_free(atomic_integer_obj_internal_t *aioi);
void atomic_integer_ce_init(void);

#endif
