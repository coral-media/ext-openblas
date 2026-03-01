--TEST--
openblas_ddot() returns dot product
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_ddot([1.0, 2.0, 3.0], [4.0, 5.0, 6.0]));
?>
--EXPECT--
float(32)
