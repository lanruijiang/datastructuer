#include <stdio.h>
#include <stdlib.h>
#define Size 5 //对Size进行宏定义，表示顺序表的最大容量
typedef struct{
    int* head;
    int length;
    int size;
}Table;
void initTable(Table * t) {
    //构造一个空的顺序表，动态申请存储空间
    t->head = (int*)malloc(Size * sizeof(int));
    //如果申请失败，作出提示并直接退出程序
    if (!t->head)
    {
        printf("初始化失败");
        exit(0);
    }
    //空表的长度初始化为0
    t->length = 0;
    //空表的初始存储空间为Size
    t->size = Size;
}

// 删除元素
void delTable(Table* t, int add) {
    int i;
    if (add > t->length || add < 1) {
        printf("被删除元素的位置有误\n");
        return;
    }
    //删除操作
    for (i = add; i < t->length; i++) {
        t->head[i - 1] = t->head[i];
    }
    t->length--;
}
//输出顺序表中元素的函数
void displayTable(Table t) {
    int i;
    for (i = 0; i < t.length; i++) {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}
int main() {
    int i;
    Table t = { NULL,0,0 };
    initTable(&t);
    //向顺序表中添加{1,2,3,4,5}
    for (i = 1; i <= Size; i++) {
        t.head[i - 1] = i;
        t.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    delTable(&t , 2);
    displayTable(t);
    free(t.head);//释放申请的堆内存
    return 0;
}