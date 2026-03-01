--TEST--
openblas_get_config() returns non-empty string
--EXTENSIONS--
openblas
--FILE--
<?php
$config = openblas_get_config();
var_dump(is_string($config));
var_dump(strlen($config) > 0);
?>
--EXPECT--
bool(true)
bool(true)
