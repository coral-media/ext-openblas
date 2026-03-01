--TEST--
openblas_sasum() returns l1 norm
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_sasum([1.0, -2.0, 3.0]));
?>
--EXPECT--
float(6)
