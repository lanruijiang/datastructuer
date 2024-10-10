#include <stdio.h>
#include <windows.h>
#define MAX_LEN 5 // 表示顺序表申请的空间大小
int enQueue(int *a, int top, int rear, int data)
{
    // 添加判断语句， 如果rear超过max， 则直接将其从a[0]重新开始存储， 如果rear+1和top重合， 则表示顺序表已满
    if ((rear + 1) % MAX_LEN == top)
    {
        printf("空间已满\n");
        return rear;
    }
    // 将新元素入队
    a[rear % MAX_LEN] = data;
    printf("元素%d 成功入队\n", data);
    // rear记录下一个空闲空间的位置
    rear = (rear + 1) % MAX_LEN;
    return rear;
}
int deQueue(int *a, int top, int rear)
{
    // 如果top==rear， 表示队列为空
    if (top == rear)
    {
        printf("队列为空\n");
        return top;
    }
    printf("元素 %d 成功出队\n", a[top]);
    // top向后移动一个位置， 记录新的队头
    top = (top + 1) % MAX_LEN;
    return top;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // 定义长度为 5 的顺序表
    int a[MAX_LEN] = {0};
    // 当队列中没有元素时， 队头和队尾指向同一位置
    int top = 0, rear = 0;
    // 元素 1 成功入队
    rear = enQueue(a, top, rear, 1);
    // 元素 2 成功入队
    rear = enQueue(a, top, rear, 2);
    // 元素 3 成功入队
    rear = enQueue(a, top, rear, 3);
    // 元素 4 成功入队
    rear = enQueue(a, top, rear, 4);
    // 元素 5 入队会失败
    rear = enQueue(a, top, rear, 5);

    // 元素 1 成功出队
    top = deQueue(a, top, rear);
    // 元素 5 再入队， 会成功
    rear = enQueue(a, top, rear, 5);
    // 元素 2 成功出队
    top = deQueue(a, top, rear);
    // 元素 3 成功出队
    top = deQueue(a, top, rear);
    // 元素 4 成功出队
    top = deQueue(a, top, rear);
    // 元素 5 成功出队
    top = deQueue(a, top, rear);
    // 队列为空时， 出队操作失败
    top = deQueue(a, top, rear);
    return 0;
}