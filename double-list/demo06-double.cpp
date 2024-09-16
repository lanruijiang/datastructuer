#include <stdio.h>
#include <stdlib.h>
typedef struct line {
    struct line* prior; //指向直接前趋
    int data;
    struct line* next; //指向直接后继
}Line;
//创建双向循环链表
Line* initLine(Line* head) {
    int i;
    Line* list = NULL;
    head = (Line*)malloc(sizeof(Line));//创建链表第一个结点（首元结点）
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    list = head;
    for (i = 2; i <= 5; i++) {
        //创建并初始化一个新结点
        Line* body = (Line*)malloc(sizeof(Line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;
        //直接前趋结点的next指针指向新结点
        list->next = body;
        //新结点指向直接前趋结点
        body->prior = list;
        list = list->next;
    }
    //通过以上代码，已经创建好双线链表，接下来将链表的首尾节点进行双向连接
    list->next = head;
    head->prior = list;
    return head;
}
//输出链表中的数据
void display(Line* head) {
    Line* temp = head;
    //由于是循环链表，所以当遍历指针temp指向的下一个节点是head时，证明此时已经循环至链表的最后一个节点
    while (temp->next != head) {
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        }
        else {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }
    //输出循环链表中最后一个节点的值
    printf("%d", temp->data);
}
//释放链表中结点占用的空间
void free_line(Line* head) {
    Line* temp = NULL;
    //切断循环
    head->prior->next = NULL;
    //从第一个结点开始，依次 free
    temp = head;
    while (temp) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

int main()
{
    //创建一个头指针
    Line* head = NULL;
    //调用链表创建函数
    head = initLine(head);
    //输出创建好的链表
    display(head);

    printf("======>> %d" , head->next->next->next->next->next->next->data);
    //手动释放链表占用的内存
    free_line(head);
    return 0;
}