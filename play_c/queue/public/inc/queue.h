#ifndef _QUEUE_H_INCLUDED_
#define _QUEUE_H_INCLUDED_

typedef struct sd 
{
    void *Data;
    size_t DataSize;
}Data_t;

typedef struct queue
{
    /* data and data size trying to make it as generic as possible */
    struct sd *Queue;
    int   Rear, Front;
    int   QueueSize;
}DSQueue_t;

typedef enum DS_ErrorCodes_t 
{
    DS_SUCCESS              =    0,
    DS_QUEUE_UNDERFLOW      =   -1,
    DS_QUEUE_OVERFLOW       =   -2,
    DS_OOM                  =   -3,
    DS_INVALID              =   -4

}DS_ErrorCodes_t;


DS_ErrorCodes_t DSQueue_init( DSQueue_t * const queue, int stack_size );
DS_ErrorCodes_t DSQueue_destroy( DSQueue_t * const queue );
DS_ErrorCodes_t DSQueue_enqueue( DSQueue_t * const queue, const void * const data, const size_t dataSize );
DS_ErrorCodes_t DSQueue_dequeue( DSQueue_t * const queue, void *data, size_t *dataSize );



#endif
