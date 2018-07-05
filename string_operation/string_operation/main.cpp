#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define N 10

int oeprate_words()
{
	char s1[N] = "abcdefghi";
	char s2[N] = "jklmnopqr";
	char s3[N * 2] = "stuvw?";

	for (int i = 0; i < N; i++)
		printf("%d %c\n", i, s1[i]);

	/* COPY FUNCTIONS */
	{
		// operate words (end of '\0')
		// copy s2 to s1 specified num of word
		strncpy(s1, s2, 2);

		// operate words (end of '\0')
		// copy s2 to s1
		strcpy(s1, s2);
	}

	/* CONNECT FUNCTIONS */
	{
		// operate words
		// s3 is connected to s2 specified num of word
		strncat(s3, s2, 3);

		// operate words
		// s3 is connected to s1
		strcat(s3, s1);
	}

	return 0;
}

int operate_array()
{
	int i1[N] = { 0,1,2,3,4,5,6,7,8,9 };
	int i2[N] = { 10,11,12,13,14,15,16,17,18,19 };
	int ret;

	/* CONNECT FUNCTIONS */
	{
		// operate array
		// copy i2 to i1 specified num of word
		// disable to overlap between words
		memcpy(i1, i2, sizeof(int) * 2);

		// operate array
		// copy i2 to i2 specified num of word
		// enable to overlap between words
		memmove(&i2[0], &i2[1], sizeof(int) * 5);
	}

	/* COMPARE FUNCTIONS */
	{
		ret = memcmp(i1, i2, 1);
	}

	return 0;
}

int main()
{
	operate_array();
	oeprate_words();
	return 0;
}
