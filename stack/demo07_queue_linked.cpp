#include <stdio.h>
#include <windows.h>
// 链表中的节点结构
typedef struct qnode
{
    int data;
    struct qnode *next;
} QNode;
// 创建链式队列的函数
QNode *initQueue()
{
    // 创建一个头节点
    QNode *queue = (QNode *)malloc(sizeof(QNode));
    // 对头节点进行初始化
    queue->next = NULL;
    return queue;
}

QNode *enQueue(QNode *rear, int data)
{
    // 1、用节点包裹入队元素
    QNode *enElem = (QNode *)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    // 2、新节点与rear节点建立逻辑关系
   rear->next = enElem;
    // 3、rear指向新节点
    rear = enElem;
    // 返回新的rear，为后续新元素入队做准备
    return rear;
}

QNode *deQueue(QNode *top, QNode *rear)
{
    QNode *p = NULL;
    if (top->next == NULL)
    {
        printf("\n队列为空\n");
        return rear;
    }
    // 1、创建新指针 p 指向目标结点
    p = top->next;
    printf("%d ", p->data);
    // 2、将目标结点从链表上摘除
    top->next = p->next;
    if (rear == p)
    {
        rear = top;
    }
    // 3、释放结点 p 占用的内存
    free(p);
    return rear;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    QNode *queue = NULL, *top = NULL, *rear = NULL;
    top = rear = initQueue(); // 创建头结点
    // 向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    rear = enQueue(rear, 1);
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 4);
    // 入队完成，所有数据元素开始出队列
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    return 0;
}