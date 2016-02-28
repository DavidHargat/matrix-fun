#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

int main(int argc, char *argv[]){

	matrix *a, *b, *r;
	
	a = matrix_create(1, 4);
	b = matrix_rotate_x(90.0f);
	
	matrix_copy(a, (float[]){
		1.0f,
		1.0f,
		1.0f,
		1.0f
	});

	r = matrix_multiply(b, a);

	matrix_print(a, 6, 1);
	matrix_print(b, 6, 1);
	matrix_print(r, 6, 1);

	matrix_free(a);
	matrix_free(b);
	matrix_free(r);

	return 0;
}
