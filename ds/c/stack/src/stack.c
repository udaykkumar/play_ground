#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define DSTrue  1
#define DSFalse 0

static inline int DSStack_IsFull(const DSStack_t *const stack)
{
	/*  Once StackTop reached max-1 we are out of room */
	return (stack->StackTop == stack->StackSize - 1) ? DSTrue : DSFalse;
}

static inline int DSStack_IsEmpty(const DSStack_t *const stack)
{
	/*  if StackTop is less than 0 nothing there yet */
	return (stack->StackTop == -1) ? DSTrue : DSFalse;
}

DS_ErrorCodes_t DSStack_init(DSStack_t *const stack, int Stacksize)
{
	/* default is invalid arguments */
	DS_ErrorCodes_t retVal = DS_INVALID;

	/* 
	 This has to be true
	 1. stack is a valid pointer
	 2. Stacksize is strictly positive 
	 */
	if (stack && Stacksize > 0)
	{
		/*  Make sure we clear everything before initialization */
		memset(stack, 0x00, sizeof(DSStack_t));

		/* calloc is a better option as it cleans the array */
		if ((stack->Stack = calloc(Stacksize, sizeof(Data_t))))
		{
			/* 
			 initial configurations
			 Stacksize = Stacksize
			 StackTop  = -1
			 */
			stack->StackSize = Stacksize;
			stack->StackTop = -1;

			/* Done here */
			retVal = DS_SUCCESS;
		}
		else
		{
			/* Calloc Failure */
			retVal = DS_OOM;
		}
	}
	/* either of stack or StackSize is wrong */
	return retVal;
}

DS_ErrorCodes_t DSStack_destroy(DSStack_t *const stack)
{
	/* default is invalid arguments */
	DS_ErrorCodes_t retVal = DS_INVALID;

	if (stack && stack->Stack)
	{
		/* Clear Data array */
		int i = 0;
		Data_t *dPtr = stack->Stack;

		/* Clear data */
		for (i = 0; i < stack->StackSize; i++)
		{
			free(dPtr[i].Data);
			dPtr[i].Data = NULL;
		}

		/* Clear Stack */
		free(stack->Stack);

		/* Reset to Null */
		stack->Stack = NULL;

		/* Reset stack configuration */
		stack->StackSize = 0;
		stack->StackTop = -1;

		/* Success */
		retVal = DS_SUCCESS;
	}

	/* This stack pointer is invalid */
	return retVal;
}

DS_ErrorCodes_t DSStack_push(DSStack_t *const stack, const void *const data,
		const size_t dataSize)
{
	/* default is invalid arguments */
	DS_ErrorCodes_t retVal = DS_INVALID;

	/* we'll make sure everything is valid dataSize = 0 is just not a valid thing to do */
	if (stack && data && dataSize > 0)
	{
		/* if there is still some room to push a new element */
		if (!DSStack_IsFull(stack))
		{
			/* go to the new room */
			stack->StackTop++;

			/* Create soem space for Data */
			stack->Stack[stack->StackTop].Data = calloc(1, dataSize);

			/* there is space */
			if (stack->Stack[stack->StackTop].Data)
			{
				/* Copy Data and Size */
				memcpy(stack->Stack[stack->StackTop].Data, data, dataSize);
				stack->Stack[stack->StackTop].DataSize = dataSize;

				/* we are done */
				retVal = DS_SUCCESS;
			}
			else
			{
				/* we could not get space , revert */
				stack->StackTop--;
				retVal = DS_OOM;
			}
		}
		else
		{
			/* stack is full, let them know */
			retVal = DS_STACK_OVERFLOW;
		}
	}

	return retVal;
}

DS_ErrorCodes_t DSStack_pop(DSStack_t *const stack, void *data,
		size_t *dataSize)
{
	/* default is invalid arguments */
	DS_ErrorCodes_t retVal = DS_INVALID;

	/* we'll do our bit to ensure sanity */
	if (stack)
	{
		/*  If stack is not empty 
		 we can go ahead and pop */
		if (!DSStack_IsEmpty(stack))
		{
			/* Copy data pointed to by top element */
			*dataSize = stack->Stack[stack->StackTop].DataSize;
			memcpy(data, stack->Stack[stack->StackTop].Data, *dataSize);

			/* free and reset */
			free(stack->Stack[stack->StackTop].Data);
			stack->Stack[stack->StackTop].Data = NULL;

			/* point to next element */
			stack->StackTop--;

			/* we are done */
			retVal = DS_SUCCESS;
		}
		else
		{
			retVal = DS_STACK_UNDERFLOW;
		}
	}
	return retVal;
}

