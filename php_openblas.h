/* openblas extension for PHP */

#ifndef PHP_OPENBLAS_H
# define PHP_OPENBLAS_H

extern zend_module_entry openblas_module_entry;
# define phpext_openblas_ptr &openblas_module_entry

# define PHP_OPENBLAS_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_OPENBLAS)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_OPENBLAS_H */
