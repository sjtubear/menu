
#include "order_list.h"


history_l * HistoryListInitial(history_l *p, history_n *n)
{
    p->head = n;
    p->tail = n;
    n->next = NULL;
    return p;
}

history_l * AddHistoryNode(history_l *p, history_n *n)
{
    p->tail->next = n;
    p->tail = n;
    return p;
}

history_n * HistoryNodeInitial(history_n *n,char A[128])
{
    strcpy(n->order,A);
    n->next = NULL;
    return n;
}

void PrintHisList(history_l *p)
{
    history_n *temp = p->head;
    do
    {
        printf("%s\n",temp->order);
        temp = temp->next;
    }while(temp != NULL);
    printf("---------------------------\n"); 
}


void ResetHisList(history_l *p)
{
    p->tail=NULL;
    p->head=NULL;
}


/*int main()
{
    char A[128]={"China"};
    char B[128]={"Good Place"};
    char C[128]={"What Are You Doing!"};
    history_n *Na = malloc(sizeof(history_n));
    history_n *Nb = malloc(sizeof(history_n));
    history_n *Nc = malloc(sizeof(history_n));

    HistoryNodeInitial(Na,A);
    HistoryNodeInitial(Nb,B);
    HistoryNodeInitial(Nc,C);
 
    history_l *La = malloc(sizeof(history_l));
    
    HistoryListInitial(La,Na);
   
    AddHistoryNode(La,Nb);
    AddHistoryNode(La,Nc);
    PrintHisList(La);

}*/
