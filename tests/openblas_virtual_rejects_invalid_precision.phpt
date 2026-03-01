--TEST--
openblas virtual methods reject invalid precision selector
--EXTENSIONS--
openblas
--FILE--
<?php
try {
    openblas_dot([1.0], [1.0], 99);
} catch (ValueError $e) {
    echo "dot\n";
}

try {
    openblas_nrm2([1.0], 99);
} catch (ValueError $e) {
    echo "nrm2\n";
}

try {
    openblas_asum([1.0], 99);
} catch (ValueError $e) {
    echo "asum\n";
}

try {
    openblas_iamax([1.0], 99);
} catch (ValueError $e) {
    echo "iamax\n";
}
?>
--EXPECT--
dot
nrm2
asum
iamax
