--TEST--
openblas_dnrm2() returns l2 norm
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_dnrm2([3.0, 4.0]));
?>
--EXPECT--
float(5)
