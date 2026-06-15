#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define MAX_VERTICES 3
int main(int ac, char **av)
{
	DSGraph_t g;
	DSGraph_Init(&g, MAX_VERTICES);
	DSGraph_DumpGraph(g);

	for (int i = 1; i <= MAX_VERTICES; i++)
		for (int j = 1; j <= MAX_VERTICES; j++)
		{
			fprintf(stdout, "Adding path from %d to %d \n", i, j);
			DSGraph_AddPath(&g, i, j);
		}

	DSGraph_DumpGraph(g);

	for (int i = 1; i <= MAX_VERTICES; i++)
		for (int j = 1; j <= MAX_VERTICES; j++)
		{
			fprintf( stdout, "\nGetPath from %d to %d\n ", i, j);
			DSGraph_GetPath(&g, i, j);
			fprintf( stdout, "\n");
		}
	return (0);
}
