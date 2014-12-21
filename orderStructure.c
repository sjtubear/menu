#include "orderStructure.h"

tOrderNode *FindCmd(tOrderNode *head, char *cmd)
{
    tOrderNode *temp = head;
    while(temp != NULL && cmd != NULL)
    {
        if(strcmp(temp->name,cmd)==0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


int ShowAllCmd(tOrderNode* head)
{
     tOrderNode *temp = head;
     while(temp!=NULL)
     {
         printf("%s :%d \n", temp->name, temp->desc);
         temp = temp->next;
     }
     return 0;
}
