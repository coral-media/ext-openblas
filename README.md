# coral-media/ext-openblas

`coral-media/ext-openblas` is a PHP extension scaffold for OpenBLAS using system OpenBLAS libraries.

## Status

- PIE metadata configured
- Build config wired for `--with-openblas` (system OpenBLAS) on Unix and Windows
- Initial function exposed: `openblas_get_config()`
- Minimal PHPT tests included

## System Requirements

### Unix/Linux

- PHP development toolchain: `phpize`, `php-config`, C compiler, `make`
- OpenBLAS development files available via `pkg-config`
- Typical Debian/Ubuntu packages:
  - `libopenblas-dev`
  - `pkg-config`

### Windows

- Visual Studio C/C++ build tools (used by `phpize`/`nmake` flow)
- OpenBLAS headers and import library installed (for example via `vcpkg`)
- Runtime `openblas.dll` available in `PATH` for tests/runtime

## Install (PIE)

```bash
pie install --with-openblas
```

## Build From Source

```bash
phpize
./configure --with-openblas
make -j"$(nproc)"
make test
```

## OpenBLAS Functions

### Core
Extension metadata and runtime info.

`openblas_version`, `openblas_get_config`

### Dot Products
Vector dot products in fixed and precision-dispatched variants.

`openblas_sdot`, `openblas_ddot`, `openblas_dot`

### Euclidean Norms (L2)
Vector 2-norm functions in fixed and precision-dispatched variants.

`openblas_snrm2`, `openblas_dnrm2`, `openblas_nrm2`

### One Norms (L1)
Vector 1-norm (sum of absolute values) functions in fixed and precision-dispatched variants.

`openblas_sasum`, `openblas_dasum`, `openblas_asum`

### Infinity Norm Helpers (i_amax)
Index of maximum absolute value in fixed and precision-dispatched variants.

`openblas_isamax`, `openblas_idamax`, `openblas_iamax`
