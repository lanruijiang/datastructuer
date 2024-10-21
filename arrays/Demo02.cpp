#include <stdio.h>
#include <stdlib.h>

int main(){
    int num[5] = {1,2,3,4,5};
    for(int i = 0 ; i < 5 ; i++){
        int v = num[i];
        printf("%d \n",v);
    }
    return 1;
}