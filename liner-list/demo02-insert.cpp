#include <stdio.h>
#include <stdlib.h>
#define Size 10 // 对Size进行宏定义，表示顺序表的最大容量
typedef struct
{
    int *head;
    int length;
    int size;
} Table;

void initTable(Table *t)
{
    // 构造一个空的顺序表，动态申请存储空间
    t->head = (int *)malloc(Size * sizeof(int));
    // 如果申请失败，作出提示并直接退出程序
    if (!t->head)
    {
        printf("初始化失败");
        exit(0);
    }
    // 空表的长度初始化为0
    t->length = 0;
    // 空表的初始存储空间为Size
    t->size = Size;
}

// 插入函数，其中，elem为插入的元素，add为插入到顺序表的位置
void insertTable(Table *t, int elem, int add)
{
    int i;
    // 如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），
    // 或者插入的位置本身不存在，程序作为提示并自动退出
    if (add > t->length + 1 || add < 1)
    {
        printf("插入位置有问题\n");
        return;
    }
    // 做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，
    // 如果没有，需要申请
    if (t->length == t->size)
    {
        t->head = (int *)realloc(t->head, (t->size + 1) * sizeof(int));
        if (!t->head)
        {
            printf("存储分配失败\n");
            return;
        }
        t->size += 1;
    }
    // 插入操作，需要将自插入位置之后的所有元素全部后移一位
    for (i = t->length - 1; i >= add - 1; i--)
    {
        t->head[i + 1] = t->head[i];
    }
    // 后移完成后，直接插入元素
    t->head[add - 1] = elem;
    t->length++;
}
// 输出顺序表中元素的函数
void displayTable(Table t)
{
    int i;
    for (i = 0; i < t.length; i++)
    {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}
int main()
{
    int i;
    Table t = {NULL, 5, 0};
    initTable(&t);
    insertTable(&t, 5, 1);
    insertTable(&t, 6, 2);
    insertTable(&t, 9, 3);
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    free(t.head); // 释放申请的堆内存
    return 0;
}