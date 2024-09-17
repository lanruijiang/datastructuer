#include <stdio.h>
#include <windows.h>
#include <windows.h>
// 元素elem进栈
int push(int *a, int top, int elem)
{
    a[++top] = elem;
    return top;
}
// 数据元素出栈
int pop(int *a, int top)
{
    if (top == -1)
    {
        printf("空栈");
        return -1;
    }
    printf("出栈元素：%d\n", a[top]);
    top--;
    return top;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a[10];
    int top = -1;
    top = push(a, top, 1);
    top = push(a, top, 2);
    top = push(a, top, 3);
    top = push(a, top, 4);
    printf("top = %d \n" ,top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    return 0;
}