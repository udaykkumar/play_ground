#ifndef _graph_H_INCLUDED_
#define _graph_H_INCLUDED_

typedef struct data 
{
    unsigned int Vertex;

}Data_t ;

typedef struct vertex 
{
    Data_t sd;
    struct vertex *Connections;
} DSVertex_t;

typedef struct graph
{
    DSVertex_t **Vertices;
    int NoOfVertices;
}DSGraph_t;

typedef enum DS_ErrorCodes_t 
{
    DS_SUCCESS             =    0,
    DS_GRAPH_UNDERFLOW     =   -1,
    DS_GRAPH_OVERFLOW      =   -2,
    DS_OOM                 =   -3,
    DS_INVALID             =   -4,
    DS_ALREADY_CONNECTED   =    5

}DS_ErrorCodes_t;



DS_ErrorCodes_t DSGraph_Init( DSGraph_t * const graph, const int vertices );
DS_ErrorCodes_t DSGraph_AddPath( DSGraph_t * const graph, const int x, const int y );
DS_ErrorCodes_t DSGraph_GetPath( DSGraph_t * const graph, const int x, const int y );
void DSGraph_DumpGraph( DSGraph_t g );


#endif
