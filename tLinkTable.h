#ifndef _LINK_TABLE_
#define _LINK_TABLE_

#include <stdio.h>
#include <stdlib.h>

//Node datastruct
typedef struct LinkNode{
    struct LinkNode* next;
}tLinkNode;

//table datastruct
typedef struct LinkTable{
   tLinkNode *head;
   tLinkNode *tail;
   int sumNode;
}tLinkTable;

/*get head)
*/
tLinkNode *GetHeadNode(tLinkTable *table);

/*

*/
tLinkNode *GetNextNode(tLinkTable *table,tLinkNode *node);


/*
Create link table
*/
tLinkTable * CreateLink();

/*
Delete Link
*/
int DeleteLink(tLinkTable *table );

/*Add Node*/
int AddLinkNode(tLinkTable* table,tLinkNode *node);

/*Delete Node*/
int DelLinkNode(tLinkTable* table,tLinkNode *node);

#endif
