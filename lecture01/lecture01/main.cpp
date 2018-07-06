#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double integral1(double a, double b, double n, double (*func)(double))
{
	double dx, sum, ans;
	dx = (b - a) / n;
	sum = 0.0;
	for (int i = n-1; i > 0; i--) {
		sum += func(a + (double)i*dx)*dx;
	}

	return sum;
}

double integral2(double a, double b, double n, double (*func)(double))
{
	double dx, sum, ans;
	dx = (b - a) / n;
	sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += func(a + (double)i*dx)*dx;
	}

	return sum;
}

double fx(double x)
{
	return x*sin(x);
}

int main()
{
	double a, b, n;
	double integ;
	a = 0.0;
	b = M_PI;
	n = 16384;
	printf("a: %lf b: %lf n: %lf\n", a, b, n);

	printf("integral1: %lf\n", integral1(a, b, n, fx));
	printf("integral2: %lf\n", integral2(a, b, n, fx));

	return 0;
}