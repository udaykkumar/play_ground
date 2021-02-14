#include <stdio.h>

#include "queue.h"


#define MAX_QUEUE_SIZE  10
int main(int ac, char **av)
{
    DSQueue_t q;

    DS_ErrorCodes_t e;
    e = DSQueue_init( &q,  MAX_QUEUE_SIZE );
    if( DS_SUCCESS != e )
    {
        fprintf( stderr, " DSStack_init Failure %d\n", e );
        return (e);
    }

    int i = 0;
    for( i = 0, e = DS_SUCCESS ; e == DS_SUCCESS ; i ++ )
    {
        fprintf( stdout, "EnQueueing %d \n", i );
        e = DSQueue_enqueue( &q, &i, sizeof(i));
    }

    int n;
    size_t size;
    for( e = DS_SUCCESS ; e == DS_SUCCESS ; )
    {
        e = DSQueue_dequeue( &q, &n, &size);
        if( e == DS_SUCCESS )
        {
            fprintf( stdout, "Dequeuing %d \n", n );
        }
    }

    return (0);
}
