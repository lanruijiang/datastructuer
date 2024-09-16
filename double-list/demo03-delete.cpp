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

//删除结点的函数，data为要删除结点的数据域的值
Line* delLine(Line* head, int data) {
    Line* temp = head;
    while (temp) {
        if (temp->data == data) {
            //删除表头结点
            if (temp->prior == NULL) {
                head = head->next;
                if (head) {
                    head->prior = NULL;
                    temp->next = NULL;
                }
                free(temp);
                return head;
            }
            //删除表中结点
            if (temp->prior && temp->next) {
                temp->next->prior = temp->prior;
                temp->prior->next = temp->next;
                free(temp);
                return head;
            }
            //删除表尾结点
            if (temp->next == NULL) {
                temp->prior->next = NULL;
                temp->prior = NULL;
                free(temp);
                return head;
            }
        }
        temp = temp->next;
    }
    printf("表中没有目标元素，删除失败\n");
    return head;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //创建一个头指针
    Line* head = NULL;
    //调用链表创建函数
    head = initLine(head);
    display(head);
    delLine(head , 2);
    //输出创建好的链表
    display(head);
    //显示双链表的优点
    // printf("链表中第 4 个节点的直接前驱是：%d", head->next->next->next->prior->data);
    free_line(head);
    return 0;
}