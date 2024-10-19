#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void show(){
    char str[100];
   int i;
 
   printf( "Enter a value :");
   scanf("%s %d", str, &i);
 
   printf( "\nYou entered: %s %d ", str, i);
   printf("\n");
}

int main(){
    show();
    return 1;
}