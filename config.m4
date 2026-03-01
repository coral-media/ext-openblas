PHP_ARG_WITH([openblas],
  [for openblas support],
  [AS_HELP_STRING([--with-openblas],
    [Build openblas extension (default: use system OpenBLAS)])],
  [yes],
  [yes])

if test "$PHP_OPENBLAS" != "no"; then
  PKG_CHECK_MODULES([OPENBLAS], [openblas], [
    PHP_EVAL_INCLINE([$OPENBLAS_CFLAGS])
    PHP_EVAL_LIBLINE([$OPENBLAS_LIBS], [OPENBLAS_SHARED_LIBADD])
  ], [
    AC_MSG_ERROR([System OpenBLAS not found. Install openblas development package (for example libopenblas-dev).])
  ])

  AC_DEFINE([HAVE_OPENBLAS], [1], [Have openblas support])
  AC_DEFINE([OPENBLAS_USE_SYSTEM], [1], [Use system OpenBLAS library])
  PHP_SUBST([OPENBLAS_SHARED_LIBADD])
  PHP_NEW_EXTENSION([openblas], [openblas.c], [$ext_shared])
fi
