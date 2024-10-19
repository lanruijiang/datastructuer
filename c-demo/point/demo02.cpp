#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int personName;
} Person;

int main()
{
    Person *person = (Person *)malloc(3 * sizeof(Person));
    person->personName = 1;

    int i = person->personName;
    printf("%d" , i);
}