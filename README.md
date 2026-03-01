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

[`openblas_version`](docs/api/functions/openblas_version.md), [`openblas_get_config`](docs/api/functions/openblas_get_config.md)

### Dot Products
Vector dot products in fixed and precision-dispatched variants.

[`openblas_sdot`](docs/api/functions/openblas_sdot.md), [`openblas_ddot`](docs/api/functions/openblas_ddot.md), [`openblas_dot`](docs/api/functions/openblas_dot.md)

### Euclidean Norms (L2)
Vector 2-norm functions in fixed and precision-dispatched variants.

[`openblas_snrm2`](docs/api/functions/openblas_snrm2.md), [`openblas_dnrm2`](docs/api/functions/openblas_dnrm2.md), [`openblas_nrm2`](docs/api/functions/openblas_nrm2.md)

### One Norms (L1)
Vector 1-norm (sum of absolute values) functions in fixed and precision-dispatched variants.

[`openblas_sasum`](docs/api/functions/openblas_sasum.md), [`openblas_dasum`](docs/api/functions/openblas_dasum.md), [`openblas_asum`](docs/api/functions/openblas_asum.md)

### Infinity Norm Helpers (i_amax)
Index of maximum absolute value in fixed and precision-dispatched variants.

[`openblas_isamax`](docs/api/functions/openblas_isamax.md), [`openblas_idamax`](docs/api/functions/openblas_idamax.md), [`openblas_iamax`](docs/api/functions/openblas_iamax.md)
