
This is an automatically generated documentation for **OpenBLAS bindings for PHP**.

## Namespaces

### \

#### Functions

| Function                                                      | Description                                                                      |
|---------------------------------------------------------------|----------------------------------------------------------------------------------|
| [`openblas_get_config()`](./functions/openblas_get_config.md) | Returns a build/configuration string for the OpenBLAS integration.               |
| [`openblas_version()`](./functions/openblas_version.md)       | Returns the extension version string.                                            |
| [`openblas_sdot()`](./functions/openblas_sdot.md)             | Computes the single-precision dot product of two vectors.                        |
| [`openblas_ddot()`](./functions/openblas_ddot.md)             | Computes the double-precision dot product of two vectors.                        |
| [`openblas_snrm2()`](./functions/openblas_snrm2.md)           | Computes the Euclidean norm (L2) in single precision.                            |
| [`openblas_dnrm2()`](./functions/openblas_dnrm2.md)           | Computes the Euclidean norm (L2) in double precision.                            |
| [`openblas_sasum()`](./functions/openblas_sasum.md)           | Computes the 1-norm (sum of absolute values) in single precision.                |
| [`openblas_dasum()`](./functions/openblas_dasum.md)           | Computes the 1-norm (sum of absolute values) in double precision.                |
| [`openblas_isamax()`](./functions/openblas_isamax.md)         | Returns the index of the element with maximum absolute value (single precision). |
| [`openblas_idamax()`](./functions/openblas_idamax.md)         | Returns the index of the element with maximum absolute value (double precision). |
| [`openblas_dot()`](./functions/openblas_dot.md)               | Computes dot product using the selected precision.                               |
| [`openblas_nrm2()`](./functions/openblas_nrm2.md)             | Computes L2 norm using the selected precision.                                   |
| [`openblas_asum()`](./functions/openblas_asum.md)             | Computes L1 norm using the selected precision.                                   |
| [`openblas_iamax()`](./functions/openblas_iamax.md)           | Returns index of max absolute value using the selected precision.                |

#### Constants

| Constant                                                                | Value | Description                          |
|-------------------------------------------------------------------------|-------|--------------------------------------|
| [`OPENBLAS_SINGLE_PRECISION`](./constants/OPENBLAS_SINGLE_PRECISION.md) | 1     | Single-precision operation selector. |
| [`OPENBLAS_DOUBLE_PRECISION`](./constants/OPENBLAS_DOUBLE_PRECISION.md) | 2     | Double-precision operation selector. |
