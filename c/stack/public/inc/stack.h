#ifndef _STACK_H_INCLUDED_
#define _STACK_H_INCLUDED_

typedef struct sd 
{
    void *Data;
    size_t DataSize;
}Data_t;

typedef struct stack
{
    /* data and data size trying to make it as generic as possible */
    struct sd *Stack;
    /* 
     * if top_ == -1 => underflow 
     * if top_ == sz-1 => full 
     * */
    int   StackTop;
    int   StackSize;
}DSStack_t;

typedef enum DS_ErrorCodes_t 
{
    DS_SUCCESS              =    0,
    DS_STACK_UNDERFLOW      =   -1,
    DS_STACK_OVERFLOW       =   -2,
    DS_OOM                  =   -3,
    DS_INVALID              =   -4

}DS_ErrorCodes_t;


DS_ErrorCodes_t DSStack_init( DSStack_t * const stack, int stack_size );
DS_ErrorCodes_t DSStack_destroy( DSStack_t * const stack );
DS_ErrorCodes_t DSStack_push( DSStack_t * const stack, const void * const data, const size_t dataSize );
DS_ErrorCodes_t DSStack_pop( DSStack_t * const stack, void *data, size_t *dataSize );



#endif
