#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


#define DSTrue  1
#define DSFalse 0

static inline int DSQueue_IsFull( const DSQueue_t * const queue )
{
    /* Front is QSize and Read is still -1, This is easy condition.         */
    return ( queue->Front == queue->QueueSize ) ? DSTrue : DSFalse ; 

}

static inline int DSQueue_IsEmpty(const DSQueue_t * const queue )
{
    /*  
        This is the only condition we'll use,
        During Dequeue we'll these values after deleting 
        single remaining entry in queie vitz Front = Rear 
    */
    return ( queue->Rear == -1 ) ? DSTrue : DSFalse ;
}

DS_ErrorCodes_t DSQueue_init( DSQueue_t * const queue, int queueSize )
{
    /* default is invalid arguments */
    int retVal = DS_INVALID;

    /* 
       This has to be true
       1. Queue is a valid pointer
       2. QueueSize is strictly positive 
     */
    if( queue && queueSize > 0)
    {
        /* Clear it before we initialize */
        memset(queue, 0x00, sizeof(DSQueue_t));

        /* calloc is kind of better */
        if((queue->Queue = calloc(queueSize, sizeof(Data_t))))
        {
            /* initialize with default values */
            queue->Rear  = -1;
            queue->Front =  0;
            queue->QueueSize = queueSize;
            retVal = DS_SUCCESS;
        }
        else
        {
            retVal = DS_OOM;
        }
    }

    return retVal;
}

DS_ErrorCodes_t DSQueue_destroy( DSQueue_t * const queue )
{
    /* default is invalid arguments */
    int retVal = DS_INVALID;

    /* sanity */
    if( queue )
    {
        /* Delete all elements one by one */
        int        i = 0;
        Data_t *dPtr = queue->Queue;
        for( i = 0 ; i < queue->QueueSize; i ++ )
        {
            free( dPtr[i].Data );
            dPtr[i].Data = NULL;
        }
    
        /* Delete Queue array */
        free( queue->Queue );
        queue->Queue = NULL;

        /* Reset Values */
        queue->Rear = 0;
        queue->Front = 0;
        queue->QueueSize = 0;

        /* Done */
        retVal = DS_SUCCESS;
    }
    return retVal;
}

DS_ErrorCodes_t DSQueue_enqueue( DSQueue_t * const queue, const void * const data, const size_t dataSize )
{
    /* default is invalid arguments */
    int retVal = DS_INVALID;

    /* we nee a proper pointer to queue and data 
        and dataSize <= 0 is invalid for us */
    if( queue && data && dataSize > 0 )
    {
        /* Check Full Condition before enqueuing */
        if( !DSQueue_IsFull(queue) )
        {
            /* insert where Front is pointed to */
            if((queue->Queue[ queue->Front ].Data = calloc(1, sizeof(Data_t))))
            {
                memcpy(queue->Queue[ queue->Front ].Data, data, dataSize);
                queue->Queue[ queue->Front ].DataSize = dataSize; 
                
                if( queue->Rear == -1 )
                    queue->Rear = 0;

                /* increment Front to next element */
                queue->Front ++;

                retVal = DS_SUCCESS;
            }
            else
            {
                retVal =  DS_OOM;
            }
        }
        else
        {
            retVal = DS_QUEUE_OVERFLOW;
        }
    }
    return retVal;
}

DS_ErrorCodes_t DSQueue_dequeue( DSQueue_t * const queue, void *data, size_t *dataSize )
{
    /* default is invalid arguments */
    int retVal = DS_INVALID;
    
    /* sanity */
    if( queue && data )
    {
        /*  Make sure it is not empty */
        if( !DSQueue_IsEmpty(queue) ) 
        {
            /* Retrieve Data from Queue */
            *dataSize = queue->Queue[ queue->Rear ].DataSize;
            memcpy( data, queue->Queue[ queue->Rear ].Data , *dataSize ); 


            /* free data */
            free( queue->Queue[ queue->Rear ].Data );
            queue->Queue[ queue->Rear ].Data = NULL;
            queue->Queue[ queue->Rear ].DataSize = 0;

            /* Nothing left we'll reset queue */
            if( queue->Front == queue->Rear || queue->Rear == queue->QueueSize - 1)
            {
                queue->Front = 0;
                queue->Rear  = -1;
            }
            else
            {
                queue->Rear ++;
            }

            retVal = DS_SUCCESS;

        }
        else
        {
            retVal = DS_QUEUE_UNDERFLOW;
        }
    }
    return retVal;
}


