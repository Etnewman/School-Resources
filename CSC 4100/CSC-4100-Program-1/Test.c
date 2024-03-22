
#include "Matrix.h"

matrix* read_file(char* file_name);

int main(int argc, char** argv)
{
	init_mem(4096)
	char* mat_1_file_name = "mat_1.txt";
	matrix* mat_1 = read_file(mat_1_file_name);
	
	return 0;
}

matrix* read_file(char* file_name)
{
	matrix* mat = 0;
	
	int num_rows = 0;
	int num_cols = 0;
	
	FILE* f_matrix = fopen(file_name, "r");
	fscanf(f_matrix, "%d", &num_rows);
	fscanf(f_matrix, "%d", &num_cols);
	mat = matrix_malloc(num_rows, num_cols);
	
	int num_elements = num_rows*num_cols;
	for (int i = 1; i <= num_elements; i++)
	{
		double* elements = mat->elements;
		double element = 0;
		fscanf(f_matrix, "%lf", &element);
		elements[i-1] = element;
		//printf("%.2lf", element);
	}
		
	fclose(f_matrix);
	return mat;
}
