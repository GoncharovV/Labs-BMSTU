#include <stdio.h>
#include <stdlib.h>

void inputCount(int* count);
void inputArray(int* arr, int size);
void sortArray(int arr[], int size);
void shiftArray(int arr[], int size);
void printArray(int* arr, int size);

int findFirstNonnegative(int arr[], int size);

int main() 
{
	// variant 2 (0 + -)
	int n;
	inputCount(&n);

	int* arr = (int*)malloc(n * sizeof(int));
	inputArray(arr, n);

	sortArray(arr, n);
	shiftArray(arr, n);

	printArray(arr, n);

	free(arr);
}

void inputCount(int* count)
{
	printf("Insert count:\n");
	scanf_s("%d", count);
}

void inputArray(int* arr, int size)
{
	for (int* p = arr; p - arr < size; p++)
	{
		scanf_s("%d", p);
	}
}

void sortArray(int arr[], int size)
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

int findFirstNonnegative(int arr[], int size)
{
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 0)
		{
			index = i;
			break;
		}			
	}
	return index;
}

void shiftArray(int arr[], int size)
{
	int indexOfNonnegative = findFirstNonnegative(arr, size);

	if (indexOfNonnegative > 0)
	{
		int* buffer = (int*)malloc(indexOfNonnegative * sizeof(int));

		for (int i = 0; i < indexOfNonnegative; i++)
			buffer[i] = arr[i];

		for (int i = 0; i < size - indexOfNonnegative; i++)
			arr[i] = arr[i + indexOfNonnegative];

		for (int i = 0; i < indexOfNonnegative; i++)
			arr[size - indexOfNonnegative + i] = buffer[i]; 

		free(buffer);
	}
}

void printArray(int* arr, int size)
{
	for (int* p = arr; p - arr < size; p++)
		printf("%d ", *p);

	printf("\n");
}