
/************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                    */
/*                                                                                  */
/*  FILE NAME             :  menu.c                                                 */
/*  PRINCIPAL AUTHOR      :  LiuYiming                                               */
/*  SUBSYSTEM NAME        :  menu                                                   */
/*  MODULE NAME           :  menu                                                   */
/*  LANGUAGE              :  C                                                      */
/*  TARGET ENVIRONMENT    :  ANY                                                    */
/*  DATE OF FIRST RELEASE :  2014/09/19                                            */
/*  DESCRIPTION           :  This is a menu program                                 */
/************************************************************************************/

/*
 *Revision log:
 *
 *Created by Liu Yiming, 2014/9/22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
#include "menu.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     5


int ShowAllCmd(tLinkTable * pLinkTable)
{
	printf("*****************************************\n");
	printf("Menu List:				 \n");
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(pLinkTable);		
	while(pNode != NULL)
	{
		printf("	%s, %s\n", pNode->cmd, pNode->desc);
		pNode = (tDataNode *)GetNextLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
	}
	printf("*****************************************\n");
	return 0;
}

tDataNode* FindCmd(tLinkTable * pLinkTable, char *cmd)
{
	//printf("%s",cmd);
	if((pLinkTable == NULL)||(cmd == NULL))
	{
		return NULL;
	}
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(pLinkTable);

	while(pNode != NULL)
	{
		if(!strcmp(pNode->cmd, cmd))
		{
			return pNode;
			
		}
		pNode = (tDataNode *)GetNextLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
	}
	return NULL;
}
/*
 * run add cmd
 */
int Add(tLinkTable *pLinkTable)
{
    char AddCmd[CMD_MAX_LEN];
    char AddDesc[DESC_LEN];
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    tDataNode * pAdd = (tDataNode *)malloc(sizeof(tDataNode));
    tDataNode * pTempNode;
    
    printf("Plase input AddCmd name > ");
    scanf("%s", AddCmd);
    pTempNode = FindCmd(pLinkTable, AddCmd);
    if(pTempNode != NULL)
    {
        printf("Cmd is existed!\n");
        return FAILURE;
    }
    strcpy(pAdd->cmd, AddCmd);
    printf("Plase input cmd desc >");
    getchar();
    scanf("%[^\n]", AddDesc);
    strcpy(pAdd->desc, AddDesc);
    pAdd->pNext = NULL;
    pAdd->hander = NULL;
    AddLinkTableNode(pLinkTable,(tLinkTableNode *)pAdd);
    return SUCCESS;
}
/*
 * run del cmd
 */
int Del(tLinkTable * pLinkTable)
{
    char DelCmd[CMD_MAX_LEN];
    tDataNode * pTempNode;
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    printf("Plase input DelCmd name > ");
    scanf("%s", DelCmd);
    pTempNode = FindCmd(pLinkTable, DelCmd);
    if(pTempNode == NULL)
    {
        printf("Cmd is not existed!\n");
        return FAILURE;
    }
    DelLinkTableNode(pLinkTable, (tLinkTableNode * )pTempNode);
    
    return SUCCESS;
}

tLinkTable * InitCmd()
{
	tLinkTable * pLinkTable = CreateLinkTable();	
	int i;
	for(i = 0; i < CMD_NUM; i++) 
	{       
        	AddLinkTableNode(pLinkTable,(tLinkTableNode *)&data[i]);
	}
	return pLinkTable;
}

int Help(tLinkTable *pLinkTable)
{
	ShowAllCmd(pLinkTable);
	return 0;
}

int Exit(tLinkTable * pLinkTable)
{
	DeleteLinkTable(pLinkTable);
	exit(0);
	return 0;
}


