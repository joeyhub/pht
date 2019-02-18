#ifndef PHT_VECTOR_CLASS_H
#define PHT_VECTOR_CLASS_H

#include "src/ds/pht_vector.h"

typedef struct _vector_obj_internal_t {
    pht_vector_t vector;
    pthread_mutex_t lock;
    uint32_t refcount;
    zend_ulong vn;
} vector_obj_internal_t;

typedef struct _vector_obj_t {
    vector_obj_internal_t *voi;
    zend_ulong vn;
    zend_object obj;
} vector_obj_t;

void voi_free(vector_obj_internal_t *voi);
void vector_ce_init(void);

extern zend_class_entry *Vector_ce;

#endif
