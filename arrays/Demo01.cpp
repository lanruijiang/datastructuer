#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 5;
    char *letter ;
    letter = (char *) malloc (num * sizeof(char));

    for(int i = 0 ; i < num ; i++){
        letter[i] = char(i + 80);
    }
    
    for(int i = 0 ; i < num ; i++){
        char c = letter[i];
        printf("%c \n" , c);
    }




    return 1;
}