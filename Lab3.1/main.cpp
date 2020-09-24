#include <stdio.h>
#include <math.h>

int main()
{
	double accuracy;
	printf("Enter accuracy:\n");
	scanf_s("%lf", &accuracy);

	double sum = 0;
	double factorial = 1;
	double pastSum = -1;
    
	for (int i = 1; fabs(sum - pastSum) > accuracy; i++)
	{
		factorial = factorial * i;
		pastSum = sum;

		sum += 1 / factorial;
	}

	printf("%lf", sum);

	getchar();
	getchar();
	return 0;
}

