--TEST--
openblas_snrm2() returns l2 norm
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_snrm2([3.0, 4.0]));
?>
--EXPECT--
float(5)
