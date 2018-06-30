#include <stdio.h>

int main()
{
	char name[10];

	printf("input name: ");
	scanf("%s", &name);
	printf("hello, world %s\n", name);

	system("pause");
	return 0;
}