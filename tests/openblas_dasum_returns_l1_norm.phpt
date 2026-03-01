--TEST--
openblas_dasum() returns l1 norm
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_dasum([1.0, -2.0, 3.0]));
?>
--EXPECT--
float(6)
