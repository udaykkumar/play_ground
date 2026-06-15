#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

#define DSTrue  1
#define DSFalse 0

static DSVertex_t* DSGraph_AddVertex(int vertex)
{
	DSVertex_t *n = calloc(1, sizeof(DSVertex_t));
	if (n)
		n->sd.Vertex = vertex;

	// OOM ??
	return n;
}

static int DSGraph_ExistsPath(DSVertex_t *v, int x)
{
	if (v == NULL)
		return DSFalse;

	if (v->sd.Vertex == x)
	{
		fprintf(stdout, " %d", v->sd.Vertex);
		return DSTrue;
	}
	else
	{
		DSVertex_t *ConnectedVertices = v->Connections;
		while (ConnectedVertices)
		{
			if (DSGraph_ExistsPath(ConnectedVertices, x) == DSTrue)
			{
				fprintf(stdout, " %d", v->sd.Vertex);
				return DSTrue;
			}
		}
	}

	return DSFalse;

}
DS_ErrorCodes_t DSGraph_GetPath(DSGraph_t *const graph, const int x,
		const int y)
{
	/* We need this to be non zero and non Null */
	if (graph && x > 0 && y > 0)
	{
		/* x and y must be within range */
		if (graph->NoOfVertices > x && graph->NoOfVertices > y)
		{
			if (graph->Vertices[x])
			{
				if (graph->Vertices[x]->Connections)
				{
					DSVertex_t *ConnectedVertices =
							graph->Vertices[x]->Connections;
					while (ConnectedVertices)
					{
						if (DSGraph_ExistsPath(ConnectedVertices, y) == DSTrue)
							return DS_SUCCESS;
					}
				}
			}
		}
	}
	return DS_INVALID;
}

DS_ErrorCodes_t DSGraph_Init(DSGraph_t *const graph, const int vertices)
{
	/* Again we'll make sure we have correct inputs */
	if (graph && vertices > 0)
	{
		/* we'll reser everything before we proceed */
		memset(graph, 0x00, sizeof(DSGraph_t));

		/* Graph is a array of Vertices, This is base of array */
		graph->Vertices = calloc(vertices + 1 /* 0 is invalid */,
				sizeof(DSVertex_t));
		if (graph->Vertices)
		{
			for (int i = 0; i <= vertices; i++)
			{
				/* initialize memory for each vertex */
				graph->Vertices[i] = calloc(1, sizeof(Data_t));

				// Revert those Callocs TODO
				if (!graph->Vertices[i])
					return DS_OOM;

				graph->Vertices[i]->sd.Vertex = i;
			}
			graph->NoOfVertices = vertices;
			return DS_SUCCESS;
		}
		return DS_OOM;
	}

	/* Get Out */
	return DS_INVALID;
}

DS_ErrorCodes_t DSGraph_AddPath(DSGraph_t *const graph, const int x,
		const int y)
{
	int retVal = DS_INVALID;

	if (graph && x > 0 && y > 0)
	{
		if (x < graph->NoOfVertices && graph->Vertices[x]->sd.Vertex == x)
		{
			if (graph->Vertices[x]->Connections == NULL)
			{
				graph->Vertices[x]->Connections = DSGraph_AddVertex(y);
				return DS_SUCCESS;
			}

			DSVertex_t *ConnectedVertices = graph->Vertices[x]->Connections;
			while (ConnectedVertices->Connections)
			{
				if (ConnectedVertices->sd.Vertex == y)
					return DS_ALREADY_CONNECTED;
				ConnectedVertices = ConnectedVertices->Connections;
			}
			ConnectedVertices->Connections = DSGraph_AddVertex(y);

		}
		else
		{
			retVal = DS_INVALID;
		}
	}
	return retVal;
}

void DSGraph_DumpGraph(DSGraph_t g)
{
	for (int i = 0; i < g.NoOfVertices; i++)
	{
		fprintf( stdout, "Vertex Id [ %d ]  ", g.Vertices[i]->sd.Vertex);
		if (g.Vertices[i]->Connections)
		{
			DSVertex_t *v = g.Vertices[i]->Connections;
			while (v)
			{
				fprintf(stdout, " %d ", v->sd.Vertex);
				v = v->Connections;
			}
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "\n");
}
