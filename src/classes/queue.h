#ifndef PHT_QUEUE_CLASS_H
#define PHT_QUEUE_CLASS_H

#include <main/php.h>
#include <stdint.h>
#include <pthread.h>

#include "src/ds/pht_queue.h"

typedef struct _queue_obj_internal_t {
    pht_queue_t queue;
    pthread_mutex_t lock;
    uint32_t refcount;
    zend_ulong vn;
} queue_obj_internal_t;

typedef struct _queue_obj_t {
    queue_obj_internal_t *qoi;
    zend_ulong vn;
    zend_object obj;
} queue_obj_t;

void qoi_free(queue_obj_internal_t *qoi);
void queue_ce_init(void);

extern zend_class_entry *Queue_ce;

#endif
