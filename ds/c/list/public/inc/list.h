#ifndef _LIST_H_INCLUDED_
#define _LIST_H_INCLUDED_

typedef struct sd
{
	void *Data;
	size_t DataSize;
} Data_t;

typedef struct list
{
	/* data and data size trying to make it as generic as possible */
	struct sd Data;
	struct list *Next;
} DSList_t;

typedef enum DS_ErrorCodes_t
{
	DS_SUCCESS = 0,
	DS_LIST_UNDERFLOW = -1,
	DS_LIST_OVERFLOW = -2,
	DS_OOM = -3,
	DS_INVALID = -4

} DS_ErrorCodes_t;

DS_ErrorCodes_t DSList_addHead(DSList_t **listHead, const void *const data,
		const size_t dataSize);
DS_ErrorCodes_t DSList_DelHead(DSList_t **listHead, void *data,
		size_t *dataSize);
DS_ErrorCodes_t DSList_addTail(DSList_t **listHead, const void *const data,
		const size_t dataSize);
DS_ErrorCodes_t DSList_DelTail(DSList_t **listHead, void *data,
		size_t *dataSize);
DS_ErrorCodes_t DSList_Reverse(DSList_t **listHead);

void DSList_PrintInt(DSList_t *list);

#endif
