#include <stdlib.h>
#include <stdio.h>

#include "nmat.h"

typedef struct{
	char x1, y1, z1;
	char x2, y2, z2;
	char x3, y3, z3;
} matrix;

matrix *create_matrix(){
	matrix *mat;
	mat = malloc(sizeof(matrix));
	
	mat->x1 = 0; mat->y1 = 0; mat->z1 = 0;
	mat->x2 = 0; mat->y2 = 0; mat->z2 = 0;
	mat->x3 = 0; mat->y3 = 0; mat->z3 = 0;
	
	return mat;
}

matrix *init_matrix(
	char x1, char y1, char z1,
	char x2, char y2, char z2,
	char x3, char y3, char z3
){
	matrix *m = create_matrix();

	m->x1 = x1; m->y1 = y1; m->z1 = z1;
	m->x2 = x2; m->y2 = y2; m->z2 = z2;
	m->x3 = x3; m->y3 = y3; m->z3 = z3;

	return m;
}

void set_matrix(
	matrix *m, 
	char x1, char y1, char z1,
	char x2, char y2, char z2,
	char x3, char y3, char z3
){
	m->x1 = x1; m->y1 = y1; m->z1 = z1;
	m->x2 = x2; m->y2 = y2; m->z2 = z2;
	m->x3 = x3; m->y3 = y3; m->z3 = z3;
}

matrix *multiply(matrix *a, matrix *b){
	matrix *result;

	result = create_matrix();

	// first row
	result->x1 = 
		(a->x1 * b->x1) + 
		(a->y1 * b->x2) + 
		(a->z1 * b->x3);
	result->y1 = 
		(a->x1 * b->y1) + 
		(a->y1 * b->y2) + 
		(a->z1 * b->y3);
	result->z1 = 
		(a->x1 * b->z1) + 
		(a->y1 * b->z2) + 
		(a->z1 * b->z3);
	
	// second row
	result->x2 = 
		(a->x2 * b->x1) + 
		(a->y2 * b->x2) + 
		(a->z2 * b->x3);
	result->y2 = 
		(a->x2 * b->y1) + 
		(a->y2 * b->y2) + 
		(a->z2 * b->y3);
	result->z2 = 
		(a->x2 * b->z1) + 
		(a->y2 * b->z2) + 
		(a->z2 * b->z3);

	// third row
	result->x3 = 
		(a->x3 * b->x1) + 
		(a->y3 * b->x2) + 
		(a->z3 * b->x3);
	result->y3 = 
		(a->x3 * b->y1) + 
		(a->y3 * b->y2) + 
		(a->z3 * b->y3);
	result->z3 = 
		(a->x3 * b->z1) + 
		(a->y3 * b->z2) + 
		(a->z3 * b->z3);

	return result;
}

void print_matrix(matrix *mat){
	printf("| %d %d %d\n",   mat->x1, mat->y1, mat->z1);
	printf("| %d %d %d\n",   mat->x2, mat->y2, mat->z2);
	printf("| %d %d %d\n\n", mat->x3, mat->y3, mat->z3);
}

int main(int argc, char *argv[]){

	/*
	matrix *a, *b, *r;
	
	a = init_matrix(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9		
	);

	b = init_matrix(
		0, 1, 1,
		1, 0, 1,
		1, 1, 0		
	);

	r = multiply(a,b);
	
	print_matrix(a);
	print_matrix(b);
	print_matrix(r);
	*/
	
	nmat *m1, *m2;
	m1 = create_nmat(4, 4);
	m2 = create_nmat(1, 4);

	m1->data[2][2] = 32;

	print_nmat(m1, 3);
	printf("%s", "\n *\n\n");
	print_nmat(m2, 2);

	//print_nmat(create_nmat(1,4));

	return 0;
}
