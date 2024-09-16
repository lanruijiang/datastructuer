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

//更新函数，其中，add 表示要修改的元素，newElem 为新数据的值
void updateElem(Line* p, int oldElem, int newElem) {
    Line* temp = p;
    int find = 0;
    //找到要修改的目标结点
    while (temp)
    {
        if (temp->data == oldElem) {
            find = 1;
            break;
        }
        temp = temp->next;
    }
    //成功找到，则进行更改操作
    if (find == 1) {
        temp->data = newElem;
        return;
    }
    //查找失败，输出提示信息
    printf("链表中未找到目标元素，更改失败\n");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //创建一个头指针
    Line* head = NULL;
    //调用链表创建函数
    head = initLine(head);
    //输出创建好的链表
    display(head);

    updateElem(head , 4 , 888);
        display(head);
    //显示双链表的优点
    free_line(head);
    return 0;
}