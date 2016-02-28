#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	size_t width;
	size_t height;
	float *data;
} matrix;

matrix *matrix_create(size_t w, size_t h){
	matrix *m;
	
	m         = malloc(sizeof(matrix));
	m->data   = malloc(sizeof(float)*w*h);
	m->width  = w;
	m->height = h;

	bzero(m->data, sizeof(float)*w*h);

	return m;
}

void matrix_free(matrix *m){
	free(m->data);
	free(m);
}

// Translates 2D coordinates to 1D index.
float matrix_get(matrix *m, size_t x, size_t y){
	return m->data[(m->width*y)+x];
}

void matrix_set(matrix *m, size_t x, size_t y, float v){
	m->data[(m->width*y)+x] = v;
}

void matrix_copy(matrix *m, float *data){
	size_t size;
	size = sizeof(float) * (m->width) * (m->height);
	memcpy(m->data, data, size); 
}

matrix *matrix_multiply(matrix *a, matrix *b){
	matrix *result;
	size_t x, i, j;

	// The size of the ROWS in matrix A
	// must be the same as the size of the
	// COLUMNS in matrix B.
	if(a->width != b->height)
		return NULL;

	result = matrix_create(b->width, b->height);

	for(i=0; i < a->height; i++){
	for(j=0; j < b->width;  j++){
		float temp = 0;

		for(x=0; x < a->width;  x++)
			temp += matrix_get(a, x, i) * matrix_get(b, j, x);

		matrix_set(result, j, i, temp);
	}
	}

	return result;
}

void matrix_print(matrix *m, int spacing){
	size_t x, y;

	// Custom formatting: we pre-format a format
	// string so we can get variable-spacing.
	char form[32];
	sprintf(form, "%%-%df", spacing);

	for(y=0; y < (m->height); y++){
		printf("%s", "| ");
		
		for(x=0; x < (m->width); x++)
			printf(form, matrix_get(m, x, y));
		
		printf("%s", "|\n");
	}
	
	printf("%s", "\n");
}
#endif
