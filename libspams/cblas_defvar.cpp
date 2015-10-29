#include "cblas_defvar.h"

char CBLAS_TRANSPOSE_CHAR[] = {'N', 'T', 'C'};
char CBLAS_UPLO_CHAR[] = {'U', 'L'};
char CBLAS_DIAG_CHAR[] = {'N', 'U'};
char CBLAS_SIDE_CHAR[] = {'L', 'R'};

char *cblas_transpose(CBLAS_TRANSPOSE TransA)
{
	switch (TransA) {
	case 111:	return &CBLAS_TRANSPOSE_CHAR[0];
	case 112:	return &CBLAS_TRANSPOSE_CHAR[1];
	case 113:	return &CBLAS_TRANSPOSE_CHAR[2];
	}
	return NULL;
}

char *cblas_uplo(CBLAS_UPLO Uplo)
{
	switch (Uplo) {
	case 121:	return &CBLAS_UPLO_CHAR[0];
	case 122:	return &CBLAS_UPLO_CHAR[1];
	}
	return NULL;
}

char *cblas_diag(CBLAS_DIAG Diag)
{
	switch (Diag) {
	case 131:	return &CBLAS_DIAG_CHAR[0];
	case 132:	return &CBLAS_DIAG_CHAR[1];
	}
	return NULL;
}

char *cblas_side(CBLAS_SIDE Side)
{
	switch (Side) {
	case 141:	return &CBLAS_SIDE_CHAR[0];
	case 142:	return &CBLAS_SIDE_CHAR[1];
	}
	return NULL;
}