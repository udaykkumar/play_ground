#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define DSTrue  1
#define DSFalse 0

static DSList_t* DSList_GetNode(const void *const data, const size_t dataSize)
{
	DSList_t *node = calloc(1, sizeof(DSList_t));
	if (node)
	{
		node->Data.Data = calloc(1, dataSize);
		if (node->Data.Data)
		{
			memcpy(node->Data.Data, data, dataSize);
			node->Data.DataSize = dataSize;
			node->Next = NULL;
			return node;
		}
	}
	return NULL;
}

void DSList_PrintInt(DSList_t *list)
{
	if (list)
	{
		fprintf(stdout, "Printing List %p\n", list);
		while (list)
		{
			fprintf( stdout, "%d ", *(int*) list->Data.Data);
			list = list->Next;
		}
		fprintf(stdout, "\n");
	}
}

DS_ErrorCodes_t DSList_addHead(DSList_t **listHead, const void *const data,
		const size_t dataSize)
{
	int retVal = DS_INVALID;

	/* as usual check for non-null */
	if (listHead && data && dataSize > 0)
	{
		DSList_t *newNode = DSList_GetNode(data, dataSize);
		if (newNode)
		{
			/* If listHead is pointing to NULL
			 there is nothing we'll create a node and append */
			if (*listHead == NULL)
			{
				*listHead = newNode;
			}
			else
			/* If there is something Let the New Node -> point to Eixiting List
			 now move listHead to point to newNode */
			{
				newNode->Next = *listHead;
				*listHead = newNode;
			}
			retVal = DS_SUCCESS;
		}
		else
		{
			retVal = DS_OOM;
		}
	}

	return retVal;
}

DS_ErrorCodes_t DSList_addTail(DSList_t **listHead, const void *const data,
		const size_t dataSize)
{
	int retVal = DS_INVALID;

	/* as usual check for non-null */
	if (listHead && data && dataSize > 0)
	{
		DSList_t *newNode = DSList_GetNode(data, dataSize);
		if (newNode)
		{
			/*  If listHead is pointing to NULL
			 there is nothing we'll create a node and append */
			if (*listHead == NULL)
			{
				*listHead = newNode;
			}
			else
			/* Get to the end of list, and link with newNode */
			{
				DSList_t *t = *listHead;
				while (t->Next)
					t = t->Next;

				t->Next = newNode;
			}
			retVal = DS_SUCCESS;
		}
		else
		{
			retVal = DS_OOM;
		}
	}

	return retVal;
}

DS_ErrorCodes_t DSList_DelHead(DSList_t **listHead, void *data,
		size_t *dataSize)
{
	int retVal = DS_INVALID;

	/* as usual check for non-null */
	if (listHead && data)
	{
		DSList_t *n = NULL;

		/* If list is not Empty */
		if (*listHead)
		{
			// Get the Head
			n = *listHead;

			// Get ListHead point to Next
			*listHead = (*listHead)->Next;

			// Detach Head
			n->Next = NULL;

			// Get Data from head
			*dataSize = n->Data.DataSize;
			memcpy(data, n->Data.Data, n->Data.DataSize);
			free(n->Data.Data);
			free(n);
			retVal = DS_SUCCESS;
		}
		else
		{
			retVal = DS_LIST_UNDERFLOW;
		}
	}
	return retVal;
}

DS_ErrorCodes_t DSList_DelTail(DSList_t **listHead, void *data,
		size_t *dataSize)
{
	int retVal = DS_INVALID;

	/* as usual check for non-null */
	if (listHead && data)
	{
		DSList_t *n = NULL;

		/* If list is not Empty */
		if (*listHead)
		{
			// Get the Head
			n = *listHead;

			// Go to last but one
			while (n->Next && n->Next->Next)
				n = n->Next;

			// If n->Next == NULL, its a single node
			if (n->Next)
			{

			}
			// Get ListHead point to Next
			*listHead = (*listHead)->Next;

			// Detach Head
			n->Next = NULL;

			// Get Data from head
			*dataSize = n->Data.DataSize;
			memcpy(data, n->Data.Data, n->Data.DataSize);

			free(n);
			retVal = DS_SUCCESS;
		}
		else
		{
			retVal = DS_LIST_UNDERFLOW;
		}
	}
	return retVal;

}

DS_ErrorCodes_t DSList_Reverse(DSList_t **listHead)
{
	int retVal = DS_INVALID;

	// Only valid if there is something in list
	if (*listHead)
	{
		DSList_t *head = NULL;
		DSList_t *temp = NULL;
		DSList_t *current = *listHead;

		while (current)
		{
			if (!head)
			{
				head = current;
				current = current->Next;
				head->Next = NULL;
			}
			else
			{
				temp = current;
				current = current->Next;
				temp->Next = head;
				head = temp;
			}
		}

		*listHead = head;

	}
	return retVal;
}
