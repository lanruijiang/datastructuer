/***链栈的实现***/
#include <stdio.h>
#include <windows.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char SElemType;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

// 算法3.5　链栈的初始化
Status InitStack(LinkStack &S)
{ // 构造一个空栈 S，栈顶指针置空
    S = NULL;
    return OK;
}

// 算法3.6　链栈的入栈
Status Push(LinkStack &S, SElemType e)
{ // 在栈顶插入元素e
    LinkStack p;
    p = new StackNode; // 生成新结点
    p->data = e;       // 将新结点数据域置为e
    p->next = S;       // 将新结点插入栈顶
    S = p;             // 修改栈顶指针为p
    return OK;
}

// 算法3.7　链栈的出栈
Status Pop(LinkStack &S, SElemType &e)
{ // 删除S的栈顶元素，用e返回其值
    LinkStack p;
    if (S == NULL)
        return ERROR; // 栈空
    e = S->data;      // 将栈顶元素赋给e
    p = S;            // 用p临时保存栈顶元素空间，以备释放
    S = S->next;      // 修改栈顶指针
    delete p;         // 释放原栈顶元素的空间
    return OK;
}
// 算法3.8　取链栈的栈顶元素
SElemType GetTop(LinkStack S)
{                  // 返回S的栈顶元素，不修改栈顶指针
    if (S != NULL) // 栈非空
    {
        return S->data; // 返回栈顶元素的值，栈顶指针不变
    }
    return 0;
}

int main()
{
    LinkStack s;
    SElemType e;
    InitStack(s);
    int num = 5;
    for (int i = 1; i <= num; i++)
    {
        e = i;
        Push(s, e);
    }

    for (int i = 1; i <= num; i++)
    {
        Pop(s, e);
        printf("%d \n", e);
    }

    return 0;
}
