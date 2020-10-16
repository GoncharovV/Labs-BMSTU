#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int* n, int* m);
int** createMatrix(int n, int m);
void inputMatrix(int** matrix, int n, int m);
void freeMatrix(int** matrix, int n);
void printMatrix(int** matrix, int n, int m);

int min(int a, int b);
void findMaxAndMin(int** matrix, int n, int m, int* maxInx, int* minInx);
void swapElements(int** matrix, int n, int m, int* maxInx, int* minInx);

int main()
{
	int n, m;
	getMatrixSize(&n, &m);

	int** matrix = createMatrix(n, m);

	inputMatrix(matrix, n, m);

	int maxInx[2] = { 0 };
	int minInx[2] = { 0 };

	findMaxAndMin(matrix, n, m, maxInx, minInx);

	swapElements(matrix, n, m, maxInx, minInx);

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

void findMaxAndMin(int** matrix, int n, int m, int* maxInx, int* minInx)
{
	n = min(n, m);
	m = n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] > matrix[maxInx[0]][maxInx[1]])
			{
				maxInx[0] = i;
				maxInx[1] = j;
			}
			if (matrix[i][j] < matrix[minInx[0]][minInx[1]])
			{
				minInx[0] = i;
				minInx[1] = j;
			}
		}
	}
}

void swapElements(int** matrix, int n, int m, int* maxInx, int* minInx)
{
	int temp = matrix[maxInx[0]][maxInx[1]];
	matrix[maxInx[0]][maxInx[1]] = matrix[n - maxInx[1] - 1][m - maxInx[0] - 1];
	matrix[n - maxInx[1] - 1][m - maxInx[0] - 1] = temp;

	temp = matrix[minInx[0]][minInx[1]];
	matrix[minInx[0]][minInx[1]] = matrix[n - minInx[1] - 1][m - minInx[0] - 1];
	matrix[n - minInx[1] - 1][m - minInx[0] - 1] = temp;
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