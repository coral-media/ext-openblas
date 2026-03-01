/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 68481f964149b4f99d98bf046a7a086b1c5367c2 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_openblas_get_config, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_openblas_version arginfo_openblas_get_config

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_openblas_sdot, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_openblas_ddot arginfo_openblas_sdot

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_openblas_snrm2, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_openblas_dnrm2 arginfo_openblas_snrm2

#define arginfo_openblas_sasum arginfo_openblas_snrm2

#define arginfo_openblas_dasum arginfo_openblas_snrm2

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_openblas_isamax, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_openblas_idamax arginfo_openblas_isamax

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_openblas_dot, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, precision, IS_LONG, 0, "OPENBLAS_DOUBLE_PRECISION")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_openblas_nrm2, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, precision, IS_LONG, 0, "OPENBLAS_DOUBLE_PRECISION")
ZEND_END_ARG_INFO()

#define arginfo_openblas_asum arginfo_openblas_nrm2

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_openblas_iamax, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, precision, IS_LONG, 0, "OPENBLAS_DOUBLE_PRECISION")
ZEND_END_ARG_INFO()


ZEND_FUNCTION(openblas_get_config);
ZEND_FUNCTION(openblas_version);
ZEND_FUNCTION(openblas_sdot);
ZEND_FUNCTION(openblas_ddot);
ZEND_FUNCTION(openblas_snrm2);
ZEND_FUNCTION(openblas_dnrm2);
ZEND_FUNCTION(openblas_sasum);
ZEND_FUNCTION(openblas_dasum);
ZEND_FUNCTION(openblas_isamax);
ZEND_FUNCTION(openblas_idamax);
ZEND_FUNCTION(openblas_dot);
ZEND_FUNCTION(openblas_nrm2);
ZEND_FUNCTION(openblas_asum);
ZEND_FUNCTION(openblas_iamax);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(openblas_get_config, arginfo_openblas_get_config)
	ZEND_FE(openblas_version, arginfo_openblas_version)
	ZEND_FE(openblas_sdot, arginfo_openblas_sdot)
	ZEND_FE(openblas_ddot, arginfo_openblas_ddot)
	ZEND_FE(openblas_snrm2, arginfo_openblas_snrm2)
	ZEND_FE(openblas_dnrm2, arginfo_openblas_dnrm2)
	ZEND_FE(openblas_sasum, arginfo_openblas_sasum)
	ZEND_FE(openblas_dasum, arginfo_openblas_dasum)
	ZEND_FE(openblas_isamax, arginfo_openblas_isamax)
	ZEND_FE(openblas_idamax, arginfo_openblas_idamax)
	ZEND_FE(openblas_dot, arginfo_openblas_dot)
	ZEND_FE(openblas_nrm2, arginfo_openblas_nrm2)
	ZEND_FE(openblas_asum, arginfo_openblas_asum)
	ZEND_FE(openblas_iamax, arginfo_openblas_iamax)
	ZEND_FE_END
};

static void register_openblas_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("OPENBLAS_SINGLE_PRECISION", 1, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("OPENBLAS_DOUBLE_PRECISION", 2, CONST_PERSISTENT);
}
