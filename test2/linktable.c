#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

/*
 * create a LinkTable
 */
tLinkTable * CreateLinkTable()
{
	tLinkTable * pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
	if(pLinkTable == NULL)
	{
		return NULL;
	}
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = 0;
	pthread_mutex_init(&(pLinkTable->mutex), NULL);
	return pLinkTable;
}
/*
 * delete a LinkTable
 */
int DeleteLinkTable(tLinkTable * pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return FAILURE;
	}
	while(pLinkTable->pHead != NULL)
	{
		tLinkTableNode *p = pLinkTable->pHead;
		pthread_mutex_lock(&(pLinkTable->mutex));
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		pLinkTable->SumOfNode -= 1;
		pthread_mutex_unlock(&(pLinkTable->mutex));
		
		//free(p);
	}
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = 0;
	pthread_mutex_destroy(&(pLinkTable->mutex));
	free(pLinkTable);
	return SUCCESS;
}
/*
 * add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
	if((pLinkTable == NULL)||(pNode == NULL))
	{
		return FAILURE;
	}
	pNode->pNext = NULL;
	pthread_mutex_lock(&(pLinkTable->mutex));
	if(pLinkTable->pHead == NULL)
	{
		pLinkTable->pHead = pNode;
	}
	if(pLinkTable->pTail == NULL)
	{
		pLinkTable->pTail = pNode;
	}
	else
	{
		pLinkTable->pTail->pNext = pNode;
		pLinkTable->pTail = pNode;
	}
	pLinkTable->SumOfNode += 1;
	pthread_mutex_unlock(&(pLinkTable->mutex));
	return SUCCESS;
}
/*
 * delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
	if((pLinkTable == NULL)||(pNode == NULL))
	{
		return FAILURE;
	}
	pthread_mutex_lock(&(pLinkTable->mutex));
	if(pLinkTable->pHead == pNode)
	{
		tLinkTableNode * pTempNode = pLinkTable->pHead;
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		pLinkTable->SumOfNode -= 1;
		if(pLinkTable->SumOfNode == 0)
		{
			pLinkTable->pTail = NULL;
		}
		//free(pTempNode);
		pthread_mutex_unlock(&(pLinkTable->mutex));
		return SUCCESS;
	}

	tLinkTableNode * p = pLinkTable->pHead;
	while(p != NULL)
	{
		if(p->pNext == pNode)
		{
			tLinkTableNode * pTempNode = p->pNext;
			p->pNext = p->pNext->pNext;
			pLinkTable->SumOfNode -= 1;
			if(pLinkTable->SumOfNode == 0)
			{
				pLinkTable->pTail = NULL;
			}
			//free(pTempNode);
			pthread_mutex_unlock(&(pLinkTable->mutex));
			return SUCCESS;
		}
		p = p->pNext;
	}
	pthread_mutex_unlock(&(pLinkTable->mutex));
	return FAILURE;
}
/*
 * search a LinkTableNode from LinkTable
 * int Condition(tLinkTableNode * pNode);
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable * pLinkTable, int Condition(tLinkTableNode * pNode))
{
	if((pLinkTable == NULL)||(Condition == NULL))
	{
		return NULL;
	}
	tLinkTableNode * pNode = pLinkTable->pHead;
	while(pNode != pLinkTable->pTail)
	{
		if(Condition(pNode) == SUCCESS)
		{
			return pNode;
		}
		pNode = pNode->pNext;
	}
	return NULL;
}
/*
 * get LinkTableHead
 */
tLinkTableNode *GetLinkTableHead(tLinkTable * pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return NULL;
	}
	return pLinkTable->pHead;
}
/*
 * get next LinkTableNode
 */
tLinkTableNode *GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
	if((pLinkTable == NULL)||(pNode == NULL))
	{
		return NULL;
	}
	tLinkTableNode * pTempNode = pLinkTable->pHead;
	while(pTempNode != NULL)
	{
		if(pTempNode == pNode)
		{
			return pTempNode->pNext;
		}
		pTempNode = pTempNode->pNext;
	}
	return NULL;
}

