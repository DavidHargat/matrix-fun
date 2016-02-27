#ifndef NMAT_H
#define NMAT_H

#include <stdlib.h>
#include <stdio.h>

// nmat
// N-Dimensional Matrix.

typedef struct{
	size_t width;
	size_t height;
	int  **data;
} nmat;

nmat *create_nmat(size_t width, size_t height);
void  free_nmat(nmat *m);

nmat *create_nmat(size_t width, size_t height){
	
	nmat *m;
	size_t x, y;

	m = malloc(sizeof(nmat));
	
	m->width  = width;
	m->height = height;
	m->data   = malloc(sizeof(int *) * height); // allocate columns

	// allocate each row
	for(y=0; y<height; y++)
		m->data[y] = malloc(sizeof(int) * width);

	// zero each cell
	for(y=0; y<height; y++)
	for(x=0; x<width;  x++)
		m->data[y][x] = 0;
	
	return m;
}

void free_nmat(nmat *m){
	size_t y;

	for(y=0; y < (m->height); y++)
		free(m->data[y]);

	free(m->data);
	free(m);
}

nmat *nmat_multiply(nmat *a, nmat *b){
	nmat *result;
	size_t x, y, i, j;

	// The size of the ROWS in matrix A
	// must be the same as the size of the
	// COLUMNS in matrix B.
	if(a->width == b->height)
		return NULL;

	result = create_nmat(b->width, b->height);

	for(i=0; i < a->height; i++){
	for(j=0; j < b->width;  j++){
		int temp = 0;
		for(x=0; x < a->width;  x++)
		for(y=0; y < b->height; y++)
			temp += a->data[i][x] * b->data[y][j];
		
		result[i][j] = temp;
	}
	}

	return result;
}

void print_nmat(nmat *m, int spacing){
	size_t x, y;

	// Custom formatting: we pre-format a format
	// string so we can get variable-spacing.

	char form[32];
	sprintf(form, "%%-%dd", spacing);

	for(y=0; y < (m->height); y++){
		printf("| ");
		
		for(x=0; x < (m->width); x++)
			printf(form, m->data[y][x]);
		
		printf("|\n");
	}
}

#endif
