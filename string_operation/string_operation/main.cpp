#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define N 10

int oeprate_words()
{
	char s1[N] = "abcdefghi";
	char s2[N] = "jklmnopqr";
	char s3[N * 2] = "stuvw?";
	char s4[N] = "ab?cd?ef?";
	char *s5;
	int  ret;

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

	/* COMPARE FUNCTIONS */
	{
		// compare s2 to s1
		// no follow by locale
		// return lager than   0 if s2 >  s1
		// return              0 if s2 == s1
		// return smaller than 0 if s2 <  s1
		ret = strcmp(s2, s1);

		// compare s2 to s1 specified num of word
		// no follow by locale
		// return lager than   0 if s2 >  s1
		// return              0 if s2 == s1
		// return smaller than 0 if s2 <  s1
		ret = strncmp(s2, s1, 3);

		// compare s2 to s1
		// follow by locale
		// return lager than   0 if s2 >  s1
		// return              0 if s2 == s1
		// return smaller than 0 if s2 <  s1
		ret = strcoll(s2, s1);

		// change locale s1 to s2
		strxfrm(s2, s1, N);
	}

	// separate s4 by specified word
	// when next stage, specified NULL 
	s5 = strtok(s4, "?");
	s5 = strtok(NULL, "?");

	// length of string 
	// count from head to \0
	ret = strlen(s3);

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
		//memcpy(i1, i2, sizeof(int) * 2);

		// operate array
		// copy i2 to i2 specified num of word
		// enable to overlap between words
		//memmove(&i2[0], &i2[1], sizeof(int) * 5);
	}

	/* COMPARE FUNCTIONS */
	{
		// compare i2 to i1
		// return lager than   0 if i2 >  i1
		// return              0 if i2 == i1
		// return smaller than 0 if i2 <  i1
		ret = memcmp(i2, i1, sizeof(int) * 4);
	}

	// set data to array specified num from to
	memset(i1, 0, sizeof(int)*N);

	return 0;
}

int main()
{
	char *a = "bob 4 men";
	char b[N * 3] = "1,2,3,4,5,6,7,8,9,\n1,";
	char name[N];
	int  age;
	char sex[N];
	//operate_array();
	oeprate_words();
	//sscanf(a, "%s %d %s", name, &age, sex);
	//a = strtok(b, ",");
	//for (int i = 0; i < 10; i++)
	//{
	//	a = strtok(NULL, ",");
	//}

	return 0;
}
