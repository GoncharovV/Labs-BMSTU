#include <stdio.h>
#include <math.h>

void infRow();
void square();
double calcSum(double h);

double a, b;

int main()
{
	double accuracy;

	printf("Insert interval via space:\n");
	scanf_s("%lf%lf", &a, &b);

	printf("Insert accuracy:\n");
	scanf_s("%lf", &accuracy);

	double h = (b - a) / 2;
	double sum = 0, oldSum = -10;

	while (fabs(sum - oldSum) > accuracy)
	{
		oldSum = sum;
		sum = calcSum(h);
		h /= 2;
	}

	printf("%lf", sum);

	getchar();
	getchar();
    
	return 0;
}

double calcSum(double h)
{
	double res = 0;

	for (double p = a; p < b; p += h)
	{
		res += h * logl(p);
	}

	return res;
}