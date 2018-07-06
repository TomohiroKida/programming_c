#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

void write_csv(char *fn)
{
	FILE *fp;
	fp = fopen(fn, "w");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			fprintf(fp, "%d,", i * 10 + j);
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void read_csv(char *fn)
{
	FILE *fp;
	char ch;
	char line[N];
	int *a = (int*)malloc(sizeof(int) * N);
	int b = 0;

	fp = fopen(fn, "r");
	while ((ch = fgetc(fp)) != EOF) {
		putchar(ch);
	}
	fseek(fp, 0L, SEEK_SET);
	while (fgets(line, N, fp)) {
		for (int i = 0; i < N; i++) {
			sscanf(line, "%d,", a[i + b]);
		}
		b += N;
		a = (int*)realloc(a, sizeof(int)*b);
	}

	fclose(fp);
}

int main()
{
	char fn[N] = "a.csv";


	//write_csv(fn);
	read_csv(fn);

	return 0;
}