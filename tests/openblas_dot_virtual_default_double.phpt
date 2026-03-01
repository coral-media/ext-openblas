--TEST--
openblas_dot() defaults to double precision
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_dot([1.0, 2.0, 3.0], [4.0, 5.0, 6.0]));
?>
--EXPECT--
float(32)
