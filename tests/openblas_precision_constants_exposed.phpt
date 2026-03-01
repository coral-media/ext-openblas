--TEST--
openblas precision constants are exposed
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(defined('OPENBLAS_SINGLE_PRECISION'));
var_dump(defined('OPENBLAS_DOUBLE_PRECISION'));
var_dump(OPENBLAS_SINGLE_PRECISION);
var_dump(OPENBLAS_DOUBLE_PRECISION);
?>
--EXPECT--
bool(true)
bool(true)
int(1)
int(2)
