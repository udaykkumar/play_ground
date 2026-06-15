#ifndef _TREE_H_INCLUDED_
#define _TREE_H_INCLUDED_

typedef struct sd
{
	void *Data;
	size_t DataSize;
} Data_t;

typedef struct tree
{
	/* data and data size trying to make it as generic as possible */
	struct sd Data;
	struct tree *Left, *Right;
} DSTree_t;

typedef enum DS_ErrorCodes_t
{
	DS_SUCCESS = 0,
	DS_TREE_UNDERFLOW = -1,
	DS_TREE_OVERFLOW = -2,
	DS_OOM = -3,
	DS_INVALID = -4

} DS_ErrorCodes_t;

DS_ErrorCodes_t DSTree_addChild(DSTree_t **treeHead, const void *const data,
		const size_t dataSize);

void DSTree_TraversePreOrder(DSTree_t *treeHead);
void DSTree_TraverseInOrder(DSTree_t *treeHead);
void DSTree_TraversePostOrder(DSTree_t *treeHead);

#if 0
DS_ErrorCodes_t DSTree_delChild( DSTree_t **treeHead, void * data, size_t *dataSize );
#endif

#endif
