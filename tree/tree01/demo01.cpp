#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20] = "I like China";

    for (int i = 0; i < 20; i++)
    {
        char c = name[i];
        printf("%d == %c \n", i + 1, c);
    }

    return 1;
}