#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct historyNode            // Have to has the struct in front of the struct name
{
    char order[128];
    struct  historyNode * next;
}history_n;

typedef struct historyList
{
    history_n *head;
    history_n *tail;
}history_l;

extern history_l * HistoryListInitial(history_l *p, history_n *n);

history_l * AddHistoryNode(history_l *p, history_n *n);

extern history_n * HistoryNodeInitial(history_n *n,char A[128]);

void PrintHisList(history_l *p);

void ResetHisList(history_l *p);
