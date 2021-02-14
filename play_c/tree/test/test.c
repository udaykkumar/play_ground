#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


#define MAX_TREE_LIST  10
int main(int ac, char **av)
{
    DSTree_t *treeHead = NULL;
    DS_ErrorCodes_t  e = DS_SUCCESS;
    int inputArray[] = { 10, 21, 4, 6 ,29, 19, 0, -1, -765, 126, 3, 18 };
    for( int i = 0; i < sizeof(inputArray)/ sizeof(inputArray[0]); i ++ )
    {
        fprintf( stdout, "Inserting %d \n", inputArray[i] );
        e = DSTree_addChild( &treeHead, &inputArray[i], sizeof(inputArray[i]));
        if(e != DS_SUCCESS)
        {
            fprintf( stderr, "Failed DSTree_addChild %d %d\n", inputArray[i], e );
            exit(0);
        }   
    }

    fprintf( stdout, "\nTravel Preorder \n");
    DSTree_TraversePreOrder( treeHead );

    fprintf( stdout, "\nTravel PostOrder \n");
    DSTree_TraversePostOrder( treeHead );

    fprintf( stdout, "\nTravel Inorder \n");
    DSTree_TraverseInOrder( treeHead );
    fprintf( stdout, "\n");


    return (0);
}
