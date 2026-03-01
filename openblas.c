/* openblas extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_openblas.h"
#include "openblas_arginfo.h"
#include <cblas.h>

#define OPENBLAS_SINGLE_PRECISION 1
#define OPENBLAS_DOUBLE_PRECISION 2

static bool openblas_float_array_from_zend_array(zend_array *arr, float **out_values)
{
	zval *val;
	uint32_t count = zend_hash_num_elements(arr);
	uint32_t i = 0;
	float *values = (float *) safe_emalloc(count, sizeof(float), 0);

	ZEND_HASH_FOREACH_VAL(arr, val) {
		values[i++] = (float) zval_get_double(val);
	} ZEND_HASH_FOREACH_END();

	*out_values = values;
	return true;
}

static bool openblas_validate_precision(zend_long precision, uint32_t arg_num)
{
	if (precision != OPENBLAS_SINGLE_PRECISION && precision != OPENBLAS_DOUBLE_PRECISION) {
		zend_argument_value_error(arg_num, "must be OPENBLAS_SINGLE_PRECISION or OPENBLAS_DOUBLE_PRECISION");
		return false;
	}
	return true;
}

static bool openblas_double_array_from_zend_array(zend_array *arr, double **out_values)
{
	zval *val;
	uint32_t count = zend_hash_num_elements(arr);
	uint32_t i = 0;
	double *values = (double *) safe_emalloc(count, sizeof(double), 0);

	ZEND_HASH_FOREACH_VAL(arr, val) {
		values[i++] = zval_get_double(val);
	} ZEND_HASH_FOREACH_END();

	*out_values = values;
	return true;
}

/* {{{ string openblas_get_config() */
PHP_FUNCTION(openblas_get_config)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING("openblas system library scaffold");
}
/* }}} */

/* {{{ string openblas_version() */
PHP_FUNCTION(openblas_version)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(PHP_OPENBLAS_VERSION);
}
/* }}} */

/* {{{ float openblas_sdot(array $x, array $y) */
PHP_FUNCTION(openblas_sdot)
{
	zend_array *x_arr, *y_arr;
	float *x_values, *y_values;
	uint32_t n;
	float result;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY_HT(x_arr)
		Z_PARAM_ARRAY_HT(y_arr)
	ZEND_PARSE_PARAMETERS_END();

	if (zend_hash_num_elements(x_arr) != zend_hash_num_elements(y_arr)) {
		zend_argument_value_error(2, "must have the same number of elements as argument #1 ($x)");
		RETURN_THROWS();
	}

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	openblas_float_array_from_zend_array(x_arr, &x_values);
	openblas_float_array_from_zend_array(y_arr, &y_values);

	result = cblas_sdot((int) n, x_values, 1, y_values, 1);

	efree(x_values);
	efree(y_values);

	RETURN_DOUBLE((double) result);
}
/* }}} */

/* {{{ float openblas_ddot(array $x, array $y) */
PHP_FUNCTION(openblas_ddot)
{
	zend_array *x_arr, *y_arr;
	double *x_values, *y_values;
	uint32_t n;
	double result;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY_HT(x_arr)
		Z_PARAM_ARRAY_HT(y_arr)
	ZEND_PARSE_PARAMETERS_END();

	if (zend_hash_num_elements(x_arr) != zend_hash_num_elements(y_arr)) {
		zend_argument_value_error(2, "must have the same number of elements as argument #1 ($x)");
		RETURN_THROWS();
	}

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	openblas_double_array_from_zend_array(x_arr, &x_values);
	openblas_double_array_from_zend_array(y_arr, &y_values);

	result = cblas_ddot((int) n, x_values, 1, y_values, 1);

	efree(x_values);
	efree(y_values);

	RETURN_DOUBLE(result);
}
/* }}} */

/* {{{ float openblas_snrm2(array $x) */
PHP_FUNCTION(openblas_snrm2)
{
	zend_array *x_arr;
	float *x_values;
	uint32_t n;
	float result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(x_arr)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	openblas_float_array_from_zend_array(x_arr, &x_values);
	result = cblas_snrm2((int) n, x_values, 1);
	efree(x_values);

	RETURN_DOUBLE((double) result);
}
/* }}} */

/* {{{ float openblas_dnrm2(array $x) */
PHP_FUNCTION(openblas_dnrm2)
{
	zend_array *x_arr;
	double *x_values;
	uint32_t n;
	double result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(x_arr)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	openblas_double_array_from_zend_array(x_arr, &x_values);
	result = cblas_dnrm2((int) n, x_values, 1);
	efree(x_values);

	RETURN_DOUBLE(result);
}
/* }}} */

/* {{{ float openblas_sasum(array $x) */
PHP_FUNCTION(openblas_sasum)
{
	zend_array *x_arr;
	float *x_values;
	uint32_t n;
	float result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(x_arr)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	openblas_float_array_from_zend_array(x_arr, &x_values);
	result = cblas_sasum((int) n, x_values, 1);
	efree(x_values);

	RETURN_DOUBLE((double) result);
}
/* }}} */

/* {{{ float openblas_dasum(array $x) */
PHP_FUNCTION(openblas_dasum)
{
	zend_array *x_arr;
	double *x_values;
	uint32_t n;
	double result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(x_arr)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	openblas_double_array_from_zend_array(x_arr, &x_values);
	result = cblas_dasum((int) n, x_values, 1);
	efree(x_values);

	RETURN_DOUBLE(result);
}
/* }}} */

/* {{{ int openblas_isamax(array $x) */
PHP_FUNCTION(openblas_isamax)
{
	zend_array *x_arr;
	float *x_values;
	uint32_t n;
	int idx;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(x_arr)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_LONG(0);
	}

	openblas_float_array_from_zend_array(x_arr, &x_values);
	idx = cblas_isamax((int) n, x_values, 1);
	efree(x_values);

	RETURN_LONG((zend_long) idx);
}
/* }}} */

/* {{{ int openblas_idamax(array $x) */
PHP_FUNCTION(openblas_idamax)
{
	zend_array *x_arr;
	double *x_values;
	uint32_t n;
	int idx;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(x_arr)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_LONG(0);
	}

	openblas_double_array_from_zend_array(x_arr, &x_values);
	idx = cblas_idamax((int) n, x_values, 1);
	efree(x_values);

	RETURN_LONG((zend_long) idx);
}
/* }}} */

/* {{{ float openblas_dot(array $x, array $y, int $precision = OPENBLAS_DOUBLE_PRECISION) */
PHP_FUNCTION(openblas_dot)
{
	zend_array *x_arr, *y_arr;
	zend_long precision = OPENBLAS_DOUBLE_PRECISION;
	uint32_t n;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY_HT(x_arr)
		Z_PARAM_ARRAY_HT(y_arr)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(precision)
	ZEND_PARSE_PARAMETERS_END();

	if (!openblas_validate_precision(precision, 3)) {
		RETURN_THROWS();
	}

	if (zend_hash_num_elements(x_arr) != zend_hash_num_elements(y_arr)) {
		zend_argument_value_error(2, "must have the same number of elements as argument #1 ($x)");
		RETURN_THROWS();
	}

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	if (precision == OPENBLAS_SINGLE_PRECISION) {
		float *x_values, *y_values;
		float result;
		openblas_float_array_from_zend_array(x_arr, &x_values);
		openblas_float_array_from_zend_array(y_arr, &y_values);
		result = cblas_sdot((int) n, x_values, 1, y_values, 1);
		efree(x_values);
		efree(y_values);
		RETURN_DOUBLE((double) result);
	}

	{
		double *x_values, *y_values;
		double result;
		openblas_double_array_from_zend_array(x_arr, &x_values);
		openblas_double_array_from_zend_array(y_arr, &y_values);
		result = cblas_ddot((int) n, x_values, 1, y_values, 1);
		efree(x_values);
		efree(y_values);
		RETURN_DOUBLE(result);
	}
}
/* }}} */

/* {{{ float openblas_nrm2(array $x, int $precision = OPENBLAS_DOUBLE_PRECISION) */
PHP_FUNCTION(openblas_nrm2)
{
	zend_array *x_arr;
	zend_long precision = OPENBLAS_DOUBLE_PRECISION;
	uint32_t n;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY_HT(x_arr)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(precision)
	ZEND_PARSE_PARAMETERS_END();

	if (!openblas_validate_precision(precision, 2)) {
		RETURN_THROWS();
	}

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	if (precision == OPENBLAS_SINGLE_PRECISION) {
		float *x_values;
		float result;
		openblas_float_array_from_zend_array(x_arr, &x_values);
		result = cblas_snrm2((int) n, x_values, 1);
		efree(x_values);
		RETURN_DOUBLE((double) result);
	}

	{
		double *x_values;
		double result;
		openblas_double_array_from_zend_array(x_arr, &x_values);
		result = cblas_dnrm2((int) n, x_values, 1);
		efree(x_values);
		RETURN_DOUBLE(result);
	}
}
/* }}} */

/* {{{ float openblas_asum(array $x, int $precision = OPENBLAS_DOUBLE_PRECISION) */
PHP_FUNCTION(openblas_asum)
{
	zend_array *x_arr;
	zend_long precision = OPENBLAS_DOUBLE_PRECISION;
	uint32_t n;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY_HT(x_arr)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(precision)
	ZEND_PARSE_PARAMETERS_END();

	if (!openblas_validate_precision(precision, 2)) {
		RETURN_THROWS();
	}

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_DOUBLE(0.0);
	}

	if (precision == OPENBLAS_SINGLE_PRECISION) {
		float *x_values;
		float result;
		openblas_float_array_from_zend_array(x_arr, &x_values);
		result = cblas_sasum((int) n, x_values, 1);
		efree(x_values);
		RETURN_DOUBLE((double) result);
	}

	{
		double *x_values;
		double result;
		openblas_double_array_from_zend_array(x_arr, &x_values);
		result = cblas_dasum((int) n, x_values, 1);
		efree(x_values);
		RETURN_DOUBLE(result);
	}
}
/* }}} */

/* {{{ int openblas_iamax(array $x, int $precision = OPENBLAS_DOUBLE_PRECISION) */
PHP_FUNCTION(openblas_iamax)
{
	zend_array *x_arr;
	zend_long precision = OPENBLAS_DOUBLE_PRECISION;
	uint32_t n;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY_HT(x_arr)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(precision)
	ZEND_PARSE_PARAMETERS_END();

	if (!openblas_validate_precision(precision, 2)) {
		RETURN_THROWS();
	}

	n = zend_hash_num_elements(x_arr);
	if (n == 0) {
		RETURN_LONG(0);
	}

	if (precision == OPENBLAS_SINGLE_PRECISION) {
		float *x_values;
		int idx;
		openblas_float_array_from_zend_array(x_arr, &x_values);
		idx = cblas_isamax((int) n, x_values, 1);
		efree(x_values);
		RETURN_LONG((zend_long) idx);
	}

	{
		double *x_values;
		int idx;
		openblas_double_array_from_zend_array(x_arr, &x_values);
		idx = cblas_idamax((int) n, x_values, 1);
		efree(x_values);
		RETURN_LONG((zend_long) idx);
	}
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(openblas)
{
	REGISTER_LONG_CONSTANT("OPENBLAS_SINGLE_PRECISION", OPENBLAS_SINGLE_PRECISION, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("OPENBLAS_DOUBLE_PRECISION", OPENBLAS_DOUBLE_PRECISION, CONST_CS | CONST_PERSISTENT);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(openblas)
{
#if defined(ZTS) && defined(COMPILE_DL_OPENBLAS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(openblas)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "openblas support", "enabled");
	php_info_print_table_row(2, "openblas backend", "system library scaffold");
	php_info_print_table_end();
}
/* }}} */

/* {{{ openblas_module_entry */
zend_module_entry openblas_module_entry = {
	STANDARD_MODULE_HEADER,
	"openblas",				/* Extension name */
	ext_functions,				/* zend_function_entry */
	PHP_MINIT(openblas),			/* PHP_MINIT - Module initialization */
	NULL,					/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(openblas),			/* PHP_RINIT - Request initialization */
	NULL,					/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(openblas),			/* PHP_MINFO - Module info */
	PHP_OPENBLAS_VERSION,			/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_OPENBLAS
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(openblas)
#endif
