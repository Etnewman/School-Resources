/*
Ethan Newman
CSC 4100
Program 1 - Memory Manager
Matrix Header
Due: 3/8/2021
*/

#include "MMHeader.h"
#include <stdlib.h>

typedef struct __matrix
{
	int num_rows;
	int num_cols;
	double* elements;
} matrix;

matrix* matrix_malloc(int num_rows, int num_cols);  

//requires two mallocs--  malloc space for the struct, then malloc space for the array, 
//store the returned address for the array in the struct

void matrix_free(matrix* mat);  //requires two frees

void set_element(matrix* mat, int row, int col, double val);

//to convert from (row, col) to index: int index = (row - 1)*cols + col - 1;
double get_element(matrix* mat, int row, int col);

matrix* multiply(matrix* left, matrix* right);

void display(matrix* mat);

matrix* matrix_malloc(int num_rows, int num_cols)
{
	matrix* struc = (matrix*)malloc(sizeof(matrix));
	double* array = (double*)malloc(sizeof(double)*(num_rows*num_cols)));
	
	struc->num_rows = num_rows;
	struc->num_cols = num_cols;
	
	struc->elements = array;
	
	return struc;
}

void matrix_free(matrix* mat)
{
	free(mat->elements);
	free(mat);
}

void set_element(matrix* mat, int row, int col, double val)
{
	int index = (row - 1)*mat->num_cols + col - 1;
	mat->elements[index] = val;
}

double get_element(matrix* mat, int row, int col)
{
	int index = (row - 1)*mat->num_cols + col - 1;
	return mat->elements[index];
	
}

//left cols has to be the same as right rows for matrix multiplication
matrix* multiply(matrix* left, matrix* right)
{
	int left_rows = left->num_rows;
	int left_cols = left->num_cols;
	int right_rows = right->num_rows;
	int right_cols = right->num_cols;
	matrix* result = matrix_malloc(left_rows, right_cols);
	
	for (int i = 1; i <= left_rows; i++)
	{
		for (int j = 1; j <= right_cols; j++)
		{
			double val = 0;
			for (int k = 1; k <= left_cols; k++)
			{
				double element_left = get_element(left, i, k);
				double element_right = get_element(right, k, j);
				double mul = element_left * element_right;
				val += mul;
			}
			set_element(result, i, j, val);
		}
	}
	
	return result;
}

void display(matrix* mat)
{
    //printf("%d ", mat->num_rows);
    //printf("%d ", mat->num_cols);
    for(int i = 1; i <= mat->num_rows; i++)
    {
            for(int k = 1; k <= mat->num_cols; k++)
            {
                    printf("%f              ", get_element(mat, i, k));
            }
            printf("\n");
    }
}
