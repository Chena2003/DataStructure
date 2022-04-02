#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode;

int main()
{

    LNode a;
    LNode *L;
    L = (LNode *)malloc(sizeof(LNode));
    L->data = 1;
    L->next = &a;

    printf("%d  %d\n", L->data, L->next);

    return 0;
}
