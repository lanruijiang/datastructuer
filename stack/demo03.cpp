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
void push(Stack *s, int data)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s->data[++s->top] = data;
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

// 将元素压入栈底
void insertAtBottom(Stack *s, int data)
{
    printf("top = %d == data == %d \n" , s->top , data);
    // 当栈为空时，直接将元素入栈
    if (s->top == -1)
    {
        push(s, data);
    }
    else
    {
        // ① 取栈底元素
        int topdata = pop(s);
         printf("top = %d \n" , s->top);
            printf("topdata = %d \n" , topdata);
        insertAtBottom(s, data);
        // ② 将之前的元素逐个入栈
        push(s, topdata);
        //  printf("top = %d \n" , s->top);
    }
}

// 逆序栈
void reverseStack(Stack *s)
{
    if (s->top != -1)
    {
        // ① 不断地取栈顶元素
        int topdata = pop(s); // 4 3 2 1
            //   printf("+++++++++++++++++> %d ===> top == %d \n"  ,topdata  , s->top);
        reverseStack(s);
        // ② 将取出的栈顶元素依次压入栈底
        // printf("==++++==> %d \n"  ,topdata);
        insertAtBottom(s, topdata);
    }
}

int main()
{
    Stack s;
    initStack(&s);
    push(&s, 1);      // 1
    push(&s, 2);      // 1 2
    push(&s, 3);      // 1 2 3
    push(&s, 4);      // 1 2 3 4
                      // 逆序栈
    reverseStack(&s); // 4 3 2 1
    // 将逆序后的栈内元素全部出栈，出栈顺序是 1 2 3 4
    while (s.top != -1)
    {
        printf("%d ", pop(&s));
    }

    free(s.data);
    return 0;
}