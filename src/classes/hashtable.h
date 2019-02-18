#ifndef PHT_HASHTABLE_CLASS_H
#define PHT_HASHTABLE_CLASS_H

#include <main/php.h>
#include <stdint.h>
#include <pthread.h>

#include "src/ds/pht_hashtable.h"

typedef struct _hashtable_obj_internal_t {
    pht_hashtable_t hashtable;
    pthread_mutex_t lock;
    uint32_t refcount;
    zend_ulong vn;
} hashtable_obj_internal_t;

typedef struct _hashtable_obj_t {
    hashtable_obj_internal_t *htoi;
    zend_ulong vn;
    zend_object obj;
} hashtable_obj_t;

void htoi_free(hashtable_obj_internal_t *htoi);
void hashtable_ce_init(void);

extern zend_class_entry *HashTable_ce;

#endif
