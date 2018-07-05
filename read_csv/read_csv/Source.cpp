#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	char *file = "./Text.txt";
	int a[10], b[10];
	int i = 0;

	if ((fp = fopen(file, "r")) == NULL) { exit(1); }

	for(int i = 0; i < 10; i++)
		fscanf(fp, "%d,", &a[i]);
	for(int i = 0; i < 10; i++)
		fscanf(fp, "%d,", &b[i]);

	fclose(fp);
	return 0;
}