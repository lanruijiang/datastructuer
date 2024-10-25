#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
    struct person *next;
    char personName[];
} Person;

int main()
{
    Person *person = (Person *)malloc(sizeof(Person));
    Person *p = NULL;
    person->next = NULL;
    strcpy(person->personName, "头指针");
    p = person;

    for (int i = 1; i <= 5; i++)
    {
        char c[] = "china";
        Person *a = (Person *)malloc(sizeof(Person));
        strcpy(a->personName, c);

        person->next = a;
        person = person->next;
    }

    Person *ph = p;
    int num = 0;
    while (ph)
    {
        num++;
        Person *ps = ph;
        printf("%s ==> %d\n", ph->personName, num);
        ph = ph->next;
        // free(ps);
    }

    printf("---------------- \n");
    Person *ph1 = p;
    int num1 = 0;
    while (ph1)
    {
        num1++;
        Person *ps = ph1;
        printf("%s ==> %d\n", ph1->personName, num1);
        ph1 = ph1->next;
        // free(ps);
    }
    return 1;
}