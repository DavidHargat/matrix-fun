#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

int main(int argc, char *argv[]){

	matrix *a = matrix_create(3, 3);
	matrix *b = matrix_create(3, 3);
	matrix *r;

	a->data = (float[9]){
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f
	};

	b->data = (float[9]){
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};
	
	r = matrix_multiply(a, b);

	matrix_print(a, 10);
	matrix_print(b, 10);
	matrix_print(r, 10);

	return 0;
}
