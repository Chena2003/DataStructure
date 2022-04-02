#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

#define MAXSIZE 100 //链表的最大长度

typedef struct{
    ElemType data;
    int cur;
}SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList &space)
{
    for(int i = 0; i < MAXSIZE -1; i++)
        space[i].cur = i + 1;

    space[MAXSIZE-1].cur = 0;
};

int Malloc_SL(SLinkList &space)
{
    int i = space[0].cur;
    if(space[0].cur) space[0].cur = space[i].cur;
    return i;
};

void Free_SL(SLinkList &space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
};

void ListInsert_SL(SLinkList &space, int i, int num)
{
    int temp = 1;
    for(int j = 1; j < i; j++)
        temp = space[temp].cur;
    
    int insert = Malloc_SL(space);
    space[insert].data = num;

    space[insert].cur = space[temp].cur;
    space[temp].cur = insert;
};

int ListDelete_L(SLinkList &space, int num)
{
    int temp = MAXSIZE - 1;
    int del = 0;
    
    while(space[temp].data != num)
    {
        temp = space[temp].cur;

        if(temp == 0) return 0;
    }

    del = temp;
    temp = MAXSIZE - 1;

    if(del == space[MAXSIZE-1].cur)
    {
        int newbody = space[del].cur;
        space[MAXSIZE-1].cur = newbody;
        Free_SL(space, del);
    }
    else
    {
        while(space[temp].cur < del)
            temp = space[temp].cur;
        
        space[temp].cur = space[del].cur;
        Free_SL(space, del);
    }
};

int LocateElem_SL(SLinkList S, ElemType e)
{
    int i = S[MAXSIZE-1].cur;

    while(S[i].data != e)
    {
        i = S[i].cur;

        if(!i) return 0;
    }
    return i;
};


int main()
{
    SLinkList space;

    InitSpace_SL(space);

    int s = Malloc_SL(space);
    int r = s;

    for(int j = 1; j < 10; j++)
    {
        int i = Malloc_SL(space);
        scanf("%d", &space[i].data);

        space[r].cur = i;
        r = i;
    }
    space[r].cur = 0;

    int i = space[r].cur;    
    // printf("%3d", space[1].data);
    for(int j = 1; j < 10; j++)
    {
        printf("%3d\n", space[i].data);
        i = space[i].cur;
    }

    getchar();

    return 0;
}