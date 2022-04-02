#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define LIST_INIT_SIZE  100 // 线性表存储空间的初始分配量
#define LISTINCREMENT   10  // 线性表存储空间的分配增量

typedef int ElemType;

typedef struct SqList
{
    ElemType *elem; // 存储空间基址
    int length; // 当前长度
    int listsize;   //当前顺序表大小
}SqList; 

/* 顺序表另一种定义
typedef struct SqList
{
    ElemType data[maxsize];
    int length;
} 
 */

status InitList_sq(SqList &L)
{
    // 构造一个空的线性表
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
};

status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    // 在线性表中第i个位置前插入新的元素e
    if (i < 1 || i > L.length + 1) return ERROR; // i值不合法
    if (L.length >= L.listsize) // 当前存储空间已满，增加分配
    {
        ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase) return OVERFLOW;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }

    ElemType *q = &(L.elem[i-1]);   // 第i个元素位置
    ElemType *p = &(L.elem[L.length-1]); // 表尾元素位置
    for(; p >= q; p--) *(p+1) = *p;     // 插入位置元素及之后元素右移

    *q = e;     //插入e
    L.length++; // 表长加1
    return OK;
};

status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    // 删除线性表中第i个位置上的元素
    if(i < 1 || i > L.length) return ERROR; // i值不合法

    e = L.elem[i-1];    // 将被删除元素赋给e
    ElemType *q = &(L.elem[i-1]);    // q为被删除元素位置
    ElemType *p = L.elem + L.length - 1;    // 表尾元素位置
    for(; q < p; q++)   *q = *(q+1);        // 被删除元素之后的元素左移
    --L.length;     // 表长减一
    return OK;
};

int LocateElem_Sq(SqList L, ElemType e)
{
    // 在线性表中查找第一个值为e的元素
    int i = 1;
    while (i <= L.length && L.elem[i-1] != e) i++;
    if (i <= L.length) return i;
    else return 0;
};

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    // 合并两个顺序表
    ElemType * pa = La.elem;
    ElemType * pb = Lb.elem;
    Lc.length = La.length + Lb.length;
    Lc.listsize = Lc.length;
    ElemType * pc = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    Lc.elem = pc;
    if(!Lc.elem) exit(OVERFLOW);

    ElemType * pa_last = La.elem + La.length - 1;
    ElemType * pb_last = Lb.elem + Lb.length - 1;

    while(pa <= pa_last && pb <= pb_last)
    {
        if(*pa < *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }

    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++; 
};

int main()
{
    SqList La, Lb, Lc;
    ElemType elem, num;
    ElemType numa[10] = {12, 1, 16, 7, 18, 9, 13, 4, 15, 0};
    ElemType numb[10] = {2, 11, 6, 17, 8, 19, 3, 14, 5, 10};

    InitList_sq(La);
    for(int i = 0; i < 10; i++)
    {
        La.elem[i] = numa[i];
        La.length++;
    }

    printf("La: \n");
    for(int i = 0; i < La.length; i++)
    {
        printf("%4d", La.elem[i]);
    }

    InitList_sq(Lb);
    for(int i = 0; i < 10; i++)
    {
        Lb.elem[i] = numb[i];
        Lb.length++;
    }

    printf("\nLb: \n");
    for(int i = 0; i < Lb.length; i++)
    {
        printf("%4d", Lb.elem[i]);
    }

    MergeList_Sq(La, Lb, Lc);
    printf("\nLc: \n");
    for(int i = 0; i < Lc.length; i++)
    {
        printf("%4d", Lc.elem[i]);
    }   

    return 0;
}