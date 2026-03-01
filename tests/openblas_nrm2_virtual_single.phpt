--TEST--
openblas_nrm2() supports single precision selector
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_nrm2([3.0, 4.0], OPENBLAS_SINGLE_PRECISION));
?>
--EXPECT--
float(5)
