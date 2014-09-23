#include "linktable.h"

typedef struct DataNode
{
	tLinkTableNode * pNext;
	char  cmd[20];
	char  desc[40];
	int (*hander)(tLinkTable * pLinkTable);
}tDataNode;

int ShowAllCmd(tLinkTable * pLinkTable);

tDataNode* FindCmd(tLinkTable *pLinkTable, char *cmd);

int Add(tLinkTable *pLinkTable);

int Del(tLinkTable * pLinkTable);

int Help(tLinkTable * pLinkTable);

int Exit(tLinkTable * pLinkTable);

static tDataNode data[] = 
{
	{NULL, "help",    "This is help cmd!", Help},
	{NULL, "version", "Menu program 1.0" , NULL},
	{NULL, "add",     "Add a mnuu cmd", Add},
        {NULL, "del",     "Del a menu cmd "  , Del},
	{NULL, "exit",    "This is exit cmd!", Exit}
};

tLinkTable * InitCmd();
