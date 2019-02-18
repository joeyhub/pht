#ifndef PHT_HASHTABLE_H
#define PHT_HASHTABLE_H

#include <Zend/zend_types.h>

#include "src/pht_string.h"

typedef struct _pht_bucket_t {
    pht_string_t *key; // @todo remove pointer to key?
    void *value;
    long hash;
    int variance;
} pht_bucket_t;

typedef struct _pht_hashtable_t {
    pht_bucket_t *values;
    int size;
    int used;
    void (*dtor)(void *);
} pht_hashtable_t;

void pht_hashtable_init(pht_hashtable_t *ht, int size, void (*dtor)(void *));
void pht_hashtable_insert(pht_hashtable_t *ht, pht_string_t *key, void *value);
void pht_hashtable_insert_ind(pht_hashtable_t *ht, long hash, void *value);
void pht_hashtable_delete(pht_hashtable_t *ht, pht_string_t *key);
void pht_hashtable_delete_ind(pht_hashtable_t *ht, long hash);
void *pht_hashtable_search(pht_hashtable_t *ht, pht_string_t *key);
void *pht_hashtable_search_ind(pht_hashtable_t *ht, long hash);
pht_string_t *pht_hashtable_key_fetch(pht_hashtable_t *ht, pht_string_t *key);
void pht_hashtable_update(pht_hashtable_t *ht, pht_string_t *key, void *value);
void pht_hashtable_update_ind(pht_hashtable_t *ht, long hash, void *value);
void pht_hashtable_destroy(pht_hashtable_t *ht);
void pht_hashtable_to_zend_hashtable(HashTable *zht, pht_hashtable_t *pht);

#endif
