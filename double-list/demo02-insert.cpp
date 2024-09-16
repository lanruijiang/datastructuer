#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct line {
    struct line* prior; //指向直接前趋
    int data;
    struct line* next; //指向直接后继
}Line;

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
    return head;
}
//输出链表中的数据
void display(Line* head) {
    Line* temp = head;
    while (temp) {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        }
        else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
}
//释放链表中结点占用的空间
void free_line(Line* head) {
    Line* temp = head;
    while (temp) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

Line* insertLine(Line* head, int data, int add) {
    //新建数据域为data的结点
    Line* temp = (Line*)malloc(sizeof(Line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    //插入到链表头，要特殊考虑
    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    }
    else {
        int i;
        Line* body = head;
        //找到要插入位置的前一个结点
        for (i = 1; i < add - 1; i++) {
            body = body->next;
            //只要 body 不存在，表明插入位置输入错误
            if (!body) {
                printf("插入位置有误！\n");
                return head;
            }
        }
        //判断条件为真，说明插入位置为链表尾，实现第 2 种情况
        if (body && (body->next == NULL)) {
            body->next = temp;
            temp->prior = body;
        }
        else {
            //第 2 种情况的具体实现
            body->next->prior = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;
        }
    }
    return head;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //创建一个头指针
    Line* head = NULL;
    //调用链表创建函数
    head = initLine(head);
    insertLine(head , 1000 , 3);
    //输出创建好的链表
    display(head);
    //显示双链表的优点
    printf("链表中第 4 个节点的直接前驱是：%d", head->next->next->next->prior->data);
    free_line(head);
    return 0;
}