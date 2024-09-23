/***顺序栈的实现***/

#include <stdio.h>
#include <windows.h>

// 顺序栈定义
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100 // 顺序栈存储空间的初始分配量
typedef int Status;
typedef char SElemType;

typedef struct
{
    SElemType *base; // 栈底指针
    SElemType *top;  // 栈顶指针
    int stacksize;   // 栈可用的最大容量
} SqStack;

// 算法3.1　顺序栈的初始化
Status InitStack(SqStack &S)
{
    // 构造一个空栈S
    // 为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
    S.base = (char *)malloc(MAXSIZE * sizeof(char));

    if (!S.base)
    {
        exit(OVERFLOW); // 存储分配失败
    }
    S.top = S.base;        // top初始为base，空栈
    S.stacksize = MAXSIZE; // stacksize置为栈的最大容量MAXSIZE
    return OK;
}

// 算法3.2　顺序栈的入栈
Status Push(SqStack &S, SElemType e)
{
    // 插入元素e为新的栈顶元素
    if (S.top - S.base == S.stacksize)
    {
        return ERROR; // 栈满
    }
    *(S.top++) = e; // 元素e压入栈顶，栈顶指针加1
    return OK;
}

// 算法3.3　顺序栈的出栈
Status Pop(SqStack &S, SElemType &e)
{
    // 删除S的栈顶元素，用e返回其值
    if (S.base == S.top)
        return ERROR; // 栈空
    e = *(--S.top);   // 栈顶指针减1，将栈顶元素赋给e
    return OK;
}

// 算法3.4　取顺序栈的栈顶元素
char GetTop(SqStack S)
{                        // 返回S的栈顶元素，不修改栈顶指针
    if (S.top != S.base) // 栈非空
    {
        return *(S.top - 1); // 返回栈顶元素的值，栈顶指针不变
    }
    return 0;
}

int main()
{
    SqStack s;
    InitStack(s);
    SElemType e;
    e = 100;
    Push(s, e);
    e = 2;
    Push(s, e);

    Pop(s, e);
    printf("%d \n", e);
    Pop(s, e);
    printf("%d \n", e);
    return 1;
}