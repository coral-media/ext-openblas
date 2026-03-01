--TEST--
openblas_idamax() returns index of max absolute value
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_idamax([1.0, -4.0, 3.0]));
?>
--EXPECT--
int(1)
