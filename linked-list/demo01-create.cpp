#include <stdio.h>
#include <stdlib.h>
// 链表中节点的结构
typedef struct link
{
    int elem;
    struct link *next;
} Link;

Link *initLink(Link *p ,int num)
{
    int i;
    // 1、创建头指针
    // Link *p = NULL;
    // 2、创建头结点
    Link *temp = (Link *)malloc(sizeof(Link));
    temp->elem = 0;
    temp->next = NULL;
    // 头指针指向头结点
    p = temp;
    // 3、每创建一个结点，都令其直接前驱结点的指针指向它
    for (i = 1; i < num; i++)
    {
        // 创建一个结点
        Link *a = (Link *)malloc(sizeof(Link));
        a->elem = i;
        a->next = NULL;
        // 每次 temp 指向的结点就是 a 的直接前驱结点
        temp->next = a;
        // temp指向下一个结点（也就是a),为下次添加结点做准备
        temp = temp->next;
    }
    return p;
}
void display(Link *p)
{
    Link *temp = p; // temp指针用来遍历链表
    // 只要temp指向结点的next值不是NULL，就执行输出语句。
    while (temp)
    {
        Link *f = temp; // 准备释放链表中的结点
        printf("%d ", temp->elem);
        temp = temp->next;
        free(f);
    }
    printf("\n");
}
int main()
{
    Link *p = NULL;
    printf("初始化链表为：\n");
    // 创建链表{1,2,3,4}
    p = initLink(p ,10);
    // 输出链表中的数据
    display(p);
    return 0;
}