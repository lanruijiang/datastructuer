#include <stdio.h>
#include <stdlib.h>

int factorial(int i){
    int result = 1;
    if(i == 0 || i == 1){
        result = i;
    }else{
        result = i * factorial(i - 1);
    }

    return result;
}

int main(){
    printf("请输入阶乘的基数 ：");
    int num ;
    scanf("%d" , &num);
    int result = factorial(num);
    printf("%d 的阶乘是 : %d ." , num , result);
}