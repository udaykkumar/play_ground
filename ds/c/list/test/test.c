#include <stdio.h>

#include "list.h"

#define MAX_LIST_SIZE  10
int main(int ac, char **av)
{
	DS_ErrorCodes_t e;
	DSList_t *list = NULL;
	int i = 0;
	for (i = 0, e = DS_SUCCESS; e == DS_SUCCESS && i < 10; i++)
	{
		fprintf(stdout, "adding %d to Head\n", i);
		e = DSList_addHead(&list, &i, sizeof(i));
	}

	DSList_PrintInt(list);

	for (i = 0, e = DS_SUCCESS; e == DS_SUCCESS && i < 10; i++)
	{
		fprintf(stdout, "adding %d to Tail\n", i);
		e = DSList_addTail(&list, &i, sizeof(i));
	}

	DSList_PrintInt(list);

	fprintf(stdout, "Deleting 5 Items from Head \n");
	for (i = 0, e = DS_SUCCESS; e == DS_SUCCESS && i < 5; i++)
	{
		int n;
		size_t size;
		e = DSList_DelHead(&list, &n, &size);
	}

	DSList_PrintInt(list);

	fprintf(stdout, "Reversing list \n");
	DSList_Reverse(&list);
	DSList_PrintInt(list);

	return (0);
}
