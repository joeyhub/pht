#ifndef PHP_PHT_H
#define PHP_PHT_H

#include <Zend/zend_modules.h>
#include <Zend/zend_API.h>

extern zend_module_entry pht_module_entry;
#define phpext_pht_ptr &pht_module_entry

#define PHP_PHT_VERSION "0.0.1"

#ifndef ZTS
#  error "ZTS is required"
#endif

ZEND_BEGIN_MODULE_GLOBALS(pht)
    void ***parent_thread_ls;
    HashTable op_array_file_names;
    HashTable child_threads;
    zend_bool skip_qoi_creation;
    zend_bool skip_htoi_creation;
    zend_bool skip_voi_creation;
    zend_bool skip_aioi_creation;
ZEND_END_MODULE_GLOBALS(pht)

ZEND_EXTERN_MODULE_GLOBALS(pht)

typedef struct _common_strings_t {
    zend_string *__construct;
    zend_string *run;
    zend_string *_THREAD;
    zend_string *value;
    zend_string *Queue;
    zend_string *HashTable;
    zend_string *Vector;
    zend_string *AtomicInteger;
} common_strings_t;

extern common_strings_t common_strings;

#define PHT_ZG(v) ZEND_MODULE_GLOBALS_ACCESSOR(pht, v)

#define PHT_CTX(ls, id, type, element) (((type) (*((void ***) ls))[TSRM_UNSHUFFLE_RSRC_ID(id)])->element)
#define PHT_EG(ls, v) PHT_CTX(ls, executor_globals_id, zend_executor_globals*, v)
#define PHT_CG(ls, v) PHT_CTX(ls, compiler_globals_id, zend_compiler_globals*, v)
#define PHT_SG(ls, v) PHT_CTX(ls, sapi_globals_id, sapi_globals_struct*, v)

#if defined(ZTS) && defined(COMPILE_DL_PHT)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
