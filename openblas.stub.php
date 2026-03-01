<?php

/**
 * @generate-class-entries
 */

/**
 * Returns a build/configuration string for the OpenBLAS integration.
 */
function openblas_get_config(): string {}

/**
 * Returns the extension version string.
 */
function openblas_version(): string {}

/**
 * Computes the single-precision dot product of two vectors.
 *
 * @param array $x Input vector.
 * @param array $y Input vector with same length as `$x`.
 */
function openblas_sdot(array $x, array $y): float {}

/**
 * Computes the double-precision dot product of two vectors.
 *
 * @param array $x Input vector.
 * @param array $y Input vector with same length as `$x`.
 */
function openblas_ddot(array $x, array $y): float {}

/**
 * Computes the Euclidean norm (L2) in single precision.
 *
 * @param array $x Input vector.
 */
function openblas_snrm2(array $x): float {}

/**
 * Computes the Euclidean norm (L2) in double precision.
 *
 * @param array $x Input vector.
 */
function openblas_dnrm2(array $x): float {}

/**
 * Computes the 1-norm (sum of absolute values) in single precision.
 *
 * @param array $x Input vector.
 */
function openblas_sasum(array $x): float {}

/**
 * Computes the 1-norm (sum of absolute values) in double precision.
 *
 * @param array $x Input vector.
 */
function openblas_dasum(array $x): float {}

/**
 * Returns the index of the element with maximum absolute value (single precision).
 *
 * @param array $x Input vector.
 */
function openblas_isamax(array $x): int {}

/**
 * Returns the index of the element with maximum absolute value (double precision).
 *
 * @param array $x Input vector.
 */
function openblas_idamax(array $x): int {}

/**
 * Computes dot product using the selected precision.
 *
 * @param array $x Input vector.
 * @param array $y Input vector with same length as `$x`.
 * @param int $precision One of `OPENBLAS_SINGLE_PRECISION` or `OPENBLAS_DOUBLE_PRECISION`.
 */
function openblas_dot(array $x, array $y, int $precision = OPENBLAS_DOUBLE_PRECISION): float {}

/**
 * Computes L2 norm using the selected precision.
 *
 * @param array $x Input vector.
 * @param int $precision One of `OPENBLAS_SINGLE_PRECISION` or `OPENBLAS_DOUBLE_PRECISION`.
 */
function openblas_nrm2(array $x, int $precision = OPENBLAS_DOUBLE_PRECISION): float {}

/**
 * Computes L1 norm using the selected precision.
 *
 * @param array $x Input vector.
 * @param int $precision One of `OPENBLAS_SINGLE_PRECISION` or `OPENBLAS_DOUBLE_PRECISION`.
 */
function openblas_asum(array $x, int $precision = OPENBLAS_DOUBLE_PRECISION): float {}

/**
 * Returns index of max absolute value using the selected precision.
 *
 * @param array $x Input vector.
 * @param int $precision One of `OPENBLAS_SINGLE_PRECISION` or `OPENBLAS_DOUBLE_PRECISION`.
 */
function openblas_iamax(array $x, int $precision = OPENBLAS_DOUBLE_PRECISION): int {}

/**
 * Single-precision operation selector.
 * @var int
 */
const OPENBLAS_SINGLE_PRECISION = 1;

/**
 * Double-precision operation selector.
 * @var int
 */
const OPENBLAS_DOUBLE_PRECISION = 2;
