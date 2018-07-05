#include <stdio.h>
#define N 10

void bubble_sort(int *a, int n);

int main()
{
	int a[N] = { 23,6,9,3,2,6,7,89,2,5 };

	bubble_sort(a, N);
	for (int i = 0; i < N; i++) {
		printf(" %d ", a[i]);
	}
	printf("\n");


	return 0;
}

void bubble_sort(int *a, int n)
{
	int tmp;
	bool fin;
	while (1) {
		fin = true;
		for (int i = 0; i < N - 1; i++) {
			if (a[i] > a[i + 1]) {
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				fin = false;
			}
		}
		if (fin) break;
	}
}