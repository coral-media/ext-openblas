--TEST--
openblas dot methods reject mismatched lengths
--EXTENSIONS--
openblas
--FILE--
<?php
try {
    openblas_sdot([1.0, 2.0], [1.0]);
} catch (ValueError $e) {
    echo "sdot\n";
}

try {
    openblas_ddot([1.0, 2.0], [1.0]);
} catch (ValueError $e) {
    echo "ddot\n";
}
?>
--EXPECT--
sdot
ddot
