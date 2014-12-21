
/*
	Name: Memu.c
	Copyright: Sjtubear-LAB
	Author: TianHao Wang
	Date: 05/12/14 22:35
	Description: This is a memu module program
*/
/*
        Author:Wang TianHao
        Date: 05/12/14 22:34
        Version 0.1: Add quit,Help function to menu.
*/
/*
        Author:Wang TianHao
        Date: 05/12/14 22:48
        Version 0.2: Add strlwr and error order handler;
*/
/*
        Author:Wang TianHao
        Date: 05/12/14 18:27
        version 0.2 Add history function/ Include order_list.h for list management.
*/

/*
        Author:Wang TianHao
        Date: 05/12/14 20:00
        version 0.3 Add argument, time , clear screen and text color;
*/

/*
        Author:Wang TianHao
        Date: 06/12/14 00:00
        version 0.4 Add rese
    char *str;
    str = s;
    while(*str != '\0')
    {
        if(*str >= 'A' && *str <= 'Z') 
        {
            *str += 'a'-'A';
        }
    str++;
    }
    return s;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "order_list.h"
#include "orderStructure.h"

#define VERSION "Version - 0.4 , UPATED AT 2014/12/6 \n"
#define CMD_MAX_LENGTH 128

typedef int (*intVoid) (void);
typedef void (*voidchar) (char *);
typedef void (*voidvoid) (void);
typedef void (*voidhis) (history_l *, history_n *);
typedef void (*voidhisl) (history_l *);

int ClearScreen();
int PrintHelpContent();
int PrintVersion();
int PrintTime();
int SystemQuit();
void SetTextColor(char *argu);
void RestartProgram(history_l *li,history_n *n);
char* strlwr(char*);

//orderlist 1.name 2.desc 3.handler 4.next;
static tOrderNode Nodes[] = 
{
    {"help","Get help information",PrintHelpContent,&Nodes[1]},
    {"clear","Clear the screen",ClearScreen, &Nodes[2]},
    {"reset","Clear all status",(intVoid) RestartProgram, &Nodes[3]},
    {"version","Show menu software version",PrintVersion,&Nodes[4]},
    {"time","Show Local Time",PrintTime,&Nodes[5]},
    {"quit","exit program",SystemQuit,&Nodes[6]},
    {"history","show menu order history",(intVoid)PrintHisList,&Nodes[7]},
    {"color","Color x;change text color(x = 1:red;2:green;3:blue;4:yellow)",(intVoid)SetTextColor,NULL}
};


int main()
{
    
    char order[CMD_MAX_LENGTH];
    // Order saved in this Array
    char argument[CMD_MAX_LENGTH];
    // Order's Argument.
    char start[CMD_MAX_LENGTH]={"-------ORDER START---------"};
    tOrderNode *temp;    

    history_l *orderList = malloc(sizeof(history_l));       //Create history list;
    history_n *startNode = malloc(sizeof(history_n));

    HistoryNodeInitial(startNode,start);
    HistoryListInitial(orderList,startNode);
   
    SetTextColor("4");
    ClearScreen();
    PrintHelpContent();
    while(1)                                                
    {
          
        printf(">>>");
        // Input Indication
        scanf("%s",order);
        // Read Order
        strlwr(order);
        //switch all orders to lower char
        tOrderNode *temp = FindCmd(Nodes,order);
        //Get the cmd node pointer
        int arg;
        arg = ScanArgument(argument);
        if(temp != NULL)
        {
            history_n *tempN = malloc(sizeof(history_n));
            HistoryNodeInitial(tempN,order);
            AddHistoryNode(orderList,tempN);
            if(strcmp(order,"history")==0)
            {
                (voidhisl)temp->handler(orderList);
            }
            else if(strcmp(order,"color")==0)
            {
                (voidchar)temp->handler(argument);
            }
            else if(strcmp(order,"reset")==0)
            {
                (voidhis)temp->handler(orderList,startNode);
            }
            else
            {
                temp->handler();
            }
        }
        else
        {
            printf("No such CMD, please type help for instruction \n");
        }             

    //    int i;
    //    i=ScanArgument(argument);
    //    
    //    if (i != -1) printf("%d and %s \n",i,argument);

    //    if(strcmp("quit",order)==0)
    //    {
    //        SetTextColor("0");
    //        ClearScreen();
    //        exit(0);
    //    }
    //    else if(strcmp("help",order)==0)
    //    {
    //        PrintHelpContent();
    //    }
    //    else if(strcmp("history",order)==0)
    //    {
    //        PrintHisList(orderList);
    //    }
    //    else if(strcmp("color",order)==0)
    //    {
    //        SetTextColor(argument);   
    //    }
    //    else if(strcmp("time",order)==0)
    //    {
    //        PrintTime();
    //    }
    //    else if(strcmp("version",order)==0)
    //    {
    //        printf(VERSION);
    //    }
    //    else if(strcmp("clear",order)==0)
    //    {
    //        ClearScreen();
    //    }
    //    else if(strcmp("reset",order)==0)
    //    {
    //        RestartProgram(orderList,startNode);
    //    }       
    //    else 
    //    {
    //        printf("Unkown Order : %s \n",order);
    //        printf("Please Input HELP for instruction!\n");
    //    }
    }
}

void SetTextColor(char *argu)
{
       
    if(strcmp("1",argu)==0)
    {
        printf("\033[;31m");
    }
    else if(strcmp("0",argu)==0)
    {
        printf("\033[0m");
    }
    else if(strcmp("2",argu)==0)
    {
        printf("\033[;32m");
    }
    else if(strcmp("3",argu)==0)
    {
        printf("\033[;34m");
    }
    else if(strcmp("4",argu)==0)
    {
        printf("\033[33m");
    }
    else
    {
        printf("Argument Illegal!\n");
    }
}

int PrintTime()
{
    time_t sec = time(NULL);
    struct tm t = *localtime(&sec);
    printf("Local time is(hh/mm/ss) : %02d:%02d:%02d\n",t.tm_hour,t.tm_min,t.tm_sec);
    return 0;
}

int PrintHelpContent()
{
    printf("------------------------------\n");
    ShowAllCmd(Nodes);
    printf("------------------------------\n");
    return 0;
}
int SystemQuit()
{
	SetTextColor("0");
	ClearScreen();
    exit(0);
    return 0;
}
int ClearScreen()
{
    printf("\033[2J");
    printf("\033[1;1H");
    return 0;   
}

void RestartProgram(history_l *li,history_n *n)
{
    ClearScreen();
    SetTextColor("4");
    PrintHelpContent();
    ResetHisList(li);
    HistoryListInitial(li,n);
}

int PrintVersion()
{
     printf(VERSION);
     return 0;
}

char *strlwr(char *s)          
//Convert to lower
{
    char *str;
    str = s;
    while(*str != '\0')
    {
        if(*str >= 'A' && *str <= 'Z') 
        {
            *str += 'a'-'A';
        }
    str++;
    }
    return s;
}

int ScanArgument(char *argu)  
 // Scan for 1 argument, If more than 1 clear buffer and return 1, if non return -1, if only 1 argument renturn 0 
{
    int flag = 0;
    char c;
    if(((c = getchar()) != '\n' )&& c != EOF)
    {
        scanf("%s",argu);
	while(( c = getchar()) != '\n' && c!= EOF)
        {
            flag = 1;
        }
    }
    else
    {
        flag=-1;
    }
    return flag;
}
