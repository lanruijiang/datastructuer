#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char personName[];
} Person;

int main()
{
    Person *person = (Person *)malloc(3 * sizeof(Person));
    strcpy(person->personName , "china");
    printf("%s" ,person->personName);
    return 1;
}