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
