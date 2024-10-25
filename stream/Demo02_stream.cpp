#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN1 10
#define LEN2 20
typedef struct {
    char* ch;
    int length;
}HString;

int concat(HString* str1, HString* str2) {
    int i;
    if (LEN1 < str1->length + str2->length) {
        str1->ch = (char *)realloc(str1->ch, (str1->length + str2->length + 1) * sizeof(char));
        //如果申请失败，则返回 0，表示连接失败
        if (str1->ch == NULL) {
            return 0;
        }
    }
    //合并两个串到 str1 中
    for (i = str1->length; i < str1->length + str2->length; i++) {
        str1->ch[i] = str2->ch[i - str1->length];
       
    }
    str1->ch[str1->length + str2->length] = '\0';
    str1->length += str2->length;
    return 1;
}

int main()
{
    HString str1 = { NULL,0 }, str2 = { NULL,0 };
    //创建存储"http://"的堆分配存储结构
    str1.ch = (char *)malloc(LEN1 * sizeof(char));
    strcpy(str1.ch, "http://");
    str1.length = strlen(str1.ch);

    //创建存储"http://"的堆分配存储结构
    str2.ch = (char *)malloc(LEN2 * sizeof(char));
    strcpy(str2.ch, "www.google.com.hk");
    str2.length = strlen(str2.ch);

    //连接两个串
    if (concat(&str1, &str2)) {
        printf("连接成功，新字符串为：%s", str1.ch);
    }
    else
    {
        printf("连接失败\n");
    }
    //手动释放申请的两个堆空间
    free(str1.ch);
    free(str2.ch);
    return 0;
}