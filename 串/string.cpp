/**
 * @file string.cpp
 * @author Chena
 * @brief 字符串的基本操作
 * @version 0.1
 * @date 2022-04-27
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

// 获取字符串长度
int strLength(Str str)
{
    return str.length;
}

// 字符串比较
int strCompare(Str s1, Str s2)
{
    for(int i = 0; i < s1.length && i < s2.length; i++)
        if(s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
    
    return s1.length - s2.length;
}

// 字符串连接
int strConcat(Str &s1, Str s2)
{
    s1.ch = (char *)realloc(s1.ch, sizeof(char) * (s1.length + s2.length));

    if(!s1.ch)
        return 0;

    for(int i = 0; i <= s2.length; i++)
        s1.ch[s1.length + i] = s2.ch[i];

    s1.length = s1.length + s2.length;
    return 1;
}

// 字符串子串
int subString(Str& substr, Str str, int pos, int len)
{
    if(pos<0||pos>=str.length||len<0||len>str.length-pos)
        return 0;
    if(substr.ch)
    {
        free(substr.ch);
        substr.ch = NULL;
    }
    if(len == 0)
    {
        substr.ch = NULL;
        substr.length = 0;
        return 1;
    }
    else
    {
        substr.ch = (char *)malloc(sizeof(char)*(len+1));
        int i = pos;
        int j = 0;
        while(i < pos+len)
        {
            substr.ch[j] = str.ch[i];
            i++;
            j++;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}

// 清空字符串
int clearString(Str& str)
{
    if(str.ch)
    {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}

int main(void)
{
    char ch1[50] = "Hello World";
    char ch2[50] = "hahahhahahha";
    Str s1, s2; 

    printf("%s\n", ch1);
    printf("%s\n", ch2);

    strAssign(s1, ch1);
    strAssign(s2, ch2);

    printf("%s\n", s1.ch);
    printf("%s\n", s2.ch);
    printf("******************\n");

    if(strCompare(s1, s2))
        printf("%s\n", s1.ch);
    else
        printf("%s\n", s2.ch);

    
    strConcat(s1, s2);
    printf("%s\n", s1.ch);

    Str s3;

    subString(s3, s1, s1.length, s2.length);
    printf("%s\n", s3.ch);
    printf("******************\n");
    
    return 0;
}