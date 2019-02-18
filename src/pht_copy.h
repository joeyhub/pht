#ifndef PHT_COPY_H
#define PHT_COPY_H

#include <main/php.h>

void copy_execution_context(void);
zend_function *copy_user_function(zend_function *old_func, zend_class_entry *new_ce);

#endif
