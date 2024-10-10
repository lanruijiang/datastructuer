#include <stdio.h>
#include <windows.h>
#define MAX_LEN 3 // 规定数组的长度
// 实现入队操作
int enQueue(int *a, int rear, int data)
{
    // 如果 rear 超出数组下标范围，队列将无法继续添加元素
    if (rear == MAX_LEN)
    {
        printf("队列已满，添加元素失败\n");
        return rear;
    }
    a[rear] = data;
    rear++;
    return rear;
}
// 实现出队操作
int deQueue(int *a, int top, int rear)
{
    // 如果 top==rear，表示队列为空
    if (top == rear)
    {
        printf("队列已空，出队执行失败\n");
        return top;
    }
    printf("出队元素：%d\n", a[top]);
    top++;
    return top;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a[MAX_LEN];
    int top, rear;
    // 设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    top = rear = 0;
    // 入队
    rear = enQueue(a, rear, 1);
    rear = enQueue(a, rear, 2);
    rear = enQueue(a, rear, 3);
    rear = enQueue(a, rear, 4);
    // 出队
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    top = deQueue(a, top, rear);
    return 0;
}