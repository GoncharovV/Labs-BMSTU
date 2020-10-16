#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int* n, int* m);
int** createMatrix(int n, int m);
void inputMatrix(int** matrix, int n, int m);
void freeMatrix(int** matrix, int n);
void printMatrix(int** matrix, int n, int m);

int findLineWithMinUnderMainDiag(int** matrix, int n, int m);
void changeMatrinx(int** matrix, int n, int m, int inx);

int main()
{
	int n, m;
	getMatrixSize(&n, &m);

	int** matrix = createMatrix(n, m);

	inputMatrix(matrix, n, m);

	int inx = findLineWithMinUnderMainDiag(matrix, n, m);

	changeMatrinx(matrix, n, m, inx);

	printMatrix(matrix, (n - 1), m);

	freeMatrix(matrix, n - 1);

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

int findLineWithMinUnderMainDiag(int** matrix, int n, int m)
{
	int minN = 1, minM = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m - i - 1; j++)
		{
			if (matrix[i][j] < matrix[minN][minM])
			{
				minN = i;
				minM = j;
			}
		}
	}

	return minN;
}

void changeMatrinx(int** matrix, int n, int m, int inx)
{
	for (int i = inx; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = matrix[i + 1][j];
		}
	}

	matrix = (int**)realloc(matrix, (n - 1) * sizeof(int*));
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