#include "tLinkTable.h"

/*Create a blank link table*/
tLinkTable *CreateLink()
{
//     tLinkNode *head = malloc(sizeof(tLinkNode));
//     tLinkNode *tail = malloc(sizeof(tLinkNode));
     tLinkTable *table = malloc(sizeof(tLinkTable));

     table->head = NULL;
     table->tail = NULL;
     table->sumNode = 0;
  
     return table;
}

/*
Delete Link table
*/
int DeleteLink( tLinkTable *table)
{
    tLinkNode *temp = NULL;
    while(table->head != NULL)
    {
        temp = table->head;
        table->head = table->head->next;
        free(temp);
        table->sumNode --;
    }
    free(table);
    return 0;
}

/*
Add Link with a Node
*/
int AddLinkNode(tLinkTable* table, tLinkNode *node)
{
    if(table->head == NULL)
    {
        table->head = node;
        table->tail = node;
        table->sumNode ++;
        return 0;
    }	
    else
    {
        tLinkNode *temp = table->tail;
        temp->next = node;
        table->tail = node;
        return 0;
    }
}

/*Delete a node*/
int DelLinkNode(tLinkTable *table, tLinkNode *node)
{
    tLinkNode *temp = table->head;
    tLinkNode *next = NULL;
    if(temp == node)
    {
         table->head = temp->next;
         if(sumNode == 1)
         { 
             table->tail = table->head;
         }
         sumNode -- ;
         free(temp);
         return 0;
    }
   // temp = temp->next;
    while(temp->next != NULL)
    {
         if(temp->next == node)
         {
             next = temp->next;
             temp->next = temp->next->next;
             free(next);
             table->sumNode -- ;
             return 0;
         }
    }
    return 1;
}










