#include <stdio.h>
#include <stdlib.h>

#define CMP_EQUALITY       0x00
#define CMP_L1_NULL        0x01
#define CMP_L1_EMPTY       0x02
#define CMP_L1_UNDEFINED   0x03
#define CMP_L1_GREATER     0x04
#define CMP_L1_LESS        0x08
#define CMP_L2_NULL        0x10
#define CMP_L2_EMPTY       0x20
#define CMP_L2_UNDEFINED   0x30
#define CMP_L2_GREATER     0x40
#define CMP_L2_LESS        0x80

#if !defined(UNDEFINED)
#define UNDEFINED ((void*)1)
#endif

typedef unsigned long long int ulli;
typedef unsigned char uc;

uc compare(char *myList1, char *myList2, ulli * pos)
{
	uc code = CMP_EQUALITY;
	int index = 0;

	if (myList1 == UNDEFINED)
	{
		code = code | CMP_L1_UNDEFINED;
	}
	else if (myList1 == NULL)
	{
		code = code | CMP_L1_NULL;
		if (pos != NULL)
			*pos = 0;
	}
	else if (*(myList1 + 0) == '\0')
	{
		code = code | CMP_L1_EMPTY;
		if (pos != NULL)
			*pos = 0;
	}

	if (myList2 == UNDEFINED)
	{
		code = code | CMP_L2_UNDEFINED;
	}
	else if (myList2 == NULL)
	{
		code = code | CMP_L2_NULL;
		if (pos != NULL)
			*pos = 0;
	}
	else if (*(myList2 + 0) == '\0')
	{
		code = code | CMP_L2_EMPTY;
		if (pos != NULL)
			*pos = 0;
	}

	if (code == CMP_EQUALITY)
	{
		while ((*(myList1 + index) != '\0') &&	// NULL TERMINATOR != NULL
		       (*(myList2 + index) != '\0') &&
		       (*(myList1 + index) != *(myList2 + index)))
		{
			if (pos != NULL)
				*pos = (*pos) + 1;
			index = index + 1;
		}

		if ((*(myList1 + index) == '\0') &&
		    (*(myList2 + index) != '\0'))
		{
			code = code | CMP_L2_GREATER;
		}
		else if ((*(myList1 + index) != '\0') &&
			 (*(myList2 + index) == '\0'))
		{
			code = code | CMP_L1_GREATER;
		}
		else if ((*(myList1 + index) != '\0') &&
			 (*(myList2 + index) != '\0'))
		{
			if (*(myList1 + index) < *(myList2 + index))
				code = CMP_L1_LESS | CMP_L2_GREATER;
			else
				code = CMP_L2_LESS | CMP_L1_GREATER;
		}

	}

	return (code);
}

int main(int argc, char **argv)
{
	ulli diff = 0;
	char *str1 = NULL;
	char *str2 = NULL;

	if (argc >= 2)
		str1 = *(argv + 1);

	if (argc >= 3)
		str2 = *(argv + 2);

	uc status = compare(str1, str2, &diff);

	fprintf(stdout, "status: %02hhx, diff: %llu\n", status, diff);

	return (0);
}
