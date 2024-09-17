#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct
{
    int *data;
    int top;
} Stack;
// 初始化栈
void initStack(Stack *s)
{
    s->data = (int *)malloc(MAX_SIZE * sizeof(int));
    s->top = -1;
}

// 入栈
void push(Stack *s, int item)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s->data[++s->top] = item;
    }
}

// 出栈
int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return s->data[s->top--];
    }
}

int main()
{
    Stack *stack;
    initStack(stack);
    push(stack, 1);
    push(stack, 2);
    int v = pop(stack);
    printf("%d \n", v);
    v = pop(stack);
    printf("%d \n", v);
    return 1;
}