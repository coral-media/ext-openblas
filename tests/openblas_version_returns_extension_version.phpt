--TEST--
openblas_version() returns extension version
--EXTENSIONS--
openblas
--FILE--
<?php
$version = openblas_version();
var_dump(is_string($version));
var_dump(strlen($version) > 0);
?>
--EXPECT--
bool(true)
bool(true)
