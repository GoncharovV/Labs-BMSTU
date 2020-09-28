#include <stdio.h>
#define ARRAY_SIZE 5

void insertArray(int arr[]);
void findIndexOfMax(int arr[], int* indexOfMax);
void findIndexOfMin(int arr[], int* indexOfMin);

int calcSum(int arr[], int* indexOfMax, int* indexOfMin);

int main()
{
	// variant 0

	int indexOfMax = 0;
	int indexOfMin = 0;

	int arr[ARRAY_SIZE];

	insertArray(arr);

	findIndexOfMax(arr, &indexOfMax);

	findIndexOfMin(arr, &indexOfMin);

	printf("Sum is %d", calcSum(arr, &indexOfMax, &indexOfMin));

	getchar();
	getchar();
	return 0;
}

void insertArray(int arr[])
{
	printf("Insert array:\n");

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void findIndexOfMax(int arr[], int* indexOfMax)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (arr[i] > arr[*indexOfMax])
		{
			*indexOfMax = i;
		}
	}
}

void findIndexOfMin(int arr[], int* indexOfMin)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (arr[i] < arr[*indexOfMin])
		{
			*indexOfMin = i;
		}
	}
}

int calcSum(int arr[], int* indexOfMax, int* indexOfMin)
{
	int sum = 0;
	double d = (arr[*indexOfMax] + arr[*indexOfMin]) / 2.0;

	if (*indexOfMax == ARRAY_SIZE - 1)
	{
		printf("Sum is 0");
	}
	else
	{
		for (int i = *indexOfMax + 1; i < ARRAY_SIZE; i++)
		{
			if (arr[i] > d)
				sum += arr[i];
		}
	}

	return sum;
}
