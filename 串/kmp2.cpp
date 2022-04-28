/**
 * @file kmp2.cpp
 * @author Chena
 * @brief KMP算法改进版
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *ch;
    int length;
}Str;

// 字符串赋值
int strAssign(Str& str, char * ch)
{
    if(str.ch)
        free(str.ch);

    int len = 0;
    char *c = ch;
    while(*c)
    {
        ++len;
        ++c;
    }
    if(len == 0)
    {
        str.ch = NULL;
        str.length = 0;
        return 1;
    }
    else
    {
        str.ch = (char *)malloc(sizeof(char) * (len+1));
        if(!str.ch)
            return 0;

        str.length = len;

        for(int i = 0; i <= len; i++)
            str.ch[i] = ch[i];

        return 1;
    }
}


// 求nextval数组
void getNextval(Str substr, int nextval[])
{
    int j = 0, t = -1;
    nextval[0] = -1;
    while(j < substr.length)
    {
        if(t == -1 || substr.ch[j] == substr.ch[t])
        {
            ++t;
            ++j;
            if(substr.ch[j] != substr.ch[t])
                nextval[j] = t;
            else
                nextval[j] = nextval[t];
        }
        else
            t = nextval[t];
    }
}

int KMP(Str str, Str substr, int nextval[])
{
    int i = 0, j = 0;
    while(i < str.length && j < substr.length)
    {
        if(j == -1 || str.ch[i] == substr.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = nextval[j];
    }
    if(j >= substr.length)
        return i - substr.length;
    else
        return -1;
}

int main(void)
{
    char ch1[50] = "ABABBBABAAAAB";
    char ch2[50] = "BAABAAA";
    Str str, substr;

    strAssign(str, ch1);
    strAssign(substr, ch2);

    int nextval[50];

    getNextval(substr, nextval);

    // for(int i = 0; i < substr.length; i++)
    //     printf("%d", nextval[i]);

    printf("%d\n", KMP(str, substr, nextval));

    return 0;
}