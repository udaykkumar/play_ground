typedef struct {
    int *data;
    int stackSize;
    int top;
    int min;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *stack = calloc(1, sizeof(MinStack));
    stack->data = calloc(1, maxSize * sizeof(int));
    stack->top = -1;
    stack->min = -1;
    stack->stackSize = maxSize;
    
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    if( obj->top == obj->stackSize -1 )
        return;
    
    // insert
    obj->data[ ++obj->top ] = x;
    
    // default min is say 0
    int min = 0;
    
    for ( int i = 0 ; i <= obj->top ; i ++ )
    {
        // if there exists a min minimum than min make it point there
        if( obj->data[i] < obj->data[min] )
            min = i;
    }
    
    obj->min = min;
}

void minStackPop(MinStack* obj) {
    // if empty no pop
    if( obj->top == -1 )
        return;
    
    // decrease top
    obj->data[obj->top--] = 0;
    
    // default min is say 0
    int min = 0;
    
    for ( int i = 0 ; i <= obj->top ; i ++ )
    {
        // if there exists a min minimum than min make it point there
        if( obj->data[i] < obj->data[min] )
            min = i;
    }
    
    obj->min = min;
    
    // if empty , no min either
    if( obj->top == -1 )
        obj->min = -1;
    
    return;
}

int minStackTop(MinStack* obj) {
    // return top element 
    return obj->data[ obj->top ];
}

int minStackGetMin(MinStack* obj) {
    return obj->data[ obj->min ];
}

void minStackFree(MinStack* obj) {
    free(obj->data);    
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */