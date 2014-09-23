
/************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                    */
/*                                                                                  */
/*  FILE NAME             :  menu.c                                                 */
/*  PRINCIPAL AUTHOR      :  LiuYiming                                               */
/*  SUBSYSTEM NAME        :  menu                                                   */
/*  MODULE NAME           :  menu                                                   */
/*  LANGUAGE              :  C                                                      */
/*  TARGET ENVIRONMENT    :  ANY                                                    */
/*  DATE OF FIRST RELEASE :  2014/09/19                                             */
/*  DESCRIPTION           :  This is a menu program                                 */
/************************************************************************************/

/*
 *Revision log:
 *
 *Created by Liu Yiming, 2014/9/20
 */

#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include "menu.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     5

tLinkTable * pLinkTable = NULL;	

main()
{	
	pLinkTable = InitCmd();
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Plase input a cmd  > ");
		scanf("%s",cmd);
		tDataNode *p = FindCmd(pLinkTable, cmd);
		if(p == NULL)
		{
			printf("This is a wrong cmd!\n");
			continue;
		}
		printf("%s - %s\n",p->cmd,p->desc);
		if(p->hander != NULL)
		{
			p->hander(pLinkTable);
		}	
	}
}

