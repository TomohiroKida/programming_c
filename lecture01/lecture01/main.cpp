#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double integral1(double a, double b, double n, double(*func)(double))
{
	double dx, sum, ans;
	dx = (b - a) / n;
	sum = 0.0;
	for (int i = n - 1; i > 0; i--) {
		sum += func(a + (double)i*dx)*dx;
	}

	return sum;
}

double integral2(double a, double b, double n, double(*func)(double))
{
	double dx, sum, ans;
	dx = (b - a) / n;
	sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += func(a + (double)i*dx)*dx;
	}

	return sum;
}

double integral3(double a, double b, double n, double(*func)(double))
{
	double dx, sum, ans;
	dx = (b - a) / n;
	sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += (func(a + (double)i*dx) + func(a + (double)(i + 1)*dx))*dx*0.5;
	}
	return sum;
}

double fx(double x)
{
	return x;// *sin(x);
}
int func(int m, int n, int *c) {}
int main()
{
	double a, b, n;
	int c[10][10];
	double integ;
	func(10, 10, c);
	a = 0.0;
	b = 10;// M_PI;
	n = 16384;
	printf("a: %lf b: %lf n: %lf\n", a, b, n);

	printf("integral1: %.40lf\n", integral1(a, b, n, fx));
	printf("integral2: %.40lf\n", integral2(a, b, n, fx));
	printf("integral3: %.40lf\n", integral3(a, b, n, fx));

	return 0;
}