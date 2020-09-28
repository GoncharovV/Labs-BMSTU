#include <stdio.h>

int main()
{
	// variant 0
	int count;
	printf("Insert count of numbers\n");
	scanf_s("%d", &count);

	int min = ((2 << 29) - 1) * 2 + 1;
	int max = -min;

	int indexOfMax = 0;

	int *arr = new int[count];

	for (int i = 0; i < count; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] > max)
		{
			indexOfMax = i;
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int sum = 0;
	double d = (max + min) / 2.0;
	if (indexOfMax == count - 1)
	{
		printf("Sum is 0");
	}
	else
	{
		for (int i = indexOfMax + 1; i < count; i++)
		{
			if (arr[i] > d)
				sum += arr[i];
		}
	}
	
	printf("Sum is %d", sum);

	getchar();
	getchar();
	return 0;
}