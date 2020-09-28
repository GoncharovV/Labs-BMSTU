#include <stdio.h>
#define ARRAY_SIZE 5

void insertArray(int arr[]);

int  findIndexOfMax(int arr[]);
int findIndexOfMin(int arr[]);
int calcSum(int arr[], int indexOfMax, int indexOfMin);

int main()
{
	// variant 0

	int arr[ARRAY_SIZE];

	insertArray(arr);

	int indexOfMax = findIndexOfMax(arr);

	int indexOfMin = findIndexOfMin(arr);

	printf("Sum is %d", calcSum(arr, indexOfMax, indexOfMin));

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

int  findIndexOfMax(int arr[])
{
	int indexOfMax = 0;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (arr[i] > arr[indexOfMax])
		{
			indexOfMax = i;
		}
	}

	return indexOfMax;
}

int findIndexOfMin(int arr[])
{
	int indexOfMin = 0;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (arr[i] < arr[indexOfMin])
		{
			indexOfMin = i;
		}
	}

	return indexOfMin;
}

int calcSum(int arr[], int indexOfMax, int indexOfMin)
{
	int sum = 0;
	double d = (arr[indexOfMax] + arr[indexOfMin]) / 2.0;

	if (indexOfMax == ARRAY_SIZE - 1)
	{
		printf("Sum is 0");
	}
	else
	{
		for (int i = indexOfMax + 1; i < ARRAY_SIZE; i++)
		{
			if (arr[i] > d)
				sum += arr[i];
		}
	}

	return sum;
}