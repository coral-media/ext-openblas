--TEST--
openblas_iamax() supports single precision selector
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_iamax([1.0, -4.0, 3.0], OPENBLAS_SINGLE_PRECISION));
?>
--EXPECT--
int(1)
