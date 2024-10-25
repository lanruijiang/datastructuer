#include <stdio.h>
#include <string.h>
#define STR_LEN 100
typedef char myString[STR_LEN];
//串普通模式匹配算法的实现函数，其中 B是主串，A是模式串
int mate(char* B, char* A) {
    int i = 0, j = 0;
    while (i < strlen(B) && j < strlen(A)) {
        if (B[i] == A[j]) {
            i++;
            j++;
        }
        else {
            //匹配失败时，i 向后移动一位，j 重置
            i = i - j + 1;
            j = 0;
        }
    }
    //跳出循环有两种可能，i=strlen(B)说明已经遍历完主串，匹配失败；j=strlen(A),说明模式串遍历完成，在主串中成功匹配
    if (j == strlen(A)) {
        return i - strlen(A) + 1;
    }
    //运行到此，为 i==strlen(B) 的情况，模式匹配失败
    return -1;
}
int main() {
    myString B = "ababcabcacbab";
    myString A = "abcac";
    int res = mate(B, A);
    if (res == -1) {
        printf("模式匹配失败，主串中不含模式串\n");
    }
    else
    {
        printf("匹配成功，主串中定义到模式串的位置为：%d", res);
    }
    return 0;
}