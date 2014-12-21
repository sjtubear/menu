#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct orderNode{
    //define 4 elements, name, handler, desc, next
    char *name;
    char *desc;
    int (*handler)();
    orderNode* next;
}tOrderNode;


tOrderNode *FindCmd(tOrderNode *head,char *cmd);

int ShowAllCmd(*tOrderNode *head);
