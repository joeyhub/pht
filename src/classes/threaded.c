#include <main/php.h>
#include <Zend/zend_API.h>

#include "src/classes/threaded.h"

zend_class_entry *Threaded_ce;

ZEND_BEGIN_ARG_INFO_EX(Threaded_lock_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(Threaded_unlock_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

zend_function_entry Threaded_methods[] = {
    PHP_ABSTRACT_ME(Threaded, lock, Threaded_lock_arginfo)
    PHP_ABSTRACT_ME(Threaded, unlock, Threaded_unlock_arginfo)
    PHP_FE_END
};

int threaded_interface_gets_implemented(zend_class_entry *interface, zend_class_entry *implementor)
{
    if (implementor->type == ZEND_INTERNAL_CLASS) {
        return SUCCESS;
    }

    zend_throw_error(NULL, "The Threaded interface cannot be implemented by userland classes");

    return FAILURE;
}

void threaded_ce_init(void)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "pht\\Threaded", Threaded_methods);
    Threaded_ce = zend_register_internal_interface(&ce);
    Threaded_ce->interface_gets_implemented = threaded_interface_gets_implemented;
}
