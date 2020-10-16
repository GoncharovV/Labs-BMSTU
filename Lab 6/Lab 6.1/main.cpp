#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int* n, int* m);
int** createMatrix(int n, int m);
void inputMatrix(int** matrix, int n, int m);
void freeMatrix(int** matrix, int n);
void printMatrix(int** matrix, int n, int m);
void transposeMatrix(int** matrix, int n, int m);
int min(int a, int b);

int main()
{
	int n, m;
	getMatrixSize(&n, &m);

	int** matrix = createMatrix(n, m);

	inputMatrix(matrix, n, m);

	transposeMatrix(matrix, n, m);

	printMatrix(matrix, n, m);

	freeMatrix(matrix, n);

	return 0;
}

void getMatrixSize(int* n, int* m)
{
	printf("Insert matrix size N and M via space: ");
	scanf_s("%d", n);
	scanf_s("%d", m);
}

int** createMatrix(int n, int m)
{
	int** matrix = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(m * sizeof(int));
	}

	return matrix;
}

void inputMatrix(int** matrix, int n, int m)
{
	printf("Insert matrix: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &matrix[i][j]);
		}
	}
}

void transposeMatrix(int** matrix, int n, int m)
{
	n = min(n, m);
	m = min(n, m);

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - i - 1; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n - j - 1][m - i - 1];
			matrix[n - j - 1][m - i - 1] = temp;
		}
	}
}

void printMatrix(int** matrix, int n, int m)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}
	
	free(matrix);
}

int min(int a, int b)
{
	int c = a;

	if (c > b)
		c = b;

	return c;
}