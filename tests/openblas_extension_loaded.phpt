--TEST--
Check if openblas is loaded
--EXTENSIONS--
openblas
--FILE--
<?php
echo 'The extension "openblas" is available';
?>
--EXPECT--
The extension "openblas" is available
