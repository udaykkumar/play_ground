#include <stdio.h>

#include "stack.h"

#define MAX_STACK_SIZE  10
int main(int ac, char **av)
{
	DSStack_t s;

	DS_ErrorCodes_t e;
	e = DSStack_init(&s, MAX_STACK_SIZE);
	if (DS_SUCCESS != e)
	{
		fprintf( stderr, " DSStack_init Failure %d\n", e);
		return (e);
	}

	int i = 0;
	for (i = 0, e = DS_SUCCESS; e == DS_SUCCESS; i++)
	{
		fprintf( stdout, "Pushing %d to stack\n", i);
		e = DSStack_push(&s, &i, sizeof(i));
	}

	int n;
	size_t size;
	for (e = DS_SUCCESS; e == DS_SUCCESS;)
	{
		e = DSStack_pop(&s, &n, &size);
		if (e == DS_SUCCESS)
		{
			fprintf( stdout, "Popped %d from Stack \n", n);
		}

	}

	return (0);
}
