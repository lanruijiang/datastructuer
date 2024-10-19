#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 14
int main()
{

    char *p = NULL;
    p = (char *)malloc(MAXSIZE * sizeof(char));
    *p = p[0];
    for (int i = 0; i < MAXSIZE; i++)
    {
        *p++ = i + 1;
    }

    char c ;
    for (int i = 0; i < MAXSIZE; i++)
    {
         c = *--p;
        printf("this point value is %d == %p \n ", c, &c);
    }
}