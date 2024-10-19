#include<stdio.h>
#define MAX_LEN 30
typedef char myString[MAX_LEN];

int main() {
    // 定义一个静态数组
    myString str = "http://www.google.com";
    printf("%s", str);
    return 0;
}