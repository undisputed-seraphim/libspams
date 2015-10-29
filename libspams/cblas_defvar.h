#pragma once

#include <stddef.h>

/*
 * Enumerated and derived types
 */
#define CBLAS_INDEX size_t  /* this may vary between platforms */

enum CBLAS_ORDER { CblasRowMajor = 101, CblasColMajor = 102 };
enum CBLAS_TRANSPOSE { CblasNoTrans = 111, CblasTrans = 112, CblasConjTrans = 113 };
enum CBLAS_UPLO { CblasUpper = 121, CblasLower = 122 };
enum CBLAS_DIAG { CblasNonUnit = 131, CblasUnit = 132 };
enum CBLAS_SIDE { CblasLeft = 141, CblasRight = 142 };

char *cblas_transpose(CBLAS_TRANSPOSE TransA);
char *cblas_uplo(CBLAS_UPLO Uplo);
char *cblas_diag(CBLAS_DIAG Diag);
char *cblas_side(CBLAS_SIDE Side);