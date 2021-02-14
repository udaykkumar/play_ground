#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


#define DSTrue  1
#define DSFalse 0


static int DSTree_CompareData( const void * const TreeData, const size_t TreeDataSize, const void * const NewData, const size_t NewDataSize, int KeepSimple )
{
    if( KeepSimple )
    {
        return *( int *) TreeData - *( int *) NewData; 
    }
    else
    {

        /** if the sizes are equal we'll compare the contents */
        if( TreeDataSize == NewDataSize )
        {
            return memcmp( NewData, TreeData, TreeDataSize);
        }

        /* Difference is sizes would do otherwise */
        return   NewDataSize  - TreeDataSize;
    }
}

static DSTree_t * DSTree_GetNode( const void * const data, const size_t dataSize )
{
    DSTree_t *Node = calloc(1, sizeof(DSTree_t));
    if(Node)
    {
        Node->Data.Data = calloc(1, sizeof(dataSize));
        if( Node->Data.Data )
        {       
            memcpy( Node->Data.Data, data, dataSize );
            Node->Data.DataSize = dataSize;
            return Node;
        }
    }
    return NULL;
}
DS_ErrorCodes_t DSTree_addChild( DSTree_t **treeHead, const void * const data, const size_t dataSize )
{
    /* default is invalid */
    int retVal = DS_INVALID;

    /* Basic validation */
    if(data && dataSize > 0)
    {
        /* root of recursion we'll return from here */
        if(*treeHead == NULL)
        {
            DSTree_t *node = DSTree_GetNode(data, dataSize);
            if(node)
            {
                *treeHead = node;
                retVal = DS_SUCCESS;
            }
            else
            {
                retVal = DS_OOM;
            }
        }
        else
        /* the usual Comparision stuff */
        {
           int TreeCompare = DSTree_CompareData( (*treeHead)->Data.Data, (*treeHead)->Data.DataSize, data, dataSize , 1 );
           if( TreeCompare < 0 )
           {
               return DSTree_addChild( &(*treeHead)->Left, data, dataSize );
           }
           else
           {    
               return DSTree_addChild( &(*treeHead)->Right, data, dataSize );
           }
        }
    }
    return retVal;
}

void DSTree_TraversePreOrder( DSTree_t *treeHead)
{
    if( treeHead == NULL )
        return ;

    fprintf(stdout, "%d ", *(int *) (treeHead->Data.Data) );
    DSTree_TraversePreOrder(treeHead->Left);
    DSTree_TraversePreOrder(treeHead->Right);

    return ;
}

void DSTree_TraverseInOrder( DSTree_t *treeHead)
{
    if( treeHead == NULL )
        return ;

    DSTree_TraverseInOrder(treeHead->Left);
    fprintf(stdout, "%d ", *(int *) (treeHead->Data.Data) );
    DSTree_TraverseInOrder(treeHead->Right);

    return ;
}

void DSTree_TraversePostOrder( DSTree_t *treeHead )
{
    if( treeHead == NULL )
        return ;

    DSTree_TraversePostOrder(treeHead->Left);
    DSTree_TraversePostOrder(treeHead->Right);
    fprintf(stdout, "%d ", *(int *) (treeHead->Data.Data) );

    return ;
}

