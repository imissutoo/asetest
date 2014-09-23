#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#include <pthread.h>
#define SUCCESS 0
#define FAILURE (-1)

typedef struct LinkTableNode
{
	struct LinkTableNode * pNext;
}tLinkTableNode;

typedef struct LinkTable
{
	tLinkTableNode * pHead;
	tLinkTableNode * pTail;
	int SumOfNode;
	pthread_mutex_t mutex;
}tLinkTable;

/*
 * create a LinkTable
 */
tLinkTable * CreateLinkTable();

/*
 * delete a LinkTable
 */
int DeleteLinkTable(tLinkTable * pLinkTable);

/*
 * add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

/*
 * delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

/*
 * search a LinkTableNode from LinkTable
 * int Condition(tLinkTableNode * pNode);
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable * pLinkTable, int Condition(tLinkTableNode * pNode));

/*
 * get LinkTableHead
 */
tLinkTableNode *GetLinkTableHead(tLinkTable * pLinkTable);

/*
 * get next LinkTableNode
 */
tLinkTableNode *GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

#endif





