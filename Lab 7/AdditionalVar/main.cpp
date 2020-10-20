#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int* n, int* m);

int** createMatrix(int n, int m);
void freeMatrix(int** matrix, int n);

void inputMatrix(int** matrix, int n, int m);
void printMatrix(int** matrix, int n, int m);

void spiral_sort(int** matrix, int n, int m);
void bubbleSort(int* arr, int len);
int* parseMatrix(int** matrix, int n, int m);

int main()
{
	int n, m;
	getMatrixSize(&n, &m);

	int** matrix = createMatrix(n, m);
	inputMatrix(matrix, n, m);

	spiral_sort(matrix, n, m);

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

void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void spiral_sort(int** matrix, int n, int m)
{
	int* arr = parseMatrix(matrix, n, m);

	bubbleSort(arr, n * m);

	int inx = 0;
	int count = n * m;
	int top = 0, left = 0, right = m - 1, down = n - 1;

	while (inx < count)
	{
		for (int i = left; i <= right && inx < count; i++)
		{
			matrix[top][i] = arr[inx];
			inx++;
		}
		top++;

		for (int i = top; i <= down && inx < count; i++)
		{
			matrix[i][right] = arr[inx];
			inx++;
		}
		right--;

		for (int i = right; i >= left && inx < count; i--)
		{
			matrix[down][i] = arr[inx];
			inx++;
		}
		down--;

		for (int i = down; i >= top && inx < count; i--)
		{
			matrix[i][left] = arr[inx];
			inx++;
		}
		left++;
	}

	free(arr);
}

int* parseMatrix(int** matrix, int n, int m)
{
	int* arr = (int*)malloc(n * m * sizeof(int));

	int inx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[inx] = matrix[i][j];
			inx++;
		}
	}

	return arr;
}