--TEST--
openblas_asum() defaults to double precision
--EXTENSIONS--
openblas
--FILE--
<?php
var_dump(openblas_asum([1.0, -2.0, 3.0]));
?>
--EXPECT--
float(6)
