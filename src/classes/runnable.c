#include <main/php.h>
#include <Zend/zend_API.h>

#include "src/classes/runnable.h"

zend_class_entry *Runnable_ce;

ZEND_BEGIN_ARG_INFO_EX(Runnable_run_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

zend_function_entry Runnable_methods[] = {
    PHP_ABSTRACT_ME(Runnable, run, Runnable_run_arginfo)
    PHP_FE_END
};

void runnable_ce_init(void)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "pht\\Runnable", Runnable_methods);
    Runnable_ce = zend_register_internal_interface(&ce);
}
